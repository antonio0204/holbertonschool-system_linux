#include "header.h"

/**
 * get_arguments_helper - Helper to extend get_arguments funcionality
 * @argv: Application parameters
 * @iterator: Current position in @argv
 * @ls_struct: Struct that contains all the parameters
 * Return: @ls_struct with the paramters
 */
LS_Struct_t get_arguments_helper(
	char **argv,
	size_t iterator,
	LS_Struct_t ls_struct)
{
	DIR *dir;
	struct stat sb;

	dir = opendir(argv[iterator]);
	if (dir)
	{
		closedir(dir);
		return (set_directories(argv, iterator, ls_struct));
	}
	else if (lstat(argv[iterator], &sb) == 0 &&
	(S_ISREG(sb.st_mode) || S_ISLNK(sb.st_mode)
	|| S_ISCHR(sb.st_mode) || S_ISBLK(sb.st_mode)
	|| S_ISFIFO(sb.st_mode) || S_ISSOCK(sb.st_mode)))
	{
		closedir(dir);
		return (set_files(argv, iterator, ls_struct));
	}
	else if (lstat(argv[iterator], &sb) == 0)
		ls_struct = set_errors_open(argv, iterator, ls_struct);
	else
		ls_struct = set_errors_access(argv, iterator, ls_struct);
	ls_struct.error_value = 2;
	closedir(dir);
	return (ls_struct);
}

/**
 * _memset - Fills memory
 * Description: This function fills memory with a constant byte @b
 * @s: Pointer to change memory values
 * @b: Byte that gonna fill @s
 * @n: Fill the first @n bytes
 * Return: The @s filled
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*(s + i) = b;
	}
	return (s);
}
