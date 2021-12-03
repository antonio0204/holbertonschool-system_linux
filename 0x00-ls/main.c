#include "header.h"

/**
 * main - Entry point
 * @argc: Application parameters length
 * @argv: Application parameters
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	return (execute(argc, argv));
}

/**
 * execute - Execute's opendir
 * @argc: Application parameters length
 * @argv: Application parameters
 * Return: Always 0
 */
int execute(int argc, char **argv)
{
	LS_Struct_t ls_struct;

	ls_struct = initialize_ls(ls_struct);
	ls_struct.options = get_options_list(argc, argv, ls_struct.options);
	ls_struct = get_arguments(argc, argv, ls_struct);
	if (ls_struct.options.flag_a == 1)
	{
		if (ls_struct.files_number > 1)
			ls_struct.files = sort_directories_list_by_name(
				ls_struct.files,
				ls_struct.files_number
			);
		if (ls_struct.directories_number > 1)
			ls_struct.directories = sort_directories_list_by_name(
				ls_struct.directories,
				ls_struct.directories_number
			);
	}

	print_errors_access(ls_struct);
	print_files(ls_struct);
	print_directories(ls_struct);
	print_errors_open(ls_struct);
	free_struct(ls_struct);
	return (ls_struct.error_value);
}

/**
 * initialize_ls - Initialize the ls_struct
 * @ls_struct: ls struct
 * Return: LS_Struct_t struct
 */
LS_Struct_t initialize_ls(LS_Struct_t ls_struct)
{
	ls_struct.directories = NULL;
	ls_struct.files = NULL;
	ls_struct.error_access = NULL;
	ls_struct.error_open = NULL;
	ls_struct.directories_number = 0;
	ls_struct.files_number = 0;
	ls_struct.error_access_number = 0;
	ls_struct.error_open_number = 0;
	ls_struct.options = initialize_flags(ls_struct.options);
	ls_struct.error_value = 0;
	return (ls_struct);
}

/**
 * initialize_flags - initialize the flags
 * @flags: flags struct
 * Return: Flag_t struct
 */
Flag_t initialize_flags(Flag_t flags)
{
	flags.flag_one = 0;
	flags.flag_a = 0;
	flags.flag_a_u = 0;
	flags.flag_l = 0;
	return (flags);
}
