#include <Python.h>
#define abs(x) (((x) < 0) ? -(x) : (x))

/**
 * long_to_string - print python long object using radix conversion
 * Modified code from Cpython
 * @aa: long object
 */

void long_to_string(PyObject *aa)
{
	PyLongObject *scratch, *a;
	Py_ssize_t size, size_a, i, j;
	digit *pout, *pin, hi;
	int negative, d;
	twodigits z;

	a = (PyLongObject *)aa, size_a = abs(Py_SIZE(a));
	negative = Py_SIZE(a) < 0;
	d = (33 * _PyLong_DECIMAL_SHIFT) /
			(10 * PyLong_SHIFT - 33 * _PyLong_DECIMAL_SHIFT);
	size = 1 + size_a + size_a / d, scratch = _PyLong_New(size);
	if (scratch == NULL)
		return;
	pin = a->ob_digit, pout = scratch->ob_digit, size = 0;
	for (i = size_a; --i >= 0; )
	{
		hi = pin[i];
		for (j = 0; j < size; j++)
		{
			z = (twodigits)pout[j] << PyLong_SHIFT | hi;
			hi = (digit)(z / _PyLong_DECIMAL_BASE);
			pout[j] = (digit)(z - (twodigits)hi * _PyLong_DECIMAL_BASE);
		}
		while (hi)
		{
			pout[size++] = hi % _PyLong_DECIMAL_BASE;
			hi /= _PyLong_DECIMAL_BASE;
		}
	}
	if (size == 0)
		pout[size++] = 0;
	if (negative)
		putchar('-');
	for (i = size; --i >= 0;)
		if (i == size - 1)
			printf("%u", pout[i]);
		else
			printf("%09u", pout[i]);
	printf("\n");
}

/**
 * print_python_int - prints info about python int object
 * @p: Python generic object
 */
void print_python_int(PyObject *p)
{
	if (!p || !PyLong_Check(p))
	{
		printf("Invalid Int Object\n");
		return;
	}
	long_to_string(p);
}
