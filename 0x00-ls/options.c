#include "header.h"

/**
 * get_options_list - Gets an options list
 * @argc: Application parameters length
 * @argv: Application parameters
 * @flags: Flag struct
 * Return: The options list
 */
Flag_t get_options_list(int argc, char **argv, Flag_t flags)
{
	int argc_iterator;

	for (argc_iterator = 1; argc_iterator < argc; argc_iterator++)
	{
		print_ambi_option(argv[argc_iterator]);
		if (_strcmp("--all", argv[argc_iterator]) == 0)
		{
			flags.flag_a = 1;
			continue;
		}
		if (_strlen(argv[argc_iterator]) == 2)
			if (argv[argc_iterator][0] == '-' && argv[argc_iterator][1] == '-')
				continue;
		if (argv[argc_iterator][0] == '-')
			flags = get_options(argv[argc_iterator], flags);
	}
	return (flags);
}

/**
 * get_options - Gets and option
 * @option: Option to get in the user input
 * @flag_struct: Flag struct
 * Return: An option;
 */
Flag_t get_options(char *option, Flag_t flag_struct)
{
	int option_iterator;
	size_t flags_iterator;
	int option_length = 0;
	int correct_flag = 0;
	char *flags = "aArStR1l";

	option_length = _strlen(option);

	if (option[0] == '-')
	{
		if (_strlen(option) >= 3)
		{
			if (option[1] == '-')
				print_unrecognized_option(option, correct_flag);
		}
		for (option_iterator = 1; option_iterator < option_length; option_iterator++)
		{
			if (option_iterator == 1 && option[option_iterator] == '-')
				continue;
			for (flags_iterator = 0;
			flags_iterator < (size_t) _strlen(flags); flags_iterator++)
				if (flags[flags_iterator] == option[option_iterator])
				{
					correct_flag = 1;
					flag_struct = set_flags(flag_struct, flags[flags_iterator]);
				}
			print_invalid_option(option, correct_flag, option_iterator);
			correct_flag = 0;
		}
	}
	return (flag_struct);
}

/**
 * set_flags - Set the flags
 * @flags: flags struct
 * @option: Option to set in @flags
 * Return: Flag_t struct
 */
Flag_t set_flags(Flag_t flags, char option)
{
	if (option == '1')
		flags.flag_one = 1;
	if (option == 'a')
		flags.flag_a = 1;
	if (option == 'A')
		flags.flag_a_u = 1;
	if (option == 'l')
		flags.flag_l = 1;
	return (flags);
}
