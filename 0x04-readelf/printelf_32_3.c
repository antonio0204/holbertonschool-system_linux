#include "hreadelf.h"

/**
 * printshstrndx_32 - prints section header table index
 * @shstrndx32: elf information header table index
 */
void printshstrndx_32(Elf32_Half shstrndx32)
{
	printf("%35s%-2c%i\n", "Section header string table index",
			':', shstrndx32);
}

/**
 * printshnum_32 - prints number of entries in the section header table
 * @shnum32: elf information
 */
void printshnum_32(Elf32_Half shnum32)
{
	printf("%27s%-10c%i\n", "Number of section headers", ':',
			shnum32);
}

/**
 * printshentsize_32 - prints a sections header size
 * @shentsize32: elf information
 */
void printshentsize_32(Elf32_Half shentsize32)
{
	printf("%25s%-12c%i%s\n", "Size of section headers", ':',
			shentsize32, " (bytes)");
}

/**
 * printphnum_32 - prints number of entries in program header table
 * @phnum32: elf information
 */
void printphnum_32(Elf32_Half phnum32)
{
	printf("%27s%-10c%i\n", "Number of program headers", ':',
			phnum32);
}

