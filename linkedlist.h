#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node
{
	int data;
	struct node *next;
};

struct linkedlist
{
	struct node *head;
	struct node *tail;
};

typedef struct node node;
typedef struct linkedlist ll;

/* linketlist helper functions */

node *ll_search (ll *list, int data);
node *ll_address (ll *list, int position);
node *ll_node (int data);

void ll_print (ll *list);
void ll_r_print(ll *list);
void ll_reverse (ll *list);
void ll_r_reverse (ll *list);
void ll_reverse_print (ll *list);

/* linkedlist core */

void ll_f_insert (ll *list, int data);
void ll_e_insert (ll *list, int data);
void ll_p_insert (ll *list, int data, int postition);

void ll_f_remove (ll *list);
void ll_e_remove (ll *list);
void ll_p_remove (ll *list, int position);
void ll_d_remove (ll *list, int data);

int ll_length (ll *list);

/* linkedlist creation and destruction */

void ll_create (ll **ref);
void ll_destroy (ll **ref);
void ll_generate_random (ll **ref, int length, int range);

endif
