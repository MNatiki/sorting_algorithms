#include "sort.h"
#include <stdio.h>


/**
 * insertion_sort_list - sort list from an array of integers
 *
 * @list: list to convert to a doubly linked list
 *
 * Return: None
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current;

if (!list || !(*list) || !(*list)->next)
return;

current = (*list)->next;

while (current)
{
listint_t *tmp = current->prev;
while (tmp && tmp->n > current->n)
{
if (tmp->prev)
tmp->prev->next = current;
else
*list = current;

current->prev = tmp->prev;
tmp->prev = current;
tmp->next = current->next;
if (current->next)
current->next->prev = tmp;
current->next = tmp;

print_list(*list);
tmp = current->prev;
}
current = current->next;
}
}
