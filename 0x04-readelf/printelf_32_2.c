#include "hreadelf.h"

/**
 * printhdrsize_32 - prints file header sizes of ELF and an entry in program
 * @elf32: elf information
 */
void printhdrsize_32(Elf32_Ehdr elf32)
{
	Elf32_Half ehsize32 = elf32.e_ehsize;
	Elf32_Half phentsize32 = elf32.e_phentsize;

	printf("%21s%-16c%i%s\n", "Size of this header", ':', ehsize32,
			" (bytes)");
	printf("%25s%-12c%i%s\n", "Size of program headers", ':',
			phentsize32, " (bytes)");
}

/**
 * printflags_32 - prints processor-specific flags associated with the file
 * @flags32: elf information
 */
void printflags_32(Elf32_Word flags32)
{
	printf("%7s%-30c0x%x\n", "Flags", ':', flags32);
}

/**
 * printpshoff_32 - prints program and section header table file offset
 * @elf32: elf information
 */
void printpshoff_32(Elf32_Ehdr elf32)
{
	Elf32_Off phoff32 = elf32.e_phoff;
	Elf32_Off shoff32 = elf32.e_shoff;

	printf("%26s%-11c%i%s\n", "Start of program headers", ':',
			phoff32, " (bytes into file)");
	printf("%26s%-11c%i%s\n", "Start of section headers", ':',
			shoff32, " (bytes into file)");
}

/**
 * printentry_32 - prints virtual address where
 * the system first transfers control
 * @entry32: elf information
 */
void printentry_32(Elf32_Addr entry32)
{
	printf("%21s%-16c0x%x\n", "Entry point address", ':', entry32);
}

/**
 * printfileversion_32 - prints file version
 * @version: elf information version
 */
void printfileversion_32(Elf32_Word version)
{
	printf("%9s%-28c%#x\n", "Version", ':',
	version == EV_NONE ? EV_NONE : EV_CURRENT);
}

