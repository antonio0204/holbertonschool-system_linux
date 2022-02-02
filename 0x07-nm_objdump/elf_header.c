#include "readelf.h"


void read_elf_section_header_N(ElfN_Ehdr *ehdr, FILE *file,
	int arch, char *filename)
{
	ElfN_Shdr *sh_tbl;
	unsigned int flags;
	int ret;

	ret = 0;
	flags = BFD_NO_FLAGS;
	if (arch == 64)
		read_elf_header_64(ehdr, file);
	else if (arch == 32)
		read_elf_header_32(ehdr, file);
	sh_tbl = malloc(sizeof(ElfN_Shdr) * ehdr->e_shnum);
	if (!sh_tbl)
		printf("Failder to allocate section header table\n");
	if (arch == 64)
		read_elf_sh_64(*ehdr, sh_tbl, fileno(file));
	else if (arch == 32)
		read_elf_sh_32(*ehdr, sh_tbl, fileno(file));
	printf("\n%s:	file format elf%d-%s\n", filename, arch,
	get_file_format_name(*ehdr));
	flags = get_flags(ehdr, sh_tbl, fileno(file));
	printf("architecture: %s, flags 0x%08x:\n",
		get_arch_mach_name(ehdr->e_machine), flags);
	if (flags == BFD_NO_FLAGS)
		printf("BFD_NO_FLAGS");
	else
	{
		ret |= _F(flags, HAS_RELOC, ret);
		ret |= _F(flags, EXEC_P, ret);
		ret |= _F(flags, HAS_LINENO, ret);
		ret |= _F(flags, HAS_DEBUG, ret);
		ret |= _F(flags, HAS_SYMS, ret);
		ret |= _F(flags, DYNAMIC, ret);
		ret |= _F(flags, WP_TEXT, ret);
		ret |= _F(flags, D_PAGED, ret);
	} printf("\n");
	printf("start address 0x%0*lx\n\n", arch == 32 ? 8 : 16, ehdr->e_entry);
	print_elf_section_header(sh_tbl, *ehdr, fileno(file));
}

