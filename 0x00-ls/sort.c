#include "header.h"

/**
 * sort_directories_list_by_name - Sort list of directories by name
 * @dir_list: List of directories
 * @list_size: The size of the directories list
 * Return: A list of directories sorted by name
 */
char **sort_directories_list_by_name(char **dir_list, size_t list_size)
{
	size_t iterator, jiterator;
	char *swap_string = NULL;

	for (iterator = 0; iterator < list_size - 1; iterator++)
	{
		for (jiterator = 0; jiterator < list_size - iterator - 1; jiterator++)
		{
			if (_strcmp_ci(dir_list[jiterator], dir_list[jiterator + 1]) > 0)
			{
				swap_string = dir_list[jiterator];
				dir_list[jiterator] = dir_list[jiterator + 1];
				dir_list[jiterator + 1] = swap_string;
			}
		}
	}
	return (dir_list);
}
