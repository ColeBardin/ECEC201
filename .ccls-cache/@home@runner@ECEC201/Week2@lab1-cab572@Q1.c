#include <stdio.h>

int main()
{
  /* Be sure to test your program for all area codes in the table */
  int area_code = 229;

    switch(area_code){
        case 229:
            printf("Albany\n");
            break;
        case 404:
            printf("Atlanta\n");
            break;
        case 470:
            printf("Atlanta\n");
            break;
        case 478:
            printf("Macon\n");
            break;
        case 678:
            printf("Atlanta\n");
            break;
        case 706:
            printf("Columbus\n");
            break;
        case 762:
            printf("Columbus\n");
            break;
        case 770:
            printf("Atlanta\n");
            break;
        case 912:
            printf("Savannah\n");
            break;
        default:
        printf("Area code not found\n");
        
    }
    
  return 0;
}