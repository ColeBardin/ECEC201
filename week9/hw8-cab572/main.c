#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

#define to_person(ptr) \
	container_of(ptr, struct person, node)

struct person {
	char name[128];
	int age;
	int salary;
	int years;
	struct list node;
};


/* This function must do the following:
 * 1. Open the provided filename
 * 2. Return The NULL Pointer if filename could not be opened
 * 3. Allocate a new list head on the heap
 * 4. Populate the list with data from the file
 * 5. Return the head of the populated list	*/
struct list *load_database(const char *filename)
{
	FILE *fp; 
	
	struct list *head;
	struct person *item;
	
	/* Rewrite this function! */
	char name[128];
	int ret, age, sal, years;

	/* Attempt to open the file */	
	fp = fopen(filename, "r");
	if(!fp) {
		/* If fopen returns NULL ptr, error */
		fprintf(stderr, "Error: load_database() could not open file %s\n", filename);
		return NULL;
	}
	/* Allocate memory for head of the list */
	head = malloc(sizeof(*head));
	if(!head) {
		/* If allocation failed, error and close file */
		fprintf(stderr, "Error: load_database() could not allocate memory for list head\n");
		fclose(fp);
		return NULL;
	}
	/* Initialize the list with given head address */
	list_init(head);

	while ( 1 ) {
		/* Read one line from the file */
		ret = fscanf(fp, "%[^,], %d, %d, %d\n", name, &age, &sal, &years);
		/* Break if no items are scanned or EOF is hit */
		if (!ret || ret == EOF) {
			break;
		}
		/* Allocate memory for the data retrieved in the line */
		item = malloc(sizeof(*item));
		if(!item) {
			/* If allocation fails, close the file and error */
			fprintf(stderr, "Error: load_database() failed to allocate memory for entry item\n");
			fclose(fp);
			return NULL;
		}
		/* Copy data from CSV file into doubly linked list */
		strcpy(item->name, name);
		item->age = age;
		item->salary = sal;
		item->years = years;
		/* Add this list item's node to the list */
		list_add_after(head, &item->node);	
	}
	/* After EOF is hit, close file */
	fclose(fp);	
	/* Return head of list */
	return head;
}


/* This function must do the following:
 * 1. Remove all items from the provided list
 * 2. Free each removed item from the heap */
void unload_database(struct list *head)
{
	struct list *cur, *sav;
	struct person *item;
	
	/* Your code goes here! */
	/* If the head is not NULL */
	if (head) {
		/* Macro a safe for loop */
		list_safe_for (head, cur, sav) {
			/* Use to_person macro to get the struct person * for the current element */
			item = to_person(cur);
			/* Use list.h func to remove the item's node from the linked list */
			list_remove(&item->node);
			/* Free the memory at that location */
			free(item);
		}
	}
	return;
}


/* This function must do the following:
 * 1. Search the provided list for the item having the provided name
 * 2. Return the item if found
 * 3. Return The NULL Pointer if not found */
struct person *find_person(struct list *head, const char *name)
{
	struct list *cur; 
	struct person *item;
	
	/* Rewrite this function! */
	list_for (head, cur) {
		item = to_person(cur);
		if(!strcmp(item->name, name))
			return item;
	}
	return NULL;
}


/* This function prints the provided struct person to the screen */
void print_person(struct person *p)
{
	printf("Employee %s:\n", p->name);
	printf("   Age: %d\n", p->age);
	printf("Salary: $%0.2f\n", (float)p->salary / 100.0f);
	printf(" Years: %d\n", p->years);
}


int main(int argc, char **argv)
{
	struct list *head;
	struct person *item;
	
	if (argc != 2) {
	    fprintf(stderr, "Usage: %s employee_name\n", argv[0]);
	    return EXIT_FAILURE;
	}

	head = load_database("employees.csv");
	
	if (!head) {
	    fprintf(stderr, "Failed to open database.\n");
	    return EXIT_FAILURE;
	}

	item = find_person(head, argv[1]);
	if (item)
	    print_person(item);
	else
	    printf("Employee NOT FOUND!\n");
	
	unload_database(head);
	free(head);

	return 0;
}
