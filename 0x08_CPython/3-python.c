#include <Python.h>
#include <stdio.h>
#include "string.h"
#define PyListCast(op) ((PyListObject *)(op))
#define PyBytesCast(op) ((PyBytesObject *)(op))
#define PyVarObjectCast(op) ((PyVarObject *)(op))


/**
 * print_python_bytes - prints info about python bytes object
 * @p: Python generic object
 */
void print_python_bytes(PyObject *p)
{
	Py_ssize_t size, i;
	char *str;

	printf("[.] bytes object info\n");
	if (!p || !PyBytes_CheckExact(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		fflush(stdout);
		return;
	}
	size = PyBytes_Size(p);
	str  = PyBytesCast(p)->ob_sval;
	printf("  size: %ld\n", size);
	printf("  trying string: %s\n", str);
	size = size + 1 > 10 ? 10 : size + 1;
	printf("  first %ld bytes:", size);
	for (i = 0; i < size; ++i)
		printf(" %02hhx", str[i]);
	putchar('\n');
	fflush(stdout);
}

/**
 * print_python_float - prints info about python float object
 * @p: Python generic object
 */
void print_python_float(PyObject *p)
{
	char *s1, *s2;
	double d;

	printf("[.] float object info\n");
	if (!p || !PyFloat_CheckExact(p))
	{
		printf("  [ERROR] Invalid Float Object\n");
		fflush(stdout);
		return;
	}
	d = ((PyFloatObject *)(p))->ob_fval;
	s1 = PyOS_double_to_string(d, 'r', 0, Py_DTSF_ADD_DOT_0, NULL);
	s2 = strchr(s1, '.');
	if (strlen(s2) >= 16)
	{
		if (s2[16] != 'e')
			s2[16] = '\0';
		printf("  value: %s%s\n", s1, (*(s2 + 17) == 'e') ? s2 + 17 : "");
	}
	else
	{
		printf("  value: %s\n", s1);
	}
	fflush(stdout);
}

/**
 * print_python_list - prints info about python list object
 * @p: Python generic object
 */
void print_python_list(PyObject *p)
{
	Py_ssize_t i, size;
	PyObject *item;
	PyListObject *list;

	printf("[*] Python list info\n");
	if (!p || !PyList_CheckExact(p))
	{
		printf("  [ERROR] Invalid list Object\n");
		fflush(stdout);
		return;
	}
	size = PyVarObjectCast(p)->ob_size;
	list = PyListCast(p);
	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", list->allocated);
	for (i = 0; i < size; i++)
	{
		item = PyList_GET_ITEM(p, i);
		printf("Element %ld: %s\n", i, (list->ob_item[i])->ob_type->tp_name);
		if (PyBytes_Check(item))
			print_python_bytes(item);
		else if (PyFloat_Check(item))
			print_python_float(item);
	}
	fflush(stdout);
}

