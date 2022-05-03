#include <stdlib.h>
#include <stdio.h>

struct queue {
  int val;
  struct queue *next;
};


/* Write your enqueue() and dequeue() functions here */



/*****************************************************/


/* Note:
 *   EXIT_SUCCESS and EXIT_FAILURE
 *   are simply #defines in stdlib.h that you can use when returning from
 *   main() to indicate to the OS if the program exited cleanly or not.
 *   EXIT_SUCCESS is always 0.  The value of EXIT_FAILURE depends on your OS */
int main(int argc, char **argv)
{
  int i, num_items;
  struct queue *Q = NULL;
  struct queue *item;

  if (argc != 2) {
    printf("Usage: %s queue_size\n", argv[0]);
    return 0;
  }

  /* atoi() accepts a string containing an integer and returns an actual int */
  num_items = atoi(argv[1]);

  /* load the queue with a monotonically increasing sequence of integers */
  for (i=0; i<num_items; i++) {
    item = malloc(sizeof(*item));
    if (!item) {
      printf("Failed to malloc() item! Exiting...\n");
      return EXIT_FAILURE;
    }

    item->val = i;
    enqueue(&Q, item);
  }

  /* unload the queue and print the value of each item to the screen */
  while (item = dequeue(&Q)) {
    printf("%d\n", item->val);
    free(item);
  }

  return EXIT_SUCCESS;
}