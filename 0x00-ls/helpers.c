#include "header.h"

/**
 * _strlen - Return the len of a string
 * Description: This function shows the length of a given string
 * @s: Pointer that contains the string
 * Return: @s len
 */
int _strlen(const char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

/**
 * _realloc - Reallocates a memory block
 * Description: This function reallocates a memmory block
 * using malloc and free
 * @ptr: The pointer allocated
 * @old_size: Size in bytes of allocated space for @ptr
 * @new_size: New size in bytes for @ptr
 * Return: A pointer to the created array
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *a;

	if (ptr == NULL)
	{
		a = malloc(new_size);
		if (a == NULL)
			return (NULL);
		return (a);
	}
	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	a = malloc(new_size);
	if (a == NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
		_memcpy(a, ptr, old_size);
	else
		_memcpy(a, ptr, new_size);
	free(ptr);
	return (a);
}

/**
 * _memcpy - Copies memory area
 * Description: This function copies @n bytes from memory
 * area @src to memory area @dest
 * @dest: Pointer that store new memory area values
 * @src: Pointer taht cointas memory area values
 * @n: Bytes of memory area to copy
 * Return: The @dest with @src memory area values
 */
void _memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*(dest + i) = *(src + i);
	}
}

/**
 * _strdup - Creates a copy of a given string
 * Description: This function returns a pointer to a newly
 * allocated space in memory, witch contains a copy of the
 * string given as parameter
 * @str: String that we gonna copy
 * Return: A pointer to the new string, NULL if @str is NULL
 * or insufficient memory was available
 */
char *_strdup(char *str)
{
	char *p;
	int i;
	int size = 0;

	if (str == NULL)
	{
		return (NULL);
	}

	while (*(str + size) != '\0')
	{
		size++;
	}
	p = malloc(sizeof(char) * size + 1);

	if (p == NULL)
	{
		return (NULL);
	}
	for (i = 0; i <= size; i++)
	{
		*(p + i) = *(str + i);
	}

	return (p);
}

/**
 * _strcat - Return concatenated string
 * Description: This function concatenate two strings
 * @dest: String where gonna concatenate
 * @src: String to concatenate with @dest
 * Return: @dest + @src
 */
char *_strcat(char *dest, char *src)
{
	int counter = 0;

	while (*(dest + counter) != '\0')
	{
		counter++;
	}
	while (*src != '\0')
	{
		*(dest + counter) = *src++;
		counter++;
	}
	return (dest);
}
