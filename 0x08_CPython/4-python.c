#include <Python.h>

/**
 * print_python_string - prints info about python string object
 * @p: python generic object
 */
void print_python_string(PyObject *p)
{
	char *type = "Non Canonical repr";

	printf("[.] string object info\n");

	if (!p || !PyUnicode_Check(p))
	{
		printf("  [ERROR] Invalid String Object\n");
		return;
	}
	if (!PyUnicode_READY(p))
	{
		if (PyUnicode_IS_COMPACT_ASCII(p))
			type = "compact ascii";
		else if (PyUnicode_IS_COMPACT(p))
			type = "compact unicode object";
		else if (PyUnicode_KIND(p) == PyUnicode_WCHAR_KIND)
			type = "legacy string, not ready";
		else if (!PyUnicode_IS_COMPACT(p) &&
				 PyUnicode_KIND(p) != PyUnicode_WCHAR_KIND)
			type = "legacy string, ready";
	}
	printf("  type: %s\n", type);
	printf("  length: %ld\n", PyUnicode_GetLength(p));
	printf("  value: %ls\n", PyUnicode_AsWideCharString(p, NULL));
}

