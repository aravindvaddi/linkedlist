#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linkedlist.h"

/* function to return the length of linkedlist */

int ll_length (ll *list)
{
	return list->length + 1;
}

/* function to return address of a node for the first occurance of a given value */

node *ll_search (ll *list, int data)
{
	node *temp = NULL;

	if(list)
	{
		temp = list->head;
		while(temp && temp->data != data)
			temp = temp->next;
	}

	return temp;
}

/* function to return address of a node at given position */

node *ll_address (ll *list, int position)
{
	node *temp = NULL;

	if(list)
	{
		temp = list->head;
		while(temp && position)
		{
			temp = temp->next;
			position--;
		}
	}

	return temp;
}

/* function to traverse and print linkedlist */

void ll_print (ll *list)
{
	node *temp;
	if(list)
	{
		temp = list->head;

		while(temp)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}

		printf("\n");
	}
}

/* core function to print linkedlist in reverse (helper function to function) */

void lib_reverseprint (node *head)
{
	if(head)
	{
		lib_reverseprint(head->next);
		printf("%d ", head->data);
	}
}

/* function to print linkedlist in reverse */

void ll_reverse_print (ll *list)
{
	lib_reverseprint (list->head);
	printf("\n");
}

/* function to check if linkedlist is empty */

int ll_empty(ll *list)
{
	if(list)
		return (!list->head) ? 1 : 0;
}

/* function to create node with data and return it's address */

node *ll_node (int data)
{
	node *temp;

	temp = malloc(sizeof *temp);
	temp->data = data;
	temp->next = NULL;

	return temp;
}

/* function to insert in the front of the list */

void ll_f_insert (ll *list, int data)
{
	node *temp;
	if(list)
	{
		temp = ll_node(data);
		temp->next = list->head;

		if(ll_empty(list))
			list->head = list->tail = temp;
		else
			list->head = temp;

		list->length++;
	}
}

/* function to insert at the end of the list */

void ll_e_insert (ll *list, int data)
{
	node *temp;
	if(list)
	{
		if(ll_empty(list))
			ll_f_insert(list, data);
		else
		{
			temp = ll_node(data);
			list->tail->next = temp;
			list->tail = list->tail->next;
			list->length++;
		}

	}
}

/* function to insert at a given position */

void ll_p_insert (ll *list, int data, int position)
{
	node *temp, *prev;
	if(list)
	{
		if(position == 0)
			ll_f_insert (list, data);
		else if(position > ll_length(list))
			ll_e_insert (list, data);
		else
		{
			temp = ll_node(data);
			prev = ll_address (list, position - 1);
			temp->next = prev->next;
			prev->next = temp;
			list->length++;
		}
	}
}


/* function to initialize linkedlist to a given pointer */

void ll_create (ll **ref)
{
	*ref = malloc(sizeof **ref);
	(*ref)->head = (*ref)->tail = NULL;
	(*ref)->length = -1;
}

/* function to generate a random linkedlist */

void ll_generate_random (ll **ref, int length, int range)
{
	int i;

	ll_create(ref);
	srand(time(NULL));

	for(i = 0; i < length; i++)
		ll_f_insert (*ref, rand() % range);

}
