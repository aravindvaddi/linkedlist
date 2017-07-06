#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linkedlist.h"

/* function to return the length of linkedlist */

int ll_length (ll *list)
{
	int i;
	node *temp;

	if(list)
	{
		temp = list->head;
		for(i = 0; temp; i++, temp = temp->next);
	}

	return i;
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
			tail = tail->next;
		}
	}
}

/* function to initialize linkedlist to a given pointer */

void ll_create (ll **ref)
{
	*ref = malloc(sizeof **ref);
	(*ref)->head = (*ref)->tail = NULL;
}
