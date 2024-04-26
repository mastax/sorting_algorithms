#include "list.h"

/**
 * ft_swap - swap 2 nodes in a doubly-lindek list :3
 * @a: the Adress of the first node.
 * @b: the Adress of the second node.
 * 
 * Return: (void)
*/
void    ft_swap(listint_t *a, listint_t *b)
{
    if (a->prev)
        a->prev->next = b;
    if (b->next)
        b->next->prev = a;
    a->next = b->next;
    b->prev = a->prev;
    a->prev = b;
    b->next = a;
}

/**
 * insertion_sort_list - insertion sorts a doubly-linked list :D
 * @list: The address of the pointer of the head node ,ok
 * 
 * Return: void
*/
void insertion_sort_list(listint_t **list)
{
    listint_t *key, *je;

    if (!list || !*list || !(*list)->next)
        return ;
    i = (*list)->next;
    while (key)
    {
        je = key;
        key = key->next;
        while (je && je->prev)
        {
            if(je->prev->n > je->n)
            {
                swap(je->prev, je);
                if (!je->prev)
                    *list = je;
                print_list(const listint_t *)*list;
            }
            else
                je = je->prev;
       }
    } 
}