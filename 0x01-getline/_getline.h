#ifndef GETLINE_H
#define GETLINE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


/**
 * struct getlined_s - holds an open file descriptor buffer
 * @fd: the integer file descriptor
 * @buf: pointer to the char buffer
 * @index: current index in the buf
 * @len: current length of the buf
 * @next: next node in linked list
 *
 * Description: singly linked list node structure,
 * which holds a file descirptor
 */
typedef struct getlined_s
{
	int fd;
	char *buf;
	size_t index;
	size_t len;
	struct getlined_s *next;
} getlined_t;

#define READ_SIZE 1024

char *_getline(const int fd);
char *read_bfz(getlined_t *fb);
getlined_t *get_fdbfz(getlined_t *head, const int fd);
char *_strchr(char *s, char c, ssize_t size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif
