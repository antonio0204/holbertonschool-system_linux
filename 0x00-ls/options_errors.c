#include "header.h"

/**
 * print_unrecognized_option - Prints if an option is unrecognized
 * @option: Current option
 * @correct_flag: 1 on success, 0 otherwise
 * Return:
 */
void print_unrecognized_option(char *option, int correct_flag)
{
	if (correct_flag == 0)
	{
		fprintf(stderr,
		"hls: unrecognized option '%s'\nTry 'hls --help' for more information.\n",
		option);
		exit(2);
	}
}

/**
 * print_invalid_option - Prints if an option is invalid
 * @option: Current option
 * @correct_flag: 1 on success, 0 otherwise
 * @option_iterator: Current position on @option string
 * Return:
 */
void print_invalid_option(char *option, int correct_flag, int option_iterator)
{
	if (correct_flag == 0)
	{
		fprintf(stderr,
		"hls: invalid option -- '%c'\nTry 'hls --help' for more information.\n",
		option[option_iterator]);
		exit(2);
	}
}

/**
 * print_ambi_option - Prints if an option is invalid
 * @option: Current option
 * Return:
 */
void print_ambi_option(char *option)
{
	if (_strcmp("--a", option) == 0)
	{
		fprintf(stderr,
		"hls: option '%s' is ambiguous; possibilities: '--all' '--almost-all' '--author'\n",
		option);
		fprintf(stderr, "Try 'hls --help' for more information.\n");
		exit(2);
	}
}
