#include <string.h>
#include <stdio.h>
struct person
{
	char name[10];
	unsigned int age;
	float weight;
};

int main()
{
	struct person bob;
	bob.age=38;
	bob.weight=143.9f;
	strcpy(bob.name,"Robert");
	printf("Person: %s\n",bob.name);
	printf("   Age: %d\n",bob.age);
	printf("Weight: %3.1f\n",bob.weight);
	printf("-------------\n");
	return(0);
}
