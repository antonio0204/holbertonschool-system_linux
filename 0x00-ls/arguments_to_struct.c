#include "header.h"

/**
 * get_arguments - Gets the arguments from @argv
 * @argc: Application parameters length
 * @argv: Application parameters
 * @ls_struct: Struct that contains all the parameters
 * Return: Then list of directories
 */
LS_Struct_t get_arguments(int argc, char **argv, LS_Struct_t ls_struct)
{
	int iterator;

	for (iterator = 1; iterator < argc; iterator++)
	{
		if (
			argv[iterator][0] != '-'
			|| (argv[iterator][0] == '-' && _strlen(argv[iterator]) == 1))
			ls_struct = get_arguments_helper(argv, iterator, ls_struct);
		if (_strlen(argv[iterator]) == 2)
		{
			if (argv[iterator][0] == '-' && argv[iterator][1] == '-')
			{
				ls_struct.directories = _realloc(ls_struct.directories,
					sizeof(char *) * (ls_struct.directories_number),
					sizeof(char *) * (ls_struct.directories_number + 1));
				ls_struct.directories[ls_struct.directories_number] = _strdup(".");
				ls_struct.directories_number++;
			}
		}
	}
	if (ls_struct.directories_number == 0 && ls_struct.files_number == 0
	&& ls_struct.error_access_number == 0 && ls_struct.error_open_number == 0)
	{
		ls_struct = add_current_directory(ls_struct);
	}
	return (ls_struct);
}

/**
 * set_directories - Sets the list of directories
 * @argv: Application parameters
 * @iterator: Actual position in @argv
 * @ls_struct: Struct that contains all the parameters
 * Return: List of directories
 */
LS_Struct_t set_directories(
	char **argv,
	size_t iterator,
	LS_Struct_t ls_struct)
{
	ls_struct.directories = set_list(
		argv, ls_struct.directories,
		ls_struct.directories_number,
		iterator);
	ls_struct.directories_number++;
	return (ls_struct);
}

/**
 * set_files - Sets the list of files
 * @argv: Application parameters
 * @iterator: Actual position in @argv
 * @ls_struct: Struct that contains all the parameters
 * Return: List of directories
 */
LS_Struct_t set_files(char **argv, size_t iterator, LS_Struct_t ls_struct)
{
	ls_struct.files = set_list(
		argv, ls_struct.files,
		ls_struct.files_number,
		iterator);
		ls_struct.files_number++;
	return (ls_struct);
}

/**
 * set_errors_access - Sets the list of errors on access directories
 * @argv: Application parameters
 * @iterator: Actual position in @argv
 * @ls_struct: Struct that contains all the parameters
 * Return: List of directories
 */
LS_Struct_t set_errors_access(
	char **argv,
	size_t iterator,
	LS_Struct_t ls_struct)
{
	ls_struct.error_access = set_list(
		argv,
		ls_struct.error_access,
		ls_struct.error_access_number,
		iterator);
	ls_struct.error_access_number++;
	return (ls_struct);
}

/**
 * set_errors_open - Sets the list of errors on open directories
 * @argv: Application parameters
 * @iterator: Actual position in @argv
 * @ls_struct: Struct that contains all the parameters
 * Return: List of directories
 */
LS_Struct_t set_errors_open(
	char **argv,
	size_t iterator,
	LS_Struct_t ls_struct)
{
	ls_struct.error_open = set_list(
		argv,
		ls_struct.error_open,
		ls_struct.error_open_number,
		iterator);
	ls_struct.error_open_number++;
	return (ls_struct);
}
