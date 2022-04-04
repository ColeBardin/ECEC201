#include <stdio.h>

int foo(int i);

int main(){
    int numbers[] = {229,404,470,678,770,478,706,762,912,666};

    int i;
    for (i=0; i<10; i++){
        foo(numbers[i]);
    }
    return 0;
}


int foo(int i)
{
  /* Be sure to test your program for all area codes in the table */
  int area_code = i;
    
    printf("%d\t", area_code);
    switch(area_code){
        case 229:
            printf("Albany\n");
            break;
        case 404:
        case 470:
        case 678:
        case 770:
            printf("Atlanta\n");
            break;
        case 478:
            printf("Macon\n");
            break;
        case 706:
        case 762:
            printf("Columbus\n");
            break;
        case 912:
            printf("Savannah\n");
            break;
        default:
        printf("Area code not found\n");
    }
    
  return 0;
}