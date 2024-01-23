#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @list: Pointer to the head of the doubly linked list
 * @current: Current node to be swapped
 * @temp: Node to be swapped with current
 */
void swap_nodes(listint_t **list, listint_t *current, listint_t *temp)
{
	if (current->prev != NULL)
		current->prev->next = temp;
	else
		*list = temp;

	if (temp->next != NULL)
		temp->next->prev = current;

	temp->prev = current->prev;
	current->prev = temp;
	current->next = temp->next;

	if (temp->next != NULL)
		temp->next->prev = current;

	temp->next = current;
}

/**
 * reverse_swap - Performs reverse traversal and swapping
 * for Cocktail Shaker sort algorithm
 *
 * @list: Pointer to the head of the doubly linked list
 * @current: Current node being compared and swapped
 * @swapped: Flag indicating whether any swap occurred
 */
void reverse_swap(listint_t **list, listint_t *current, int *swapped)
{
	listint_t *temp;

	while (current->prev != NULL)
	{
		if (current->n < current->prev->n)
		{
			temp = current->prev;
			swap_nodes(list, current, temp);
			*swapped = 1;
			print_list(*list);
		}
		else
		{
			current = current->prev;
		}
	}

	if (current->prev == NULL)
	{
		current = current->next;
	}
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Cocktail Shaker sort algorithm
 *
 * @list: Pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		current = *list;

		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				temp = current->next;
				swap_nodes(list, current, temp);
				swapped = 1;
				print_list(*list);
			}
			else
			{
				current = current->next;
			}
		}

		if (!swapped)
			break;

		reverse_swap(list, current, &swapped);

	} while (swapped);
}
