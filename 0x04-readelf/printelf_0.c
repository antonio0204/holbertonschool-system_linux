#include "hreadelf.h"

/**
 * printversion - prints version number of ELF specification
 * @ident: containing elf header information
 * @str: string containing name of program
 *
 * Return: 0 on success, otherwise 1
 */
int printversion(unsigned char *ident, char *str)
{
	if (ident[EI_VERSION] == EV_NONE)
	{
		fprintf(stderr, "%s: Error: Invalid ELF version\n", str);
		return (1);
	}
	printf("%9s%-28c%i (current)\n", "Version", ':', EV_CURRENT);
	return (0);
}

/**
 * printdata - prints data encoding of processor-specific data in the file
 * @ident: containing elf information
 * @str: string containing name of program
 *
 * Return: 0 on success, Error 1, is msb 2
 */
int printdata(unsigned char *ident, char *str)
{
	if (ident[EI_DATA] == ELFDATANONE)
	{
		fprintf(stderr, "Error %s\n", str);
		return (1);
	}
	if (ident[EI_DATA] == ELFDATA2LSB)
	{
		printf("%6s%-31c%s%s\n", "Data", ':', "2's complement, ",
				"little endian");
	}
	else
	{
		printf("%6s%-31c%s%s\n", "Data", ':', "2's complement, ",
				"big endian");
		return (2);
	}
	return (0);
}

/**
 * printclass - prints architecture information
 * @ident: containing elf information
 * @str: string containing name of program
 *
 * Return: 0 on success, error 1, 32 is 2
 */
int printclass(unsigned char *ident, char *str)
{
	if (ident[EI_CLASS] == ELFCLASSNONE)
	{
		fprintf(stderr, "Error %s\n", str);
		return (1);
	}
	if (ident[EI_CLASS] == ELFCLASS32)
	{
		printf("%7s%-30c%s\n", "Class", ':', "ELF32");
		return (2);
	}
	else
	{
		printf("%7s%-30c%s\n", "Class", ':', "ELF64");
	}
	return (0);
}

/**
 * _printmag - prints the magic numbers
 * @ident: containing elf information
 */
void _printmag(unsigned char *ident)
{
	size_t i;

	printf("%11s", "Magic:   ");
	for (i = 0; i < EI_NIDENT; ++i)
		printf("%02x ", ident[i]);
	putchar('\n');
}

