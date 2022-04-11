#include <stdio.h>
int main()
{
  int count=0;
  char ch;
printf("Enter a sentence terminated by .");
while(1)
  {
      scanf("%c",&ch);
      if((ch=='A')||(ch=='E')||(ch=='I')||(ch=='O')||(ch=='U'))
        count++;
 else if((ch=='a')||(ch=='e')||(ch=='i')||(ch=='o')||(ch=='u'))
        count++;
    //printf("No of vowels= %d\n",count);
    if(ch=='.') break;
  }
  
  printf("No of vowels= %d\n",count);
return(0);
  }
