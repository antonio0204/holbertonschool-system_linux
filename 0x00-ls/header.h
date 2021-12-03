#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <ctype.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

/**
 * struct Flag - Store the flags status
 * @flag_one: Flag -1
 * @flag_a: FLag -a
 * @flag_a_u: Flag -A
 * @flag_l: Flag -l
 */
typedef struct Flag
{
	int flag_one;
	int flag_a;
	int flag_a_u;
	int flag_l;
} Flag_t;

/**
 * struct LS_Struct - Ls command struct
 * @directories: List of directories in argv
 * @files: List of files in argv
 * @error_access: List of access errors
 * @error_open: List of open errors
 * @options: List of options in argv
 * @directories_number: Number of directories in @directories
 * @files_number: Number of files in @files
 * @error_access_number: Number of access errors
 * @error_open_number: Number of open errors
 * @error_value: Error value on return
 */
typedef struct LS_Struct
{
	char **directories;
	char **files;
	char **error_access;
	char **error_open;
	Flag_t options;
	size_t directories_number;
	size_t files_number;
	size_t error_access_number;
	size_t error_open_number;
	size_t error_value;
} LS_Struct_t;

/*
 * Main
 */
int execute(int, char **);
LS_Struct_t initialize_ls(LS_Struct_t);
Flag_t initialize_flags(Flag_t flags);

/*
 * Print
 */
void print_directories(LS_Struct_t);
void print_files(LS_Struct_t);
void print_errors_access(LS_Struct_t);
void print_errors_open(LS_Struct_t);

/*
 * Arguments_to_struct
 */
LS_Struct_t get_arguments(int, char **, LS_Struct_t);
LS_Struct_t set_directories(char **, size_t, LS_Struct_t);
LS_Struct_t set_files(char **, size_t, LS_Struct_t);
LS_Struct_t set_errors_access(char **, size_t, LS_Struct_t);
LS_Struct_t set_errors_open(char **, size_t, LS_Struct_t);
LS_Struct_t get_arguments_helper(char **, size_t, LS_Struct_t);
char *_memset(char *, char, unsigned int);

/*
 * Helpers
 */
int _strlen(const char *);
void *_realloc(void *, unsigned int, unsigned int);
void _memcpy(char *, char *, unsigned int);
char *_strdup(char *);
char *_strcat(char *, char *);

/*
 * Print_format_dir
 */
int get_files_in_dir(char *, LS_Struct_t, size_t);
void print_directories_with_parameters(
	char **,
	char *, size_t, LS_Struct_t, size_t);
char **readdir_get_directories(DIR *, size_t *);
void print_dirname_at_start(char *, LS_Struct_t);
int _strcmp(char *, char *);

/*
 * Print_format_options
 */
void flag_l(char *, char **, size_t, LS_Struct_t);
void flag_a(char **, size_t, size_t);
void flag_A(
	char **,
	size_t,
	size_t);

/*
 * Sort
 */
char **sort_directories_list_by_name(char **, size_t);

/*
 * Lib
 */
int _strcmp_ci(char *, char *);
void free_struct(LS_Struct_t);
char **set_list(char **, char **, size_t, int);
LS_Struct_t add_current_directory(LS_Struct_t);
char __tolower(char);
void print_perm(char *, int);
int _strcmp_aux(char *, char *);

/*
 * Options
 */
Flag_t get_options_list(int, char **, Flag_t);
Flag_t get_options(char *, Flag_t);
void print_invalid_option(char *, int, int);
void print_unrecognized_option(char *, int);
Flag_t set_flags(Flag_t, char);
void print_ambi_option(char *option);

#endif
