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
	for (item = head; item; item = item->next, i++);
	free(item);	
	return i;
}

/* you write this one! */
struct list *list_pop_tail(struct list **head)
{
	/* rewrite this function! */
	struct list *item;
	struct list *del;
	if ( (!*head) || (!(*head)->next) ) {
		*head = NULL;
		return NULL;
	}
	for (item = *head; (item->next)->next; item = item->next);
	del = item->next;
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
		printf("Added %p (val: %d) to list.\n", item, item->val);
	}

	printf("# of items: %d\n", list_count(head));

	/* remove each item and print its value */
	while (item = list_pop_tail(&head)) {
		printf("Removed %p (val: %d)\n", item, item->val);
		free(item);
	}

	return 0;
}
