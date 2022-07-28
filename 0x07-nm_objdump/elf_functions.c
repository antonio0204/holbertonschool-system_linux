#include "readelf.h"

/**
 * elf_check_file - checks if the elf file is valid
 * @magic: magic string
 * Return: on success: true, on Failure: false.
 */
bool elf_check_file(unsigned char *magic)
{
	if (magic[0] != ELFMAG0 || magic[1] != ELFMAG1
		|| magic[2] != ELFMAG2 || magic[3] != ELFMAG3)
		return (false);
	return (true);
}
/**
 * get_architecture - fetches the architecture of the elf file
 * @c: char
 * @arch: architecture - 32 / 64
 * Return: on success: true, on Failure: false.
 */
bool get_architecture(char c, int *arch)
{
	if (c == ELFCLASS32)
		*arch = 32;
	else if (c == ELFCLASS64)
		*arch = 64;
	else
		return (false);
	return (true);
}

bool display_section(uint32_t type, ElfN_Ehdr ehdr, ElfN_Shdr shdr,
					char *str_tbl)
{
	if (type == SHT_NULL || type == SHT_NOBITS || type == SHT_SYMTAB)
		return (false);
	if (type == SHT_STRTAB && !(shdr.sh_flags & SHF_ALLOC))
		return (false);
	if ((ehdr.e_type == ET_EXEC || ehdr.e_type == ET_DYN) &&
		(type == SHT_REL || type == SHT_RELA))
		return (true);
	if (ehdr.e_type != ET_EXEC && (type == SHT_REL || type == SHT_RELA))
		return (false);
	if (ehdr.e_type == ET_EXEC
		&& (!strcmp(str_tbl + shdr.sh_name, ".text")
			|| !strcmp(str_tbl + shdr.sh_name, ".data")))
		return (true);
	if (ehdr.e_type == ET_DYN
		&& (!strcmp(str_tbl + shdr.sh_name, ".text")
			|| !strcmp(str_tbl + shdr.sh_name, ".data")))
		return (true);
	if (ehdr.e_machine == EM_X86_64
		&& (!strcmp(str_tbl + shdr.sh_name, ".text")
			|| !strcmp(str_tbl + shdr.sh_name, ".data")))
		return (false);
	if (!strcmp(str_tbl + shdr.sh_name, ".tm_clone_table"))
		return (false);
	if (!strcmp(str_tbl + shdr.sh_name, ".note.GNU-stack"))
		return (false);
	if (!strlen(str_tbl + shdr.sh_name))
		return (false);
	return (true);
}

