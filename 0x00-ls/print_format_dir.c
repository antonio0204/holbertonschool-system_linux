#include "header.h"

/**
 * opendir_current_in_argv - Opens an user input directory
 * @dir_name: Name of the directory
 * @ls_struct: Struct that contains all the parameters
 * @iterator: Current position in dir array
 * Return: 0 on success, 2 otherwise
 */
int get_files_in_dir(
	char *dir_name,
	LS_Struct_t ls_struct,
	size_t iterator)
{
	DIR *dir;
	size_t list_index = 0;
	char **dir_list = NULL;
	int execution_return = 0;

	dir = opendir(dir_name);

	if (dir)
	{
		print_dirname_at_start(dir_name, ls_struct);
		dir_list = readdir_get_directories(dir, &list_index);
		sort_directories_list_by_name(dir_list, list_index);
		print_directories_with_parameters(
			dir_list,
			dir_name,
			list_index,
			ls_struct,
			iterator);
		free(dir_list);
		closedir(dir);
		return (0);
	}
	closedir(dir);
	return (execution_return);
}

/**
 * print_dirname_at_start - Prints the dirname
 * @dir_name: The directory name
 * @ls_struct: Struct that contains all the parameters
 * Return:
 */
void print_dirname_at_start(char *dir_name, LS_Struct_t ls_struct)
{
	if (ls_struct.directories_number > 1
	|| ls_struct.files_number > 0
	|| ls_struct.error_access_number > 0
	|| ls_struct.error_open_number > 0)
		printf("%s:\n", dir_name);
}

/**
 * print_directories_with_parameters - Prints the files in a directory
 * with the parameters
 * @dir_list: Files/directories inside the current directory
 * @dir_name: Current directory name
 * @list_index: Size of the @dir_list
 * @ls_struct: Struct that contains all the parameters
 * @dir_iterator: Current position in dir array
 * Return:
 */
void print_directories_with_parameters(
	char **dir_list, char *dir_name,
	size_t list_index,
	LS_Struct_t ls_struct,
	size_t dir_iterator)
{
	size_t iterator, jump = 0;

	if (ls_struct.options.flag_l == 1 || ls_struct.options.flag_one == 1)
		jump = 1;

	for (iterator = 0; iterator < list_index; iterator++)
	{
		if (ls_struct.options.flag_l == 1)
			flag_l(dir_name, dir_list, iterator, ls_struct);
		if (ls_struct.options.flag_a == 1)
			flag_a(dir_list, iterator, jump);
		else if (ls_struct.options.flag_a_u == 1)
			flag_A(dir_list, iterator, jump);
		else
		{
			if (dir_list[iterator][0] != '.')
			{
				if (jump == 1)
					printf("%s\n", dir_list[iterator]);
				else
					printf("%s  ", dir_list[iterator]);
			}
		}
		free(dir_list[iterator]);
	}
	if (jump == 0)
		printf("\n");
	if ((dir_iterator < ls_struct.directories_number - 1))
		printf("\n");
}

/**
 * readdir_get_directories - Gets the directories list
 * @dir: The current oppened directory
 * @list_index: Size of directories_list
 * Return: List of directories
 */
char **readdir_get_directories(DIR *dir, size_t *list_index)
{
	struct dirent *read;
	char **dir_list = NULL;

	while ((read = readdir(dir)) != NULL)
	{
		dir_list = _realloc(dir_list,
		(*list_index) * sizeof(char *),
		(*list_index + 1) * sizeof(char *));
		dir_list[*list_index] = _strdup(read->d_name);
		*list_index = *list_index + 1;
	}
	return (dir_list);
}
