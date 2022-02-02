#include "readelf.h"

/**
 * get_arch_mach_name - fetches the architecture of the elf file
 * @e_machine: machine
 * Return: architecture of machine
 */
char *get_arch_mach_name(unsigned int e_machine)
{
	if (e_machine == EM_386)
		return ("i386");
	else if (e_machine == EM_X86_64)
		return ("i386:x86-64");
	return ("UNKNOWN");
}

/**
 * get_file_format_name - fetches the file format of the elf file
 * @ehdr: elf header struct
 * Return: file format of elf
 */
char *get_file_format_name(ElfN_Ehdr ehdr)
{
	if (ehdr.e_machine == EM_386)
		return ("i386");
	else if (ehdr.e_machine == EM_X86_64)
		return ("x86-64");
	return (ehdr.e_ident[EI_DATA] == ELFDATA2LSB ? "little" : "big");
}

/**
 * elf_has_section_type - check if the @type of section is in sections of elf
 * @sh_tbl: section header table
 * @count: no of sections
 * @type: type to be looked in
 * Return: 1 on success otherwise 0
 */
bool elf_has_section_type(ElfN_Shdr sh_tbl[], int count, uint32_t type)
{
	int i;

	for (i = 0; i < count; i++)
	{
		if (sh_tbl[i].sh_type == type)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * elf_has_symbols - elf symbols
 * @sh_tbl: tble
 * @count: counter
 * @fd: file descriptor
 * @str_indx: string index
 * Return: Success 1 otherwise 0
 */
bool elf_has_symbols(ElfN_Shdr sh_tbl[], int count, int fd, uint32_t str_indx)
{
	int i;
	char *str_tbl = read_section(fd, sh_tbl[str_indx]);

	for (i = 0; i < count; i++)
	{
		if (sh_tbl[i].sh_type == SHT_SYMTAB &&
			!strcmp(str_tbl + sh_tbl[i].sh_name, ".symtab"))
			return (1);
		if (sh_tbl[i].sh_type == SHT_DYNSYM &&
			!strcmp(str_tbl + sh_tbl[i].sh_name, ".dynsym"))
			return (1);
	}
	return (0);
}

/**
 * get_flags - fetches the flags appropiately based on elf file
 * @ehdr: elf header struct
 * @sh_tbl: sections structure
 * @fd: input file's file descriptor
 * Return: flags
 */

int get_flags(ElfN_Ehdr *ehdr, ElfN_Shdr sh_tbl[], int fd)
{
	int flags = BFD_NO_FLAGS;

	if (ehdr->e_type == ET_EXEC)
		flags |= EXEC_P;
	if (ehdr->e_type != ET_EXEC && ehdr->e_type != ET_DYN &&
		elf_has_section_type(sh_tbl, ehdr->e_shnum, SHT_REL))
		flags |= HAS_RELOC;
	if (!(flags & EXEC_P) && ehdr->e_type != ET_DYN &&
		elf_has_section_type(sh_tbl, ehdr->e_shnum, SHT_RELA))
		flags |= HAS_RELOC;
	if (ehdr->e_type != ET_EXEC &&
		elf_has_section_type(sh_tbl, ehdr->e_shnum, SHT_DYNSYM))
		flags |= DYNAMIC;
	if (elf_has_symbols(sh_tbl, ehdr->e_shnum, fd, ehdr->e_shstrndx))
		flags |= HAS_SYMS;
	if (elf_has_section_type(sh_tbl, ehdr->e_shnum, SHT_HASH) ||
		elf_has_section_type(sh_tbl, ehdr->e_shnum, SHT_GNU_HASH))
		flags |= D_PAGED;
	return (flags);
}

