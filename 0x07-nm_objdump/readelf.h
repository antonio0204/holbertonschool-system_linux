#ifndef _READELF_H
#define _READELF_H

#include <assert.h>
#include <elf.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <inttypes.h>
#include <linux/limits.h>
#include <ctype.h>
#include <math.h>

#define _F(f, t, r) printf("%s%s", r && (f & t) ? ", " : "", f & t ? #t : "")
#define GET_BYTE(field) get_byte(field, sizeof(field))
#define ELF_ST_BIND(x) ((x) >> 4)
#define ELF_ST_TYPE(x) (((unsigned int) x) & 0xf)
#define E "Error: Not an ELF file - it has the wrong magic bytes at the start"
#define SPACE {print_char(' '); print_char(' '); }
/**
 * struct ehdr - Struct to represent headers from both 32 and 64bits files
 * @e_ident : magic number
 * @e_entry : Entry point virtual address
 * @e_phoff : Program header table file offset
 * @e_shoff: Section header table file offset
 * @e_version: Identifies object file version
 * @e_flags: Processor-specific flags
 * @e_type: Identifies object file type
 * @e_machine:  Specifies required architecture
 * @e_ehsize:  ELF header size in bytes
 * @e_phentsize:  Program header table entry size
 * @e_phnum:  Program header table entry count
 * @e_shentsize:  Section header table entry size
 * @e_shnum:  Section header table entry count
 * @e_shstrndx: Section header string table index
 */
typedef struct ehdr
{
	unsigned char e_ident[EI_NIDENT];
	uint64_t e_entry;
	uint64_t e_phoff;
	uint64_t e_shoff;
	uint32_t e_version;
	uint32_t e_flags;
	uint16_t e_type;
	uint16_t e_machine;
	uint16_t e_ehsize;
	uint16_t e_phentsize;
	uint16_t e_phnum;
	uint16_t e_shentsize;
	uint16_t e_shnum;
	uint16_t e_shstrndx;
} ElfN_Ehdr;

/**
 * struct shdr - Struct to represent section headers from both 32 and 64bits
 * @sh_name : offset to a string in the .shstrtab section that represents the
 * name of this section
 * @sh_type : Identifies the type of this header.
 * @sh_flags : Identifies the attributes of the section.
 * @sh_addr: Virtual address of the section in memory, for sections that are
 * loaded.
 * @sh_offset: Offset of the section in the file image.
 * @sh_size: Size in bytes of the section in the file image. May be 0.
 * @sh_link: Contains the section index of an associated section.
 * @sh_info:  Contains extra information about the section.
 * @sh_addralign:  Contains the required alignment of the section.
 * @sh_entsize:  Contains the size, in bytes, of each entry, for sections that
 * contain fixed-size entries
 */
typedef struct shdr
{
	uint32_t sh_name;
	uint32_t sh_type;
	uint64_t sh_flags;
	uint64_t sh_addr;
	uint64_t sh_offset;
	uint64_t sh_size;
	uint32_t sh_link;
	uint32_t sh_info;
	uint64_t sh_addralign;
	uint64_t sh_entsize;
} ElfN_Shdr;

/**
 * struct symtab-  Symbol table entry
 * @st_name : Symbol name, index in string tbl
 * @st_info : Type and binding attributes
 * @st_other :  No defined meaning, 0
 * @st_shndx : Associated section index
 * @st_value : Value of the symbol
 * @st_size : Associated symbol size
 */
typedef struct symtab
{
	uint64_t st_name;
	unsigned char st_info;
	unsigned char st_other;
	uint16_t st_shndx;
	uint64_t st_value;
	uint64_t st_size;
} ElfN_Sym;

/**
 * enum flags- enum of flags for an elf
 * @BFD_NO_FLAGS: No flags
 * @HAS_RELOC: Has REL AND RELA types
 * @HAS_DEBUG: NOt implemented yet
 * @EXEC_P: Is exec
 * @HAS_LINENO: not implemented yet
 * @HAS_SYMS: Has symbols
 * @HAS_LOCAL: Has local variables
 * @DYNAMIC: Has dynamic content
 * @WP_TEXT: not implemented yet
 * @D_PAGED: Is dynamic paged
 */
enum flags
{
	BFD_NO_FLAGS = 0,
	HAS_RELOC    = 1,
	EXEC_P       = 2,
	HAS_LINENO   = 4,
	HAS_DEBUG    = 8,
	HAS_SYMS     = 16,
	HAS_LOCAL    = 32,
	DYNAMIC      = 64,
	WP_TEXT      = 128,
	D_PAGED      = 256
};

/* utils */
uint64_t get_byte_big_endian(uint64_t data, int size);
uint64_t get_byte_host(uint64_t data, int size);
char *read_section(int fd, ElfN_Shdr sh);
char get_st_flag(ElfN_Shdr sh_tbl[], ElfN_Sym symtab, char *strtab);

char determine_st_flag_roftb(ElfN_Sym symtab, char *strtab,
ElfN_Shdr sh_tbl[]);
int is_symbol_from_section(ElfN_Sym symtab, char *strtab,
ElfN_Shdr sb_tbl[], const char *s);

/* 64 */
void read_elf_header_64(ElfN_Ehdr *ehdr, FILE *file);
void read_elf_sh_64(ElfN_Ehdr ehdr, ElfN_Shdr *sh_tbl, int fd);
void read_elf_st_64(ElfN_Ehdr ehdr, ElfN_Shdr shdr, ElfN_Sym *sym_tbl, int fd);

/* 32 */
void read_elf_header_32(ElfN_Ehdr *ehdr, FILE *file);
void read_elf_sh_32(ElfN_Ehdr ehdr, ElfN_Shdr *sh_tbl, int fd);
void read_elf_st_32(ElfN_Ehdr ehdr, ElfN_Shdr shdr, ElfN_Sym *sym_tbl, int fd);

bool elf_check_file(unsigned char *magic);
bool get_architecture(char c, int *arch);


int read_elf_stN(ElfN_Ehdr *ehdr, FILE *file, int arch);
void print_elf_symbol_table(ElfN_Shdr sh_tbl[], ElfN_Sym sym_tbl[],
			    ElfN_Ehdr ehdr, uint64_t count,
			    int fd);

/* */
void read_elf_section_header_N(ElfN_Ehdr *ehdr, FILE *file, int arch,
								char *filename);

char *get_arch_mach_name(unsigned int e_machine);
char *get_file_format_name(ElfN_Ehdr ehdr);
int get_flags(ElfN_Ehdr *ehdr, ElfN_Shdr sh_tbl[], int fd);

void read_elf_section_header_N(ElfN_Ehdr *ehdr,
FILE *file, int arch, char *filename);

void print_elf_section_header(ElfN_Shdr sh_tbl[], ElfN_Ehdr ehdr, int fd);

void print_buffer(char *b, int size, uint64_t address);
bool display_section(uint32_t type, ElfN_Ehdr ehdr,
ElfN_Shdr shdr, char *str_tbl);

#endif
