#include <stdio.h>
#include <stdlib.h>

        struct list{
                int val;
                struct list *next;
        };

        void list_add(struct list **head,struct list *item)
                {
                        item->next=*head;
                        *head=item;
                }

        int main()
        {
                struct list *head;
                struct list *item;
                int i;
                head=NULL;
                for(i=1;i<4;i++) {
                        item=malloc(sizeof(*item));
                        item->val=i;

                        list_add(&head,item);
                        }

                for(item=head;item;item=item->next)
                printf("%d ",item->val);
        return(0);
        }
