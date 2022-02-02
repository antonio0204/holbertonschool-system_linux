#ifndef _HLS_H_
#define _HLS_H_
/*--- C libs ---*/
#include <stdio.h>
#include <stdlib.h>

/**
 * struct nascar - singly linked with the data cars present in the race
 * @id: id of the nascar
 * @laps: number of the laps completed
 * @next: the next nascar struct
 * Description: singly linked list node to store nascars
 */
typedef struct nascar
{
	int id;
	size_t laps;
	struct nascar *next;
} Nascar;


void race_state(int *id, size_t size);
void new_nascar(Nascar **head, int id);

#endif
