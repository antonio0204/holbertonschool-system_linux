#include "hreadelf.h"
/**
 * printinstruction - print struct with info string
 * @instruct: instruct array
 * @size: size array
 * @match: match bytes
 */
void printinstruction(instruction_t instruct[], int size, Elf64_Half match)
{
	int i;
	int m = 0;

	for (i = 0; i < size; i++)
	{
		if (instruct[i].code == match)
		{
			printf("%s\n", instruct[i].str);
			m = 1;
			break;
		}
	}

	if (m != 1)
		printf("%s\n", instruct[0].str);
}

/**
 *printmachine - prints arquitecture
 *@machine: bytes type arquitecture
 */
void printmachine(Elf64_Half machine)
{
	instruction_t machines[] = {
	{ EM_NONE, "No machine" },
	{ EM_M32, "AT&T WE 32100" },
	{ EM_SPARC, "Sparc" },
	{ EM_386, "Intel 80386" },
	{ EM_88K, "Motorola m88k family" },
	{ EM_860, "Intel 80860" },
	{ EM_MIPS, "MIPS R3000 big-endian" },
	{ EM_PARISC, "HPPA" },
	{ EM_SPARC32PLUS, "Sun's \"v8plus\"" },
	{ EM_PPC, "PowerPC" },
	{ EM_PPC64, "PowerPC 64-bit" },
	{ EM_S390, "IBM S390" },
	{ EM_ARM, "ARM" },
	{ EM_SH, "Hitachi SH" },
	{ EM_SPARCV9, "SPARC v9 64-bit"},
	{ EM_IA_64, "Intel Merced" },
	{ EM_X86_64, "Advanced Micro Devices X86-64" },
	{ EM_VAX, "Digital VAX" }
	};

	printf("%9s%-28c", "Machine", ':');
	printinstruction(machines, 18, machine);
}

/**
 * printtype - prints the object file type
 * @type: type bytes
 */
void printtype(Elf64_Half type)
{
	instruction_t types[] = {
	{ ET_NONE, "NONE (No file type)"},
	{ ET_REL, "REL (Relocatable file)" },
	{ ET_EXEC, "EXEC (Executable file)" },
	{ ET_DYN, "DYN (Shared object file)" },
	{ ET_CORE, "CORE (Core file)" }
	};

	printf("%6s%-31c", "Type", ':');
	printinstruction(types, 5, type);
}

/**
 * printosabi - prints OS, ABI to which the object is targeted, and ABI version
 * @ident: elf osabi
 */
void printosabi(unsigned char *ident)
{
	instruction_t osabi[] = {
	/* { 0, printf("<unknown: %x>\n", ident[EI_OSABI]) }, */
	{ ELFOSABI_NONE, "UNIX - System V" },
	{ ELFOSABI_HPUX, "UNIX - HP-UX" },
	{ ELFOSABI_NETBSD, "UNIX - NetBSD" },
	{ ELFOSABI_LINUX, "UNIX - Linux" },
	{ ELFOSABI_SOLARIS, "UNIX - Solaris" },
	{ ELFOSABI_IRIX, "UNIX - SGI Irix" },
	{ ELFOSABI_FREEBSD, "UNIX - Compaq TRU64" },
	{ ELFOSABI_ARM, "UNIX - ARM" }
	};
	printf("%8s%-29c", "OS/ABI", ':');
	printinstruction(osabi, 8, ident[EI_OSABI]);
	printf("%14s%24i\n", "ABI Version:", ident[EI_ABIVERSION]);
}

