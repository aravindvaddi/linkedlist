#include <stdio.h>
#include "linkedlist.h"

int main()
{
	int i;
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

	return 0;
}
