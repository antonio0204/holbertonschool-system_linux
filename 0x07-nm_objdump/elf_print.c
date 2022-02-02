#include "readelf.h"

/**
 * isprintable - checks if the symbol is printable
 * @strtab: string table
 * @st: Symbol table
 * Return: On success - 1, On Failure 0
 */
int isprintable(char *strtab, ElfN_Sym st)
{
	return (strtab[st.st_name] && ELF_ST_TYPE(st.st_info) != STT_FILE);
}

/**
 * print_elf_symbol_table - displays the elf header section as
 * "read elf -W -s"
 * @sh_tbl: section header table
 * @ehdr: Elf header
 * @sym_tbl: Symbol table
 * @count: no of symbols
 * @fd: file descriptor of input elf file
 * @ehdr: elf header structure
 */
void print_elf_symbol_table(ElfN_Shdr sh_tbl[], ElfN_Sym sym_tbl[],
ElfN_Ehdr ehdr, uint64_t count, int fd)
{
	uint64_t i = 0;
	char *str_tbl;
	char *symbol_str_tbl;
	bool arch32 = ehdr.e_ident[EI_CLASS] == ELFCLASS32;

	str_tbl = read_section(fd, sh_tbl[ehdr.e_shstrndx]);
	for (i = 0; i < ehdr.e_shnum; i++)
		if (strcmp(str_tbl + sh_tbl[i].sh_name, ".strtab") == 0)
			symbol_str_tbl = read_section(fd, sh_tbl[i]);
	for (i = 0; i < count; i++)
	{
		if (isprintable(symbol_str_tbl, sym_tbl[i]))
		{
			if (get_st_flag(sh_tbl, sym_tbl[i], str_tbl) != 'U' &&
				get_st_flag(sh_tbl, sym_tbl[i], str_tbl) != 'w')
			printf("%0*x", arch32 ? 8 : 16,
			(unsigned int)sym_tbl[i].st_value);
			else
				printf("%*s", arch32 ? 8 : 16, "");
			printf(" %c ", get_st_flag(sh_tbl, sym_tbl[i], str_tbl));
			printf("%s", symbol_str_tbl + sym_tbl[i].st_name);
			printf("\n");
		}
	}
}

void print_elf_section_header(ElfN_Shdr sh_tbl[],
	ElfN_Ehdr ehdr, int fd)
{
	int i = 0;
	char *str_tbl;
	char *content;
	uint64_t address;
	uint16_t type;

	if (ehdr.e_shnum == 0)
	{
		printf("There are no sections in this file.\n");
		return;
	}

	str_tbl = read_section(fd, sh_tbl[ehdr.e_shstrndx]);
	for (i = 0; i < ehdr.e_shnum; i++)
	{
		type = sh_tbl[i].sh_type;
		if (display_section(type, ehdr, sh_tbl[i], str_tbl))
		{
			printf("Contents of section %s:\n",
					str_tbl + sh_tbl[i].sh_name);
			fflush(stdout);
			content = read_section(fd, sh_tbl[i]);
			address = sh_tbl[i].sh_addr;
			print_buffer(content, sh_tbl[i].sh_size, address);
		}
	}
}
