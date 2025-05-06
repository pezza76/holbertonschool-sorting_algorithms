#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @a: First node
 * @b: Second node (a->next)
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	else
		*list = b;

	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;

	a->prev = b;
	b->next = a;

	print_list(*list);
}

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		while (current->prev && current->n < current->prev->n)
		{
			swap_nodes(list, current->prev, current);
		}
		current = current->next;
	}
}

