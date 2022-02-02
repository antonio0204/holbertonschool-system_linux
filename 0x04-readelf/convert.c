#include "hreadelf.h"
/**
 * convertmsb - convert to big endian, switch pointer
 * @ptr: pointer to first octet of word
 * @size: size of type ptr points to
 */
void convertmsb(char *ptr, size_t size)
{
	size_t tmp, start, end;

	for (start = 0, end = size - 1; start < end; ++start, --end)
	{
		tmp = ptr[start];
		ptr[start] = ptr[end];
		ptr[end] = tmp;
	}
}

/**
 * convert64 - convert all params to big endian
 * @elf64: elf 64 bytes information
 * @ismsb: is bit endian
 */
void convert64(Elf64_Ehdr elf64, int ismsb)
{
	if (ismsb == 2)
	{
		convertmsb((char *) &elf64.e_type, sizeof(elf64.e_type));
		convertmsb((char *) &elf64.e_machine, sizeof(elf64.e_machine));
		convertmsb((char *) &elf64.e_version, sizeof(elf64.e_version));
		convertmsb((char *) &elf64.e_entry, sizeof(elf64.e_entry));
		convertmsb((char *) &elf64.e_phoff, sizeof(elf64.e_phoff));
		convertmsb((char *) &elf64.e_shoff, sizeof(elf64.e_shoff));
		convertmsb((char *) &elf64.e_flags, sizeof(elf64.e_flags));
		convertmsb((char *) &elf64.e_ehsize, sizeof(elf64.e_ehsize));
		convertmsb((char *) &elf64.e_phentsize, sizeof(elf64.e_phentsize));
		convertmsb((char *) &elf64.e_shstrndx, sizeof(elf64.e_phoff));
		convertmsb((char *) &elf64.e_phnum, sizeof(elf64.e_phnum));
		convertmsb((char *) &elf64.e_shnum, sizeof(elf64.e_shnum));
		convertmsb((char *) &elf64.e_shstrndx, sizeof(elf64.e_shstrndx));
	}
}

/**
 * convert32 - convert all params to big endian
 * @elf32: elf 32 bytes information
 * @ismsb: is bit endian
 */
void convert32(Elf32_Ehdr elf32, int ismsb)
{
	if (ismsb == 2)
	{
		convertmsb((char *) &elf32.e_type, sizeof(elf32.e_type));
		convertmsb((char *) &elf32.e_machine, sizeof(elf32.e_machine));
		convertmsb((char *) &elf32.e_version, sizeof(elf32.e_version));
		convertmsb((char *) &elf32.e_entry, sizeof(elf32.e_entry));
		convertmsb((char *) &elf32.e_phoff, sizeof(elf32.e_phoff));
		convertmsb((char *) &elf32.e_shoff, sizeof(elf32.e_shoff));
		convertmsb((char *) &elf32.e_flags, sizeof(elf32.e_flags));
		convertmsb((char *) &elf32.e_ehsize, sizeof(elf32.e_ehsize));
		convertmsb((char *) &elf32.e_phentsize, sizeof(elf32.e_phentsize));
		convertmsb((char *) &elf32.e_shstrndx, sizeof(elf32.e_phoff));
		convertmsb((char *) &elf32.e_phnum, sizeof(elf32.e_phnum));
		convertmsb((char *) &elf32.e_shnum, sizeof(elf32.e_shnum));
		convertmsb((char *) &elf32.e_shstrndx, sizeof(elf32.e_shstrndx));
	}
}

