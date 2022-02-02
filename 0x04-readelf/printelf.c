#include "hreadelf.h"

/**
 * printelf64h - convert all params to big endian
 * @elf64: elf 32 bytes information
 */
void printelf64h(Elf64_Ehdr elf64)
{
	printosabi(elf64.e_ident);
	printtype(elf64.e_type);
	printmachine(elf64.e_machine);
	printfileversion(elf64.e_version);
	printentry(elf64.e_entry);
	printpshoff(elf64);
	printflags(elf64.e_flags);
	printhdrsize(elf64);
	printphnum(elf64.e_phnum);
	printshentsize(elf64.e_shentsize);
	printshnum(elf64.e_shnum);
	printshstrndx(elf64.e_shstrndx);
}

/**
 * printelf32h - convert all params to big endian
 * @elf32: elf 32 bytes information
 */
void printelf32h(Elf32_Ehdr elf32)
{
	printosabi_32(elf32.e_ident);
	printtype_32(elf32.e_type);
	printmachine_32(elf32.e_machine);
	printfileversion_32(elf32.e_version);
	printentry_32(elf32.e_entry);
	printpshoff_32(elf32);
	printflags_32(elf32.e_flags);
	printhdrsize_32(elf32);
	printphnum_32(elf32.e_phnum);
	printshentsize_32(elf32.e_shentsize);
	printshnum_32(elf32.e_shnum);
	printshstrndx_32(elf32.e_shstrndx);
}

