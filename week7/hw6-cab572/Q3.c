/* Homework 6: Question 3
	 Compile with: gcc -std=c89 -Wall -Wpedantic -Werror -fno-common -o Q3 Q3.c
	 Then run your compiled program with: ./Q3
*/
#include <stdlib.h>
#include <stdio.h>

struct list {
	int val;
	struct list *next;
};

/* from Lecture 6 */
void list_add_head(struct list **head, struct list *item)
{
	item->next = *head;
	*head = item;
}

/* from Lecture 6 (just for your reference) */
struct list *list_pop_head(struct list **head)
{
	struct list *cur;

	cur = *head;
	if (cur) {
		*head = cur->next;
		cur->next = NULL;
	}

	return cur;
}

/* you write this one! */
int list_count(struct list *head)
{
	/* rewrite this function! */
	int i=0;
	struct list *item;
	/* Repeat until current item points to NULL, incrementing i each step */
	for (item = head; item; item = item->next, i++);
	/* Free temp struct instance */
	free(item);	
	return i;
}

/* you write this one! */
struct list *list_pop_tail(struct list **head)
{
	/* rewrite this function! */
	struct list *item;
	struct list *del;
	/* If the Head is Null or the Head points to NULL */
	if ( (!*head) || (!(*head)->next) ) {
		/* Set Head to NULL and return it */
		*head = NULL;
		return *head;
	}
	/* Iterate until item is second to last item */
	for (item = *head; (item->next)->next; item = item->next);
	/* Save the last item in del instance */
	del = item->next;
	/* Point second to last item to NULL */
	item->next = NULL;
	return del;
}


int main()
{
	int i;
	struct list *item;
	struct list *head = NULL;

	/* load up the list with ten items */
	for (i=0; i<10; i++) {
		item = malloc(sizeof(*item));
		item->val = i;
		list_add_head(&head, item);
		printf("Added %p (val: %d) to list.\n", (void *)item, item->val); 
		/* Cast item to void pointer get rid of undefined behavior from sample code */
	}

	printf("# of items: %d\n", list_count(head));

	/* remove each item and print its value */
	while ( (item = list_pop_tail(&head)) ) { /* Fixed erroneous code by putting assignment in paranthesis */
		printf("Removed %p (val: %d)\n", (void *)item, item->val);
		/* Cast item to void pointer get rid of undefined behavior from sample code */
		free(item);
	}

	return 0;
}
