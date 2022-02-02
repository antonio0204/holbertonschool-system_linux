#include <Python.h>
#include <stdio.h>
#define PyVarObjectCast(op) ((PyVarObject *)(op))
#define PyLongObjectCast(op) ((struct _longobject *)(op))
#define abs(x) (((x) < 0) ? -(x) : (x))

/**
 * print_python_int - prints info about python int object
 * @p: Python generic object
 */
void print_python_int(PyObject *p)
{
	Py_ssize_t size, i;
	digit *ob_digit;
	unsigned long n = 0;

	if (!p || !PyLong_Check(p))
	{
		printf("Invalid Int Object\n");
		return;
	}
	size = PyVarObjectCast(p)->ob_size;
	ob_digit = PyLongObjectCast(p)->ob_digit;

	if (abs(size) > 3 || (abs(size) == 3 && ob_digit[2] >= 16))
	{
		printf("C unsigned long int overflow\n");
		return;
	}
	for (i = 0; i < abs(size); ++i)
	{
		n += ob_digit[i] * (1L << (30 * i));
	}
	if (size < 0)
		putchar('-');
	printf("%lu\n", n);
}

