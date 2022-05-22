#define list_for(head, cur)		\
for (cur=head->next; cur!=head; cur=cur->next)

#define list_safe_for(head, cur, sav)	\
for (cur=head->next, sav=cur->next;		\
	cur!=head;							\
	cur=sav, sav=cur->next)


struct list {
	int val; /* Change data type as needed */
	struct list *next;
	struct list *prev;
};

void list_init(struct list *head);

void list_add_after(struct list *cur, struct list *new);

void list_add_before(struct list *cur, struct list *new);

void list_remove(struct list *cur);
