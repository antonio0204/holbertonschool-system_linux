#include "header.h"

/**
 * _strcmp - Compare strings
 * Description: This function compare two strings
 * @s1: First string to compare
 * @s2: Second string to compare
 * Return: @n bytes of @src
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 > *s2)
			return (*s1 - *s2);
		else if (*s2 > *s1)
			return ((*s2 - *s1) * -1);
		s1++;
		s2++;
	}
	return (0);
}

void print_perm(
	char *dir_path,
	int is_dir
)
{
	char permissions[11];
	struct stat sb;
	struct passwd *usr;
	struct group *grp;
	char *time;
	mode_t perm;

	if (lstat(dir_path, &sb) == 0)
	{
		perm = sb.st_mode;
		usr = getpwuid(sb.st_uid);
		grp = getgrgid(sb.st_gid);
		time = ctime(&(sb.st_mtime));
		_memset(permissions, '-', 11);
		if (is_dir == 0)
			permissions[0] = ((perm & S_IFMT) == S_IFDIR) ? 'd' : '-';
		if (S_ISLNK(perm))
			permissions[0] = 'l';
		permissions[1] = (perm & S_IRUSR) ? 'r' : '-';
		permissions[2] = (perm & S_IWUSR) ? 'w' : '-';
		permissions[3] = (perm & S_IXUSR) ? 'x' : '-';
		permissions[4] = (perm & S_IRGRP) ? 'r' : '-';
		permissions[5] = (perm & S_IWGRP) ? 'w' : '-';
		permissions[6] = (perm & S_IXGRP) ? 'x' : '-';
		permissions[7] = (perm & S_IROTH) ? 'r' : '-';
		permissions[8] = (perm & S_IWOTH) ? 'w' : '-';
		permissions[9] = (perm & S_IXOTH) ? 'x' : '-';
		permissions[10] = '\0';
		printf("%s ", permissions);
		printf("%ld ", sb.st_nlink);
		printf("%s ", usr->pw_name);
		printf("%s ", grp->gr_name);
		printf("%ld ", sb.st_size);
		printf("%c%c%c %c%c %c%c%c%c%c ", time[4], time[5], time[6],
		time[8], time[9], time[11], time[12], time[13], time[14], time[15]);
	}
}

/**
 * _strcmp_aux - Compare strings
 * Description: This function compare two strings
 * @s1: First string to compare
 * @s2: Second string to compare
 * Return: @n bytes of @src
 */
int _strcmp_aux(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 > *s2)
			return (*s1 - *s2);
		else if (*s2 > *s1)
			return ((*s2 - *s1) * -1);
		s1++;
		s2++;
		if (*s1 == '\0' && *s2 != '\0')
			return (-1);
		if (*s1 != '\0' && *s2 == '\0')
			return (1);
	}
	return (0);
}
