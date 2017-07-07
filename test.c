#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

int main()
{
	int i, t;
	int a[] = {1, 50, 0, 6};
	ll *list = NULL, *rand_list = NULL;

	/* testing ll_create */
	ll_create(&list);
	ll_create(&rand_list);

	/* testing length and print functions on an empty list */
	printf("Before Insertion\nLength: %d\n", ll_length(list));
	ll_print(list);

	/* testing insert at beginning and end functions */
	for(i = 0; i < 10; i++)
	{
		if(i % 2)
		{
			ll_f_insert(list, i);
			printf("Length: %d\n", ll_length(list));
			ll_print(list);
		}
		else
		{
			ll_e_insert(list, i);
			printf("Length: %d\n", ll_length(list));
			ll_print(list);
		}
	}

	/* testing address function testing by traversing through the list and printing values at each address, compared with the print function above */
	printf("Address function testing:\n");
	for(i = 0; i < ll_length(list); i++)
		printf("%d ", ll_address(list, i)->data);
	printf("\n");

	/* testing inserting at nth position function */
	for(i = 0; i < 4; i++)
	{
		printf("Inserting at %d position\n", a[i]);
		ll_p_insert(list, a[i] + 20, a[i]);
		printf("Length: %d\n", ll_length(list));
		ll_print(list);
	}

	/* testing removal at n position (remove in front calls this function internallt) */
	for(i = 0; i < 5; i++)
	{
		printf("Removing at position %d\n", i);
		ll_p_remove(list, i);
		printf("Length: %d\n", ll_length(list));
		ll_print(list);
	}

	/* testing function to remove at end indirectly */
	ll_p_remove(list, list->length);
	printf("Length: %d\n", ll_length(list));
	ll_print(list);

	/* testing random list generator function */
	ll_generate_random (rand_list, 20, 10);
	printf("Random list below, length = %d\n", ll_length(rand_list));
	ll_print(rand_list);
	/* testing print list in reverse function */
	printf("Random list, reverse print\n");
	ll_reverse_print(rand_list);

	/* testing removing when data is given function */
	for(i = 0; i < 4; i++)
	{
		printf("Removing using data %d:\n", t = rand() % 20);
		ll_d_remove(rand_list, t);
		printf("Length: %d\n", ll_length(rand_list));
		ll_print(rand_list);
	}

	/* testing function to remove at given position again */
	for(i = 0; i < 5; i++)
	{
		printf("Removing at position %d\n", i);
		ll_p_remove(list, i);
		printf("Length: %d\n", ll_length(list));
		ll_print(list);
	}

	/* testing function to remove at give position for illegal cases (ll_length gives length of the list, list->length holds the position of the last node)*/
	ll_p_remove(list, ll_length(list));
	printf("Length: %d\n", ll_length(list));
	ll_print(list);

	/* testing linkedlist reverse function */
	printf("list\n");
	printf("Address before head: %p tail: %p\n", list->head, list->tail);
	ll_print(list);
	ll_reverse(list);
	printf("Address after head: %p tail: %p\n", list->head, list->tail);
	ll_print(list);

	printf("rand_list\n");
	printf("Address before head: %p tail: %p\n", rand_list->head, rand_list->tail);
	ll_print(rand_list);
	ll_reverse(rand_list);
	printf("Address after head: %p tail: %p\n", rand_list->head, rand_list->tail);
	ll_print(rand_list);

	/* testing 	linkedlist destroy function */
	ll_destroy (&list);
	ll_destroy (&rand_list);

	return 0;
}
