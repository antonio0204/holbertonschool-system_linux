#ifndef HREADELF_H
#define HREADELF_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <elf.h>

/**
 * struct instruction_s - code and str
 * @code: the byte code
 * @str: string to print
 *
 * Description: code and str
 * for hreadelf HOLBERTON
 */
typedef struct instruction_s
{
	int code;
	char *str;
} instruction_t;
/* convert */
void convertmsb(char *ptr, size_t size);
void convert64(Elf64_Ehdr elf64, int ismsb);
void convert32(Elf32_Ehdr elf32, int ismsb);
/* printelf_3 */
void printshstrndx(Elf64_Half shstrndx64);
void printshnum(Elf64_Half shnum64);
void printshentsize(Elf64_Half shentsize64);
void printphnum(Elf64_Half phnum64);
/* printelf_2 */
void printhdrsize(Elf64_Ehdr elf64);
void printflags(Elf64_Word flags64);
void printpshoff(Elf64_Ehdr elf64);
void printentry(Elf64_Addr entry64);
void printfileversion(Elf64_Word version);
/* printelf_1 */
void printinstruction(instruction_t instruct[], int size, Elf64_Half match);
void printmachine(Elf64_Half machine);
void printtype(Elf64_Half type);
void printosabi(unsigned char *ident);
/* printelf_0 */
int printversion(unsigned char *ident, char *str);
int printdata(unsigned char *ident, char *str);
int printclass(unsigned char *ident, char *str);
void _printmag(unsigned char *ident);

/* printelf_32_1 */
void printinstruction_32(instruction_t instruct[], int size, Elf32_Half match);
void printmachine_32(Elf32_Half machine);
void printtype_32(Elf32_Half type);
void printosabi_32(unsigned char *ident);
/* printelf_32_2 */
void printhdrsize_32(Elf32_Ehdr elf32);
void printflags_32(Elf32_Word flag32);
void printpshoff_32(Elf32_Ehdr elf32);
void printentry_32(Elf32_Addr entry32);
void printfileversion_32(Elf32_Word version);

/* printelf_32_3 */
void printshstrndx_32(Elf32_Half shstrndx32);
void printshnum_32(Elf32_Half shnum32);
void printshentsize_32(Elf32_Half shentsize32);
void printphnum_32(Elf32_Half phnum32);

/* printelf */
void printelf64h(Elf64_Ehdr elf64);
void printelf32h(Elf32_Ehdr elf32);

#endif
