#include "sort.h"

/**
 * swap_node - Swaps two nodes in a doubly linked list.
 * @list: A pointer to a pointer to the first node of the list.
 * @node1: A pointer to the first node to swap.
 * @node2: A pointer to the second node to swap.
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
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                        order using the Insertion sort algorithm.
 * @list: A pointer to a pointer to the first node of the list.
 *
 * Description: Prints the list after each swap correctly.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		while (temp->prev && temp->n < temp->prev->n)
		{
			swap_node(list, temp->prev, temp);
			print_list(*list);
		}
	}
}
