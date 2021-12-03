#include "header.h"

/**
 * flag_l - ls flag -l
 * @dir_name: Directory name
 * @dir_list: Directories list
 * @iterator: Actual position in @dir_list
 * @ls_struct: Ls struct
 * Return:
 */
void flag_l(
	char *dir_name,
	char **dir_list,
	size_t iterator,
	LS_Struct_t ls_struct){
	char dir_path[256];

	if (ls_struct.options.flag_a != 1
	&& (_strcmp(".", dir_list[iterator]) == 0
	|| _strcmp("..", dir_list[iterator]) == 0))
		return;
	_memset(dir_path, '\0', 256);
	_strcat(dir_path, dir_name);
	if (dir_name[_strlen(dir_name) - 1] != '/')
	{
		_strcat(dir_path, "/");
	}
	_strcat(dir_path, dir_list[iterator]);
	print_perm(dir_path, 0);
}

void flag_a(
	char **dir_list,
	size_t iterator,
	size_t jump)
{
	if (jump == 1)
		printf("%s\n", dir_list[iterator]);
	else
		printf("%s  ", dir_list[iterator]);
}

void flag_A(
	char **dir_list,
	size_t iterator,
	size_t jump)
{
	if (_strlen(dir_list[iterator]) <= 2)
	{
		if (_strcmp(".", dir_list[iterator]) == 0
		|| _strcmp("..", dir_list[iterator]) == 0)
			return;
	}
	if (jump == 1)
		printf("%s\n", dir_list[iterator]);
	else
		printf("%s  ", dir_list[iterator]);
}
