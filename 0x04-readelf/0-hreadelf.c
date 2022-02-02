# include "hreadelf.h"
/**
 * get_fd - get file descriptor
 * @name: name of filedescriptor get
 *
 * Return: FILE
 */
FILE *get_fd(char *name)
{
	FILE *fp;

	fp = fopen(name, "rb");

	if (!fp)
	{
		fprintf(stderr, "%s: Error: '%s': No such file\n", "no", name);
		return (NULL);
	}

	return (fp);
}
/**
 * valid_args - valid arguments
 * @argc: count args
 * @argv: array with args
 * Return: success 1, otherwise 0
 */
int valid_args(int argc, char **argv)
{
	int status;
	struct stat sb;

	status = 1;
	if (argc != 2)
	{
		fprintf(stderr, "%s: Warning: Nothing to do.\n"
						"Usage: %s elf-file\n", *argv, *argv);
		return (0);
	}

	stat(argv[1], &sb);
	if (!S_ISREG(sb.st_mode))
	{
		fprintf(stderr, "%s: Error: '%s': is not an ordinary file\n",
			argv[0], argv[1]);
	}
	return (status);
}

/**
 * printelfh - print elf header
 * @fp: file descriptor
 * @args: array with args
 * Return: success 1, otherwise 0
 */
int printelfh(FILE *fp, char *args)
{
	Elf64_Ehdr elf64;
	Elf32_Ehdr elf32;
	int exit_stat, is32, ismsb;

	fread(&elf64, sizeof(elf64), 1, fp);
	rewind(fp);
	fread(&elf32, sizeof(elf32), 1, fp);
	if (memcmp(elf64.e_ident, ELFMAG, SELFMAG))
	{
		fprintf(stderr, "Error");
		return (1);
	}
	puts("ELF Header:");
	_printmag(elf64.e_ident);
	is32 = printclass(elf64.e_ident, args);
	if (is32 == 1)
		return (1);
	ismsb = printdata(elf64.e_ident, args);
	if (ismsb == 1)
		return (1);
	exit_stat = printversion(elf64.e_ident, args);
	if (exit_stat)
		return (1);
	/* ------ */
	if (is32)
	{
		convert32(elf32, ismsb);
		printelf32h(elf32);
	}
	else
	{
		convert64(elf64, ismsb);
		printelf64h(elf64);
	}
	return (exit_stat);
}
/**
 * main - read elf file
 * @argc: the count of args
 * @argv: the args
 * Return: success 1, otherwise 0
*/
int main(int argc, char **argv)
{
	FILE *fp;
	int exit_stat;

	if (valid_args(argc, argv) == 0)
		return (1);

	fp = get_fd(argv[1]);

	if (!fp)
		return (1);

	exit_stat = printelfh(fp, *argv);
	return (exit_stat);
}

