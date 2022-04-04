#include <stdio.h>
/* quick funcion to test switch statement over all area codes in table work plus 666 (not in table) */
int foo(int i);

int main(){
    int numbers[] = {229,404,470,678,770,478,706,762,912,666};

    int i;
    for (i=0; i<10; i++){
        foo(numbers[i]);
    }
    return 0;
}

/* change back to main after check */
int foo(int i)
{
  /* Be sure to test your program for all area codes in the table */
  int area_code = i;

    /* Print the current area code with a tab
    Delete after validation */
    printf("%d\t", area_code);

    /* switch statement on area_code */
    switch(area_code){
        /* No dubplicates for Albany. No fallthroughs */
        case 229:
            printf("Albany\n");
            break;
        /* All fallthrough cases for Atlanta */
        case 404:
        case 470:
        case 678:
        case 770:
            printf("Atlanta\n");
            break;
        /* No dubplicates for Macon. No fallthroughs */
        case 478:
            printf("Macon\n");
            break;
        /* All fallthrough cases for Columbus */
        case 706:
        case 762:
            printf("Columbus\n");
            break;
        /* No dubplicates for Savannah. No fallthroughs */
        case 912:
            printf("Savannah\n");
            break;
        /* If no matches, print default error message */
        default:
        printf("Area code not found\n");
    }
  return 0;
}