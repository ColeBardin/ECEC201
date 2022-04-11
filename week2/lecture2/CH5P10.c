#include <stdio.h>
        int main()
        {
                int numeric_grade;
                unsigned int x;
                char letter_grade;
          while(1)
            {
                printf("\nEnter Numeric Grade: ");
                scanf("%d",&numeric_grade);
                if((numeric_grade>100)||(numeric_grade<0))
              {
                printf("\nInvalid Numeric Grade");
                  break;
              }
                x=numeric_grade/10;
                if(x>=9)  letter_grade='A';
                else if(x>=8) letter_grade='B';
                else if(x>=7) letter_grade='C';
                else if(x>=6) letter_grade='D';
                else letter_grade='F';
                printf("\nLetter Grade=%c  ",letter_grade);
              }
                return(0);
        }
// while(1) loop allows the user to enter a series of numeric grades until an invalid numeric grade enters when the code exits
