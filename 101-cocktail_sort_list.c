#include "sort.h"


/**
 * swap_node - Swaps two nodes in a doubly linked list
 *
 * @list: Pointer to the head of the list
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_node(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1 == node2)
		return;

	if (node1->prev == NULL)
		*list = node2;
	else
		node1->prev->next = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node2->next = node1;
	node1->prev = node2;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in
 *                      ascending order using the Cocktail shaker
 *                      sort algorithm.
 * @list: Pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = *list, *end = NULL;
	int swapped = 1;

	if (list == NULL || (*list) == NULL || ((*list)->next) == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		/* Traverse from left to right */
		while (start->next != end)
		{
			if (start->n > start->next->n)
			{
				swap_node(list, start, start->next);
				swapped = 1;
				print_list(*list);
			} else
				start = start->next;
		}
		end = start;
		/* Traverse from right to left */
		while (start->prev != NULL)
		{
			if (start->prev->n > start->n)
			{
				swap_node(list, start->prev, start);
				swapped = 1;
				print_list(*list);
			} else
				start = start->prev;
		}
		start = (*list);
	}
}
