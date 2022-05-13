#include <stdio.h>
#include <string.h>
struct person
{
	char name[10];
	unsigned int age;
	float weight;
};

void person_init(

	struct person *p,
	char * name,
	unsigned int age,
	float weight)
{
	p->age=age;
	p->weight=weight;
	strcpy(p->name,name);
}

int main()
{
	struct person bob;
	person_init(&bob,"Robert",38,143.9f);
	printf("Person: %s\n",bob.name);
	printf("   Age: %d\n",bob.age);
	printf("Weight: %3.1f\n", bob.weight);
	return(0);
}
