#include "readelf.h"

/**
 * determine_st_flag_roftb - gets the flag based on symbol type
 * @symtab: section header table
 * @strtab: symbol table
 * @sh_tbl: string table
 * Return: flag
 */
char determine_st_flag_roftb(ElfN_Sym symtab, char *strtab, ElfN_Shdr sh_tbl[])
{
	if (ELF_ST_BIND(symtab.st_info) == STB_WEAK)
	{
		if (!symtab.st_value)
			return (ELF_ST_TYPE(symtab.st_info) ==
			STT_OBJECT ? 'v' : 'w');
		return (ELF_ST_TYPE(symtab.st_info) == STT_OBJECT ? 'V' : 'W');
	} else if (symtab.st_shndx == SHN_COMMON)
		return ('C');
	else if (symtab.st_shndx == SHN_UNDEF)
		return ('U');
	else if (is_symbol_from_section(symtab, strtab, sh_tbl, ".debug"))
		return ('N');
	return (0);
}

/**
 * is_symbol_from_section - check if the symbol is from @s section
 * @sh_tbl: section header table
 * @symtab: symbol table
 * @strtab: string table
 * @s: name of the section
 * Return: 1 on Success else 0
 */
int is_symbol_from_section(ElfN_Sym symtab, char *strtab, ElfN_Shdr sh_tbl[],
							const char *s)
{
	if (!strcmp(s, ".rel"))
	{
		printf("%s\n", strtab + sh_tbl[symtab.st_shndx].sh_name);
		return (!strncmp(s, strtab + sh_tbl[symtab.st_shndx].sh_name, 4));
	}
	return (!strcmp(strtab + sh_tbl[symtab.st_shndx].sh_name, s));
}

