#include "hreadelf.h"

/**
 * printshstrndx - prints section header table index
 * @shstrndx64: elf information header table index
 */
void printshstrndx(Elf64_Half shstrndx64)
{
	printf("%35s%-2c%i\n", "Section header string table index",
			':', shstrndx64);
}

/**
 * printshnum - prints number of entries in the section header table
 * @shnum64: elf information
 */
void printshnum(Elf64_Half shnum64)
{
	printf("%27s%-10c%i\n", "Number of section headers", ':',
			shnum64);
}

/**
 * printshentsize - prints a sections header size
 * @shentsize64: elf information
 */
void printshentsize(Elf64_Half shentsize64)
{
	printf("%25s%-12c%i%s\n", "Size of section headers", ':',
			shentsize64, " (bytes)");
}

/**
 * printphnum - prints number of entries in program header table
 * @phnum64: elf information
 */
void printphnum(Elf64_Half phnum64)
{
	printf("%27s%-10c%i\n", "Number of program headers", ':',
			phnum64);
}
