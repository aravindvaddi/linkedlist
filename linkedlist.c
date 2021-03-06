#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linkedlist.h"

/* function to return the length of linkedlist */

int ll_length (ll *list)
{
	/* function returns the number of elements in the list */
	return list->length + 1;
}

/* function to return position of an element with a given data */

int ll_position (ll *list, int data)
{
	node *temp;
	int position;

	if(list)
	{
		temp = list->head;
		if(temp)
		{
			for(position = 0; temp && temp->data != data; position++)
				temp = temp->next;
			if(position < ll_length(list));
				return position;
		}
	}
	return -1;
}

/* function to return data of an element at a given position */

int ll_data (ll *list, int position)
{
	node *temp = ll_address(list, position);
	if(temp)
		return temp->data;
	else
		return -1;
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

/* function to reverse a linkedlist */

void ll_reverse (ll *list)
{
	node *prev, *curr, *next;
	if(list)
	{
		curr = list->head;
		prev = NULL;

		while(curr)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		list->tail = list->head;
		list->head = prev;
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

	temp = malloc(sizeof(node));
	temp->data = data;
	temp->next = NULL;

	return temp;
}

/* function to insert in the front of the list */

void ll_f_insert (ll *list, int data)
{
	node *temp = NULL;
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
	if(list && position <= ll_length(list))
	{
		if(position == 0)
			ll_f_insert (list, data);
		else if(position = ll_length(list))
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

/* function to remove node at front of the list */

void ll_f_remove (ll *list)
{
	ll_p_remove(list, 0);
}

/* function to remove node at the end of the list */

void ll_e_remove (ll *list)
{
	ll_p_remove (list, list->length);
}

/* function to remove node at a given position */

void ll_p_remove (ll *list, int position)
{
	node *temp, *prev;

	if(list && !ll_empty(list) && position <= ll_length(list) - 1)
	{
		if(position == 0)
		{
			temp = list->head;
			if(ll_length(list) == 1)
				list->head = list->tail = NULL;
			else
				list->head = list->head->next;
		}
		else
		{
			prev = ll_address(list, position - 1);
			temp = prev->next;
			prev->next = prev->next->next;
			if(prev->next == NULL)
				list->tail = prev;
		}

		temp->data = 0;
		temp->next = NULL;
		free(temp);
		temp = NULL;
		list->length--;
	}
}

/* function to remove node if the node's data is given */

void ll_d_remove (ll *list, int data)
{
	int position;
	node *temp;

	if(list)
	{
		position = ll_position (list, data);
		if(position >= 0 && position < ll_length(list))
			ll_p_remove (list, position);
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

void ll_generate_random (ll *list, int length, int range)
{
	int i;

	if(list)
	{
		srand(time(NULL));

		for(i = 0; i < length; i++)
			ll_f_insert (list, rand() % range);
	}
}

/* function to destroy a linked list with a given reference to the list */

void ll_destroy (ll **ref)
{
	while(!ll_empty(*ref))
		ll_f_remove (*ref);

	free(*ref);
	*ref = NULL;
}
