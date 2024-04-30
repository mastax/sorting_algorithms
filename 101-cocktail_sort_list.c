#include "sort.h"

/**
 * swap_me - swap th nodes them_selves.
 * @current: pointer...
 * @current_old: pointer...
 * @list: Doubly Linked List
 */
void swap_me(listint_t *curent, listint_t *curent_old, listint_t **list)
{
	listint_t *tmp1 = curent->next;
	listint_t *tmp2 = curent_old->prev;

	if (tmp1 != NULL)
		tmp1->prev = curent_old;
	if (tmp2 != NULL)
		tmp2->next = curent;
	curent->prev = tmp2;
	curent_old->next = tmp1;
	curent->next = curent_old;
	curent_old->prev = curent;
	if (*list == curent_old)
		*list = curent;
	print_list(*list);
}

/**
 * cocktail_sort_list - cocktail_sort_list
 *
 * @list: doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *check = *list, *first = NULL, *last = NULL;

	if (!(*list))
		return;
	if (!list)
		return;
	if (!(*list)->next)
		return;
	do {
		while (check->next)
		{
			if (check->n > check->next->n)
				swap_me(check->next, check, list);
			else
				check = check->next;
		}
		last = check;
		while (check->prev != first)
		{
			if (check->n < check->prev->n)
				swap_me(check, check->prev, list);
			else
				check = check->prev;
		}
		first = check;
	} while (first != last);
}