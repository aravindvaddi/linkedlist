#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <linkedlist.h>

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
