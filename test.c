#include <stdio.h>
#include "linkedlist.h"

int main()
{
	int i;
	int a[] = {1, 50, 0, 6};
	ll *list = NULL, *rand_list = NULL;

	ll_create(&list);
	ll_create(&rand_list);

	printf("Before Insertion\nLength: %d\n", ll_length(list));
	ll_print(list);

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

	printf("Address function testing:\n");
	for(i = 0; i < ll_length(list); i++)
		printf("%d ", ll_address(list, i)->data);
	printf("\n");

	for(i = 0; i < 4; i++)
	{
		printf("Inserting at %d position\n", a[i]);
		ll_p_insert(list, a[i] + 20, a[i]);
		printf("Length: %d\n", ll_length(list));
		ll_print(list);
	}

	for(i = 0; i < 5; i++)
	{
		printf("Removing at position %d\n", i);
		ll_p_remove(list, i);
		printf("Length: %d\n", ll_length(list));
		ll_print(list);
	}

	ll_p_remove(list, list->length);
	printf("Length: %d\n", ll_length(list));
	ll_print(list);

	ll_generate_random (rand_list, 20, 75);
	printf("Random list below, length = %d\n", ll_length(rand_list));
	ll_print(rand_list);
	printf("Random list, reverse print\n");
	ll_reverse_print(rand_list);

	for(i = 0; i < 5; i++)
	{
		printf("Removing at position %d\n", i);
		ll_p_remove(list, i);
		printf("Length: %d\n", ll_length(list));
		ll_print(list);
	}

	ll_p_remove(list, ll_length(list));
	printf("Length: %d\n", ll_length(list));
	ll_print(list);

	ll_destroy (&list);
	ll_destroy (&rand_list);

	return 0;
}
