#include "hreadelf.h"

/**
 * printhdrsize - prints file header sizes of ELF and an entry in program
 * @elf64: elf information
 */
void printhdrsize(Elf64_Ehdr elf64)
{
	Elf64_Half ehsize64 = elf64.e_ehsize;
	Elf64_Half phentsize64 = elf64.e_phentsize;

	printf("%21s%-16c%i%s\n", "Size of this header", ':', ehsize64,
			" (bytes)");
	printf("%25s%-12c%i%s\n", "Size of program headers", ':',
			phentsize64, " (bytes)");
}

/**
 * printflags - prints processor-specific flags associated with the file
 * @flags64: elf information
 */
void printflags(Elf64_Word flags64)
{
	printf("%7s%-30c0x%x\n", "Flags", ':', flags64);
}

/**
 * printpshoff - prints program and section header table file offset
 * @elf64: elf information
 */
void printpshoff(Elf64_Ehdr elf64)
{
	Elf64_Off phoff64 = elf64.e_phoff;
	Elf64_Off shoff64 = elf64.e_shoff;

	printf("%26s%-11c%li%s\n", "Start of program headers", ':',
			phoff64, " (bytes into file)");
	printf("%26s%-11c%li%s\n", "Start of section headers", ':',
			shoff64, " (bytes into file)");
}

/**
 * printentry - prints virtual address where the system first transfers control
 * @entry64: elf information
 */
void printentry(Elf64_Addr entry64)
{
	printf("%21s%-16c0x%lx\n", "Entry point address", ':', entry64);
}

/**
 * printfileversion - prints file version
 * @version: elf information version
 */
void printfileversion(Elf64_Word version)
{
	printf("%9s%-28c%#x\n", "Version", ':',
	version == EV_NONE ? EV_NONE : EV_CURRENT);
}

