#include "laps.h"

/**
 * race_state - print race
 * @id: the cars id
 * @size: the number of cars in the race
 * Return: void
 */
void race_state(int *id, size_t size)
{
	size_t i;
	Nascar *_nascar;

	static Nascar *head;

	if (size == 0)
	{
		while (head != NULL)
		{
			_nascar = head;
			head = head->next;
			free(_nascar);
		}
		return;
	}
	for (i = 0; i < size; i++)
		new_nascar(&head, id[i]);

	printf("Race state:\n");
	for (_nascar = head; _nascar != NULL; _nascar = _nascar->next)
		printf("Car %d [%lu laps]\n", _nascar->id, _nascar->laps);
}

/**
 * new_nascar - add a new car to the race
 * @head: the head of the linked list
 * @id: the id of the new car to add
 * Return: void
 */
void new_nascar(Nascar **head, int id)
{
	Nascar *_nascar, *t_nascar;

	if (*head == NULL || id < (*head)->id)
	{
		_nascar = malloc(sizeof(Nascar));
		if (_nascar == NULL)
			exit(EXIT_FAILURE);
		_nascar->id = id;
		_nascar->laps = 0;
		_nascar->next = *head;
		*head = _nascar;
		printf("Car %d joined the race\n", id);
		return;
	}
	_nascar = *head;
	while (_nascar->next && _nascar->next->id <= id)
		_nascar = _nascar->next;
	if (_nascar->id == id)
	{
		_nascar->laps++;
		return;
	}
	t_nascar = malloc(sizeof(Nascar));
	if (t_nascar == NULL)
		exit(EXIT_FAILURE);
	t_nascar->id = id;
	t_nascar->laps = 0;
	t_nascar->next = _nascar->next;
	_nascar->next = t_nascar;
	printf("Car %d joined the race\n", id);
}
