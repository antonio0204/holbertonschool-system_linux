#include "readelf.h"

/**
 * read_elf_st_32 - fills the sym with suitable(32)
 * architecture data
 * @sym_tbl: section header table
 * @fd: file descriptor of input elf file
 * @ehdr: elf header structure
 * @shdr: SECTION header containing symbol table section
 */
void read_elf_st_32(ElfN_Ehdr ehdr, ElfN_Shdr shdr, ElfN_Sym *sym_tbl, int fd)
{
	uint64_t (*get_byte)(uint64_t, int), i;

	Elf32_Sym sym32_tbl;

	get_byte = (ehdr.e_ident[EI_DATA] == ELFDATA2MSB)
	? get_byte_big_endian : get_byte_host;

	assert(lseek(fd, (off_t) shdr.sh_offset, SEEK_SET) ==
	(off_t) shdr.sh_offset);

	for (i = 0; i < shdr.sh_size / sizeof(Elf32_Sym); i++)
	{
		read(fd, (void *)&sym32_tbl, shdr.sh_entsize);
		sym_tbl[i].st_name  = GET_BYTE(sym32_tbl.st_name);
		sym_tbl[i].st_info  = GET_BYTE(sym32_tbl.st_info);
		sym_tbl[i].st_other = GET_BYTE(sym32_tbl.st_other);
		sym_tbl[i].st_shndx = GET_BYTE(sym32_tbl.st_shndx);
		sym_tbl[i].st_value = GET_BYTE(sym32_tbl.st_value);
		sym_tbl[i].st_size  = GET_BYTE(sym32_tbl.st_size);
	}
}

/**
 * read_elf_sh_32 - fills the sh with suitable(32)
 * architecture data
 * @sh_tbl: section header table
 * @fd: file descriptor of input elf file
 * @ehdr: elf header structure
 */
void read_elf_sh_32(ElfN_Ehdr ehdr, ElfN_Shdr *sh_tbl, int fd)
{
	uint64_t (*get_byte)(uint64_t, int), i;

	Elf32_Shdr shdr32_tbl;

	get_byte = (ehdr.e_ident[EI_DATA] == ELFDATA2MSB)
	? get_byte_big_endian : get_byte_host;

	assert(lseek(fd, (off_t) ehdr.e_shoff, SEEK_SET) ==
	(off_t) ehdr.e_shoff);

	for (i = 0; i < ehdr.e_shnum; i++)
	{
		assert(read(fd, (void *)&shdr32_tbl, ehdr.e_shentsize) ==
		ehdr.e_shentsize);
		sh_tbl[i].sh_name = GET_BYTE(shdr32_tbl.sh_name);
		sh_tbl[i].sh_type = GET_BYTE(shdr32_tbl.sh_type);
		sh_tbl[i].sh_flags = GET_BYTE(shdr32_tbl.sh_flags);
		sh_tbl[i].sh_addr = GET_BYTE(shdr32_tbl.sh_addr);
		sh_tbl[i].sh_offset = GET_BYTE(shdr32_tbl.sh_offset);
		sh_tbl[i].sh_size = GET_BYTE(shdr32_tbl.sh_size);
		sh_tbl[i].sh_link = GET_BYTE(shdr32_tbl.sh_link);
		sh_tbl[i].sh_info = GET_BYTE(shdr32_tbl.sh_info);
		sh_tbl[i].sh_addralign = GET_BYTE(shdr32_tbl.sh_addralign);
		sh_tbl[i].sh_entsize = GET_BYTE(shdr32_tbl.sh_entsize);
	}
}

/**
 * read_elf_header_32 - fills the ehdr with suitable(32) architecture data
 * @ehdr: elf header structure
 * @file: input file
 */
void read_elf_header_32(ElfN_Ehdr *ehdr, FILE *file)
{
	ssize_t n;
	Elf32_Ehdr ehdr32;
	uint64_t (*get_byte)(uint64_t, int);

	get_byte = (ehdr->e_ident[EI_DATA] == ELFDATA2MSB)
	? get_byte_big_endian : get_byte_host;
	n = fread(&ehdr32.e_type, sizeof(ehdr32) - EI_NIDENT, 1, file);
	if (n != 1)
		exit(EXIT_FAILURE);
	ehdr->e_type = GET_BYTE(ehdr32.e_type);
	ehdr->e_machine = GET_BYTE(ehdr32.e_machine);
	ehdr->e_version = GET_BYTE(ehdr32.e_version);
	ehdr->e_entry = GET_BYTE(ehdr32.e_entry);
	ehdr->e_phoff = GET_BYTE(ehdr32.e_phoff);
	ehdr->e_shoff = GET_BYTE(ehdr32.e_shoff);
	ehdr->e_flags = GET_BYTE(ehdr32.e_flags);
	ehdr->e_ehsize = GET_BYTE(ehdr32.e_ehsize);
	ehdr->e_phentsize = GET_BYTE(ehdr32.e_phentsize);
	ehdr->e_phnum = GET_BYTE(ehdr32.e_phnum);
	ehdr->e_shentsize = GET_BYTE(ehdr32.e_shentsize);
	ehdr->e_shnum = GET_BYTE(ehdr32.e_shnum);
	ehdr->e_shstrndx = GET_BYTE(ehdr32.e_shstrndx);
}
