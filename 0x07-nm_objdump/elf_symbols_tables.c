#include "readelf.h"

/**
 * read_elf_stN - fills the ehdr with suitable(N) architecture
 * data
 * @ehdr: elf header structure
 * @file: input file
 * @arch: architecture the elf file
 * Return: 1 - if no symbols else 0
 */
int read_elf_stN(ElfN_Ehdr *ehdr, FILE *file, int arch)
{
	ElfN_Shdr *sh_tbl;
	ElfN_Sym *sym_tbl;
	int i;
	uint64_t count = 0;

	if (arch == 64)
		read_elf_header_64(ehdr, file);
	else if (arch == 32)
		read_elf_header_32(ehdr, file);
	sh_tbl = malloc(sizeof(ElfN_Shdr) * ehdr->e_shnum);

	if (!sh_tbl)
		printf("Failed to allocate section header table\n");
	if (arch == 64)
		read_elf_sh_64(*ehdr, sh_tbl, fileno(file));
	else if (arch == 32)
		read_elf_sh_32(*ehdr, sh_tbl, fileno(file));
	for (i = 0; i < ehdr->e_shnum; i++)
	{
		if (sh_tbl[i].sh_type == SHT_SYMTAB)
		{
			if (arch == 64)
			{
				count = sh_tbl[i].sh_size / sizeof(Elf64_Sym);
				sym_tbl = malloc(sizeof(ElfN_Sym) * count);
				read_elf_st_64(*ehdr, sh_tbl[i], sym_tbl, fileno(file));
			} else if (arch == 32)
			{
				count = sh_tbl[i].sh_size / sizeof(Elf32_Sym);
				sym_tbl = malloc(sizeof(ElfN_Sym) * count);
				read_elf_st_32(*ehdr, sh_tbl[i], sym_tbl, fileno(file));
			}
			print_elf_symbol_table(sh_tbl, sym_tbl, *ehdr, count, fileno(file));
		}
	}
	return (count ? 1 : 0);
}

