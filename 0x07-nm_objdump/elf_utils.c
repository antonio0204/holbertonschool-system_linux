#include "readelf.h"

/**
 * get_byte_big_endian - fetches the bytes in big endian formatted data
 * @data: data to be fetched
 * @size: of the data
 *
 * Return: the bytes in big endian format data.
 */
uint64_t get_byte_big_endian(uint64_t data, int size)
{
	switch (size)
	{
		case 2:
			return (be16toh(data));
		case 4:
			return (be32toh(data));
		case 8:
			return (be64toh(data));
		default:
			return (0);
	}
}

/**
 * get_byte_host - fetches the bytes
 * @data: data to be fetched
 * @size: size of the data
 *
 * Return: the data
 */
uint64_t get_byte_host(uint64_t data, int size)
{
	(void)size;
	return (data);
}

/**
 * read_section - fetches the section
 * @sh: section header
 * @fd: file descriptor of input elf file
 * Return: string representation of the file
 */
char *read_section(int fd, ElfN_Shdr sh)
{
	char *buff = malloc(sh.sh_size + 1);

	if (!buff)
	{
		printf("Failed to allocate\n");
	}

	assert(buff != NULL);
	assert(lseek(fd, (off_t) sh.sh_offset, SEEK_SET) ==
		(off_t) sh.sh_offset);
	assert(read(fd, (void *) buff, sh.sh_size) == (ssize_t) sh.sh_size);
	buff[sh.sh_size] = '\0';
	return (buff);
}

/**
 * get_st_flag - get the flag based on symbol type
 * @sh_tbl: section header table
 * @symtab: symbol table
 * @strtab: string table
 * Return: flag
 */
char get_st_flag(ElfN_Shdr sh_tbl[], ElfN_Sym symtab, char *strtab)
{
	char t;

	if (symtab.st_shndx == SHN_ABS)
		t = 'a';
	else if (determine_st_flag_roftb(symtab, strtab, sh_tbl))
		return (determine_st_flag_roftb(symtab, strtab, sh_tbl));
	else if (is_symbol_from_section(symtab, strtab, sh_tbl, ".bss"))
		t = 'b';
	else if (is_symbol_from_section(symtab, strtab, sh_tbl, ".text")
	|| ELF_ST_TYPE(symtab.st_info) == STT_FUNC
	|| is_symbol_from_section(symtab, strtab, sh_tbl, ".init_array")
	|| is_symbol_from_section(symtab, strtab, sh_tbl, ".fini_array")
	|| is_symbol_from_section(symtab, strtab, sh_tbl, ".plt"))
		t = 't';
	else if (is_symbol_from_section(symtab, strtab, sh_tbl, ".rodata")
	|| is_symbol_from_section(symtab, strtab, sh_tbl, ".eh_frame_hdr")
	|| is_symbol_from_section(symtab, strtab, sh_tbl, ".eh_frame"))
		t = 'r';
	else if (ELF_ST_TYPE(symtab.st_info) == STT_OBJECT ||
			ELF_ST_TYPE(symtab.st_info) == STT_NOTYPE ||
			is_symbol_from_section(symtab, strtab, sh_tbl, ".data") ||
			is_symbol_from_section(symtab, strtab, sh_tbl, ".data1"))
		t = 'd';
	else
		return ('?');
	return (ELF_ST_BIND(symtab.st_info) == STB_LOCAL ? t : t - 32);
}

