#include "header.h"

/**
 * _strcmp_ci - Compare strings case insensitive
 * Description: This function compare two strings
 * @s1: First string to compare
 * @s2: Second string to compare
 * Return: @n bytes of @src
 */
int _strcmp_ci(char *s1, char *s2)
{
	int len1 = -1;
	int len2 = -1;

	if (_strcmp_aux(s1, ".") != 0 && _strcmp_aux(s1, "..") != 0)
	{
		len1 = _strlen(s1);
		while (*s1 == '.')
			s1++;
	}
	if (_strcmp_aux(s2, ".") != 0 && _strcmp_aux(s2, "..") != 0)
	{
		len2 = _strlen(s2);
		while (*s2 == '.')
			s2++;
	}
	if (_strcmp(s1, s2) == 0 && len1 != -1 && len2 != -1)
	{
		if (*s1 == '/' || *s2 == '/')
		{
			if (len1 > len2)
				return (1);
			else
				return (-1);
		}
		if (len1 > len2)
			return (-1);
		else
			return (1);
	}
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (__tolower(*s1) > __tolower(*s2))
			return (__tolower(*s1) - __tolower(*s2));
		else if (__tolower(*s2) > __tolower(*s1))
			return ((__tolower(*s2) - __tolower(*s1)) * -1);
		s1++;
		s2++;
	}
	return (0);
}

/**
 * free_struct - Frees the main struct
 * @ls_struct: Struct that contains all the parameters
 * Return:
 */
void free_struct(LS_Struct_t ls_struct)
{
	if (ls_struct.directories)
		free(ls_struct.directories);
	if (ls_struct.files)
		free(ls_struct.files);
	if (ls_struct.error_access)
		free(ls_struct.error_access);
	if (ls_struct.error_open)
		free(ls_struct.error_open);
}

/**
 * add_current_directory - Adds the current directory if none is send
 * @ls_struct: Struct that contains all the parameters
 * Return: A list of of directories
 */
LS_Struct_t add_current_directory(LS_Struct_t ls_struct)
{
	ls_struct.directories = _realloc(
		ls_struct.directories,
		sizeof(char *) * (ls_struct.directories_number),
		sizeof(char *) * (ls_struct.directories_number + 1));
	ls_struct.directories[ls_struct.directories_number] = _strdup(".");
	ls_struct.directories_number++;
	return (ls_struct);
}


/**
 * set_list - Sets the list
 * @argv: Application parameters
 * @list: List to set
 * @list_index: Current position in @list
 * @iterator: Actual position in @argv
 * Return: An array of strings
 */
char **set_list(char **argv, char **list, size_t list_index, int iterator)
{
	list = _realloc(list,
	sizeof(char *) * (list_index),
	sizeof(char *) * (list_index + 1));
	list[list_index] = _strdup(argv[iterator]);
	return (list);
}

/**
 * __tolower - Returns the lowercase
 * @c: Char to convert
 * Return: @c in lowercase
 */
char __tolower(char c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}
