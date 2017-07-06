#include <stdio.h>
#include "linkedlist.h"

int main()
{
	int i;
	int a[] = {1, 50, 0, 6};
	ll *list = NULL;

	ll_create(&list);

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

	return 0;
}
