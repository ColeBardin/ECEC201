C/C++ Notes

Data types:
int - integer - 2 or 4 bytes
float - floating point - 4 bytes
double - double floating point - 8 bytes
char - character - 1 byte
wchar_t - wide character - 2 bytes
bool - boolean - 1 byte
void - empty - 0 bytes

char test = 'h'
wchar_t test = L'ם' // storing hebrew character since it takes more memory
	//use 'L' to specify to compiler that its a wide char

void indicates absense of data

Type modifiers
4 type modifiers:
	signed
	unsigned
	short
	long
all can apply to:
	int
	double
	char


size_t in C99:
	Largest number than system can count to!

signed int - 4 bytes - used for integers (equivalent to int)
unsigned int - 4 bytes - can only store positive integers
short - 2 bytes - used for small integers (-32768 to 32767)
unsigned short - 2 bytes - used for small positive ints (0 to 65535)
long - at least 4 bytes - used for long its (equal to long int)
unsigned long - 4 bytes - used for large pos ints or 0 (equal to unsigned long int)
long long - 8 bytes - used for very large ints (equal to long long int)
unsigned long long - 8 bytes - used for bery large pos ints or 0 (equal to unsigned long long int)
long double - 12 bytes - used for large floating point numbers
signed char - 1 byte - used for characters (guaranteed range -127 to 127)
unsigned char - 1 byte - used for chars (range 0 to 255)

Float and Double:
used for decimal and exponential values
// creating float type variables
float num1 = 3.0f;
float num2 = 3.5f;
float num3 = 3E-5f; // 3x10^-5

// creating double type variables
double num4 = 3.0;
double num5 = 3.5;
double num6 = 3E-5; // 3x10^-5

must add 'f' and the end of float values because compilers will assume its a double

float: 4 bytes, 7 decimal digit precision
double: 8 bytes, 15 decimal digit precision

Specify decimal points with setprecision():
...
int main() {
	double a = 3.912348239293;
	float b = 3.912348239293f;

	cout << setprecision(13); // sets to 13 digits

	cout << "Double type numner = " << a << endl;
	cout << "Float type number = " << b << endl;

	return 0;
}

This outputs:
Double Type Number  = 3.912348239293
Float Type Number   = 3.912348270416

Specific precision:
int main() {
	...
	cout << "Double type number = " << setprecision(11) << a << endl;
	cout << "Float type number = " << setprecision(7) << b << endl;

	return 0;
}

Format specifier for exponential numbers:

double ex = 325E25;
double num = 3.25;

cout << scientific << num;
cout << scientific << ex;

additional specifier:
fixed : same as default


Long double:
long double num_ldb = 2.569L
//L so compiler knows its a 'long double'
//no 'long float'

acros:
piece of code which is given some name
#define directive is used to define a macro

//macro def
#define LIMIT 5
int main() {
	for (int i = 0; i < LIMIT; i++) {
		std::cout<<i<<"\n";
	}
	return 0;
}
LIMIT (macro def) is replaced with 5 (macro expansion) by compiler

acros with arguments
// macro with parameter
#define AREA(l,w) (l*w)
//(l,w) are params, (l*w) is replacement statement/expansion
int main() {
	int l1 = 10, l2 = 5, area;
	area = AREA(l1, l2);
	std::cout<<"Area of a rectangle is: "<<area;
	return 0;
}

File inclusion in Macros
	type of directive tells compiler to include a file in source code program
	two types:
1. Header file or standard files:
	contain definion of pre-defined funcs like printf() scanf()
	i/o functions are in 'iostream'
	SYNTAX: #include<file_name>;
		#include<iostream>;
2. Userdefined files:
	SYNTAX: #include"filename"
Conditional compilation:
	choose to compile or skip specific portions of program
	ifdef and endif
SYNTAX:
#ifdef macro_name
	statement1;
	statement2;
	statement3;
	...etc
#endif

Constant:
const int var = 5;
keyword, data type, name of variable, initial value

or use #define directive
#define indentifierName value

Storage classes:
describe the features of a var/func
SYNTAX: storage_class var_data_type var_name;

5 storage classes:
1. auto		function block	local	garbage
2. register	function block	local	garbage	
3. extern	whole program	global	zero
4. static	whole program	local	zero
5. mutable	class		local	garbage

Auto: will decide data type for your variable
	auto a = 3.2; // chooses float
	auto b = 32; // chooses int
Extern: var is defined somewhere else not within the same block its used
	using this storage class says we are not defining a new var but just accessing a global var that already exists
	and to use that global value
Static: hold value even after theyre out of scope. local to wherever theyre defined
	or can be global. no new memory allocated every time it is referenced
	define static count = 0; inside counting func so count doesnt have to be global
Register: same as auto except compiler tries to store var in microprocessor if a free register is available
	faster use of register variables during runtime than memory ones
	usually a few var to be stored this way that will be used a LOT
	note: cannot obtain address of register vars using pointers
utable: allows for data members in 'const' class/structs to be modified without updating other members
	class Test {
	public:
		int x;
		mutable int y; //allows for change of var y if instance is const
		Test(){x=4;y=10;}
	};
	int main(){
		const Test t1; // constant instance t1 of class Test
		t1.y = 20; // valid since data member 'y' is 'mutable'
		t1.x = 10; // will throw error codes
		return 0;
	}


PRINTING AND SCANNING:
#include <stdio.h>
included in standard in out header
printf();
scanf();

Format specifiers: %
%c	Character
%d	Signed integer
%e	Scientific notation of floats
%E	Scientific notation of floats
%f	Float values
%g	Similar as %e or %E
%G	Similar as %e or %E
%hi	Signed integer (short)
%hu	Unsigned Integer (short)
%i	Unsigned integer
%l	Long Int
%ld	Long Int
%li	Long Int
%lf	Double
%Lf	Long double
%lu	Unsigned int or unsigned long
%lli	Long long
%lld	Long long
%llu	Unsigned long long
%o	Octal representation
%p	Pointer
%s	String
%u	Unsigned int
%x	Hexadecimal representation
%X	Hexadecimal representation
%n	Prints nothing
%zu 	size_t length, can be printed with %d but proper way is to use %zu
%%	Prints % character

print 5 digits of int:
printf("text %5d\n"); // Pads with spaces

to pad with zeroes or other character
printf("text %05d");

printing floats with precision:
printf("foo: %.2\n"); // Shows 2 decimal places

Scanning from keyboard:
int a;
float b;
scanf("%d,%f", &a, &b); // Scanf needs '&' for variables. Only takes address
// & gives memory address to variables passed to scanf





Pointers:
variables that store addresses of other variables
multi byte data type
holds 64 bit address, 8 bytes

Special operators:
& //address of operator (what is the MEMORY ADDRESS of this variable)
* //dereference operator (what is IN memory at the address stored at this pointer)

char foo;
char *foo_ptr; //var that stores add of vars of type char
foo = 5;
foo_ptr = &foo; // address of foo
/* printf:
foo (%d): 5
foo_ptr (%p): 0x7ffe1749af07 // hex address of foo
&foo_ptr (%p): 0x7ffe1749af08 // starting address of foo_ptr
*foo_ptr (%d): 5
*/


Do not EVER return pointers to local variables in a function!!
use keyword STATIC to have variables in functions not be marked as invalid after returning
AUTO variables live in stack frame
STATIC variables live in read/write DATA SEGMENT

char *foo(){
	static char fun[] = "my string";
	return fun; /* Needs keyword STATIC on var to be able to return this */
}
int main(){
	printf("%s",fun());

	char *foo = fun();
	foo[0] = 'M'; /* allowed since STATIC vars live in RW part of DATA SEG */
	return0;
}
After foo stack frame is invalidated, String Literal of fun is still stored in DATA SEG


Array Pointers:

int* func(*arr, n){ /* Use of deref op on array var. arrays are passed as pointers by default */
	arr[0] = 1 /* No need for deref operator here */
	/*
	&arr = address of 0th element of arr
	&arr + n = address of nth element of arr
	can be seen in scope of main
	*/
	return &arr + n -1; /* address of last element of arr since len of arr is n */
}

int main() {

	int n = 5;
	int arr[n];

	func(arr, n) /* no need for & operator when passing array */
	return 0;
}

arr[n] syntax is same as *(arr + n)
since array names ARE addresses


Function pointers:
TODO: documen func *



Strings:
char my_arr = {'h', 'e', 'l', 'l', 'o'};
Array of chars^

But can be a string with null char
char my_str = {'h', 'e', 'l', 'l', 'o', '\0'};
adding Null char \0 to end of array makes it a string

printf("%s", my_str);
will start at &my_str will increment in memory until a \0 is reached
If no \0 char is found it will keep printing memory! (undefined)


Or can initialize string with better syntax:
char my_str[] = "Hello"; /* String Literal, adds null char */
ALWAYS READ ONLY, IMMUTABLE
String Literal gets copied to READ ONLY part in memory
and it gets copied to stack frame when arr is initialized


You can get the address of the READ ONLY string literal:
char *foo = "My string";
*foo[0] = 'M' is NOT ALLOWED, it will compile but theres a SEG FAULT
this is IMMUTABLE
because string literals are addresses


but array my_str is mutable!
Indices of the my_str array can used to edit memory that it spans


String literal addresses are READ ONLY so
char *foo(){
	return "Literal";
}
int main(){
	printf("%s",foo());
	return 0;
}
Is a valid program since foo returns char*

Strings can only be set on initialization:
char fun[5]; /* add 1 to length for \0 */
fun = "fun!"; /* IS NOT ALLOWED */

Proper way:
char fun[5]; /* destination array must be long enough to store literal. ADD ONE FOR NULL CHAR */
int i=0;
while( (fun[i]="Fun!"[i]) != '\0')
	i++;
/* assignment returns value of what is being assigned -> copies chars over until "Fun!"[i] is the nul char */

Better func for this: 
#include <string.h>
char  *strcpy(char *dst, char *src) {
	char *p = dst;
	while  ((*dst++ = *scr) != '\0\)
	return *p; /* allowed since the addresse stored at p is in main stack frame! */
}

calling:
char fun[5];
strcpy(fun, "Fun!");


CONST keyword:
const int foo = 10;
/* Only sets value of foo when initialized
Compiler will throw error if assignment after initialization is attempted */

not really useful tho

but mainly used for func parameters

void func(const char *str){ /* Same as 'char const *str' */
/* CONST means values stored at str address is IMMUTABLE! */
	str[2] = 'X'; /* will throw error since the chars pointed to are constant */

	/* But str addres can be changed */
	str = "Some new string";
	return;
}

const char *str = char const *str != char * const str
char * const str means str address is UNCHANGEABLE but chars ARE

const char * char str makes both UNCHANGEABLE

Including const in func declarations allow for funcs to only read the data pointed to by a pointer
const char *str

char *strcat(char *dst, const char *src); /* Concatenates src to dst */
size_t strlen(const char *s); /* Returns length of string */
	sizeof() would return entire length of char array, including null char and extra bits

int strcmp(const char *s1, const char *s2); /* Returns 0 when strings match! or returns difference in ASCII of first different chars */

adding 'n' between str funcs:
strncmp includes int param n that will perform func until \0 or n is reached

adding 'r' between str funcs:
strrcmp includes int param n that will perform func in reverse




Structures:
Stores variable of different types

definition:

struct person {
	char name[10];
	unsigned int age;
	float weight;
	/* names of members are local to structs */
}; /* Inlcudes ; */

int main(){
	struct person bob; /* struct tags 'person' lives in its own namespace, will not collide with vars and func names */
	
	bob.age = 38; /* . operator to access members after initialization */
	strcpy(bob.name, "Bob"); /* Must use strcpy to set strings after initialization */

	struct person cole = {"Cole", 20, 150.5f}; /* members can be set on initialization of struct entry */ 
	/* Order of members MUST match if initialized like this */
	return 0;
}

How are struct members stored in memory?
&bob = &name
Address of entry points to first member of struct like arrays
embers are offset in memory by the size of the data type of the member

Functions that initialize structs:
void person_init(struct person *p, char *name, unsigned int name, float weight){
	(*p).age = age;
	(*p).weight = weight;
	strcpyu((*p)).name, name);
}

call:
struct person bob;
person_init(&bob, "Robert" 38, 143.9f);
Good funtion to include with struct header files

OR WITH ARROW OPERATOR:
p->member is SHORTHAND FOR (*p).member
p is address of structure entry

p->age = age;
p->weight = weight;
strcpy(p->name, name);



3 Dereferencing Operators:
Dereference: *ptr
Array index: arr[index]				*(array + index)
Arrow operator: structptr->memebr	(*structptr).member





DYNAMIC MEMORY MANAGEMENT
malloc() free() realloc()
unlike Static keyword that puts it in data seg

dynamic memory is stored in HEAP
size of memory is needed at Runtime not compile time!
memory is allowcated when specified

UST #include <stdlib.h>
defines:
void *malloc(size_t size); /* no size_t in c89, it is unsigned long */
void free(void *ptr);

malloc returns address of first byte in HEAP of allocation

First create pointer for type you want to use since malloc retuns void *
example:
char *char_ptr; /* Create char * variable first */
char_ptr = malloc(10); /* Save return val of malloc to char * */

type of dest pointer defines pointer arithmetic

short *foo'
foo = malloc(6*sizeof(short));

needs 2 changes to convert foo arr to ints
fix:
int *foo;
foo = malloc(6*sizeof(*foo)); /* get the size of what foo poitns to. More dynamic and easier to change */

malloc can be used for any type
even structs
example:
struct stuff {
	int val
	char key;
	float pi;
};

int main(){
	struct stuff *foo;
	foo = malloc(sizeof(*foo)); /* mallocs enough memory to store ONE of whatever foo is */
}


free(address)

only free once, no DOUBLE freeing, runtime will throw errors

int *foo;
foo = malloc(sizeof(*foo));
free(foo);

NULL ptr gets returned when Malloc cannot allocate enough memory
UST CHECK AFTER MALLOC FOR NULL PTR!!!
#include <stdlib.h>
int *foo;
foo = malloc(sizeof(*foo));
if (foo == NULL) /* or if(!foo) since NULL is 0 */
	return EXIT_FAILURE;


DEF OF NULL
#define NULL ((void *)0)

EMORY LEAKS OCCUR when free is not used






LINKED LISTS
Kind of Array that can grow and shrink
List of elements
NOT ARRAY: block of elements w/ hard indices

can be used for not immediately known length arrays
allocates memory as it runs

HOW TO IMPLEMENT
create struct:
struct list {
	int val;
	struct list *next; /* POINTER TO ANOTHER STRUCT LIST */
};
CREATES CHAINS OF LIST STRUCTS
format:
head -> 3 -> 2 -> 1 -> NULL (tail)

KEEP TRACK OF HEAD. it is the 'list'
TAIL points to NULL to indicate end

USAGE
struct list {
	int val;
	struct *next;
};

/* LIST ADD FUNC */
void list_add(struct list **head, struct list *item){
	/* Make ITEM point to what head was pointing to */
	item->next=*head;

	/* Point HEAD to ITEM */
	*head = item;
}

int main() {
	struct list *head; /* CREATE FIRST STRUCT */
	struct list *item;

	head = NULL; /* MAKE EMPTY LIST. VAL HERE CHANGES */
	/* ADDR OF HEAD STAYS THE SAME, VALUE AT HEAD CHANGES */

	item = malloc(sizeof(*item));
	item->val = 1; /* SET VAL OF ITEM */
	
	/* NOW ADD TO LIST */
	/* HEAD is DOUBLE POINTER, ADDRESS TO ADDRESS OF HEAD */
	list_add(&head, item); /* USE FUNC TO ADD TO LIST */
	/* &head is anchor of list */
	/* HEAD currently points to NULL list_add points it */
}	


how to ITERATE through linked lists:
struct list {
	int val;
	struct list *next;
};

int main(){
	struct list *head;
	struct list *item;
	int i;

	for (item = head; item; item = item->next)
		printf("%d ",item->val);
}



LIST POP HEAD FUNC
struct list {
	int val;
	struct list *next;
};

struct list *list_pop_head(struct list **head){
	struct list *cur /* temp var for current */
	/* COPY HEAD ELEMENT */
	cur = *head;
	if (cur) { /* IF IT IS NOT NULL */
		*head = cur->next; /* POINT HEAD TO NEXT ELEMENT */
		cur-nexx = NULL; /* SEVER OLD ELEMENT FROM LIST */
	}
	return cur;
}

int main(){
	struct list *head;
	struct lsit *item;
	int i;

	/* INDIVIDUAL ITEM */
	item = list_pop_head(&head);
	free(item);

	/* IN LOOP */	
	while (item = list_pop_head(&head)){
		printf("%d\n", item->val);
		free(item);
	}
} 




DOUBLY LINKED LISTS:
more complex but easier to work with

struct d_list {
	int val;
	struct d_list *next;
	struct d_list *prev;
};

containes next and previous item in list
they are circularly linked, no NULL terminator tail

stop circulating when you reach the HEAD again
can be linear but not very useful, so make them circular

HEAD -> 1 next-> 2 next -> 3 next -> HEAD
HEAD <- prev 1 <- prev 2 <- prev 2 <- HEAD

HOW TO WORK WITH DOUBLY LINKED LISTS
#include <stdlib.h>
struct list {
	int val;
	struct list *next;
	struct list *prev;
};
void list_init(struct list *head) {
	head->next = head;
	head->prev = head;
	/* Empty doubly linked lists start with head pointing to intself in both directions 
	HEAD <- HEAD -> HEAD */
}
void add_after(struct list *cur, struct list *new) {
	/* Part 1: edit new item pointers to link it to list */
	new->next = cur->next; /* Make new item point to cur's next item */
	new->prev = cur; /* Make new item point back to cur item */
	/* Part 2: edit current list items to link it around the new item */
	cur->next->prev = new; /* Make item after cur points backwards to new item */
	cur->next = new; /* Make cur point forwards to new item */
}
void add_before(struct list *cur, struct list *new) {
	/* Part 1: edit new item pointers to link it in the list */
	new->next = cur; /* Point new item to current item */
	new->prev = cur->prev; /* Make new item point backwards to whatever cur was pointing backwards to */
	/* Part 2: edit current list items to link it around the new item */
	cur->prev->next = new; /* Make item behind cur to point forward to new item */
	cur->prev = new; /* Make cur item point backwards to new item */
}
void list_remove(struct list *cur) {
	cur->prev->next = cur->next; /* Make item behind cur point to item after cur */
	cur->next->prev = cur->prev; /* Make item after cur point to item behind cur */
	/* Detach current item internally */
	cur->next = NULL;
	cur->prev = NULL;
}
int main() {
	int i;
	struct list *item, *cur, *next;
	struct list head = malloc(sizeof(*head)); /* Or it can live on main stack frame with no malloc call */
	list_init(&head); /* Init empty doubly linked list */	
	
	for (i=0; i<2; i++) {
		item = malloc(sizeof(*item));
		item->val = i;
		add_after(head, item); /* Add item after HEAD */
		/* Current structure: HEAD next -> 2 next-> 1 next-> HEAD and prev going in opposite dir */
	}
	/* Iterate through doubly linked lists */
	for (cur=head->next; cur!=head; cur=cur->next) { /* Iterate until we reach the head again, can be done with prev as well. Leaves cur equal to head */
		printf("%d\n", cur->val); /* Statements with cur list element */
		/* Arbitray insertion */
		if (cur->val == 2) { /* If current item has value of 2 */
			item = malloc(sizeof(*item));
			item->val = 37;
			add_after(cur, item); /* Add a newly allocated item with val of 37 after it */
			break;
		}	
	}
	/* Add item before */
	item = malloc(sizeof(*item));
	item->val = 97;
	add_before(head, item);
	/* Current order: HEAD next-> 2 next-> 37 next-> 1 next-> 97 next-> HEAD */
	/* Removing an item */
	for (cur=head->next; cur!=head; cur=cur->next) {
	/* Iterate until cur is the item with val of 37 */
		if (cur->val == 37)
			break;
	}
	/* Now remove cur */
	list_remove(cur);
	/* Free it if you're done with it */
	free(cur);
	/* ITEM REMOVAL IN LOOP (BE CAREFUL) there's a reason why we broke out of the loop BEFORE removing the item  */
	/* If there is no BREAK after finding the correct item, the loop cannot find the next item. cur is INVALID or next/prev are NULL. Gives SEG FAULT */
	for (cur=head->next, next=cur->next; cur!=head; cur=next, next=cur->next) { /* Edit initializer and iterater options for the loop to save cur next BEFORE removing it */
		/* After each iteration update NEXT variable to cur->next so when we free(cur), the loop can continue */
		list_remove(cur);
		printf("Removed %d\n", cur->val);
		free(cur);
	}
	return 0;
}	

MACRO for list ITERATION
/* Macro for SAFE list iteration that saves the next address so items can be removed */
#define list_safe_for(head, cur, sav)	\
for (cur=head->next, sav=cur->next;		\
	cur!=head;							\
	cur=sav, sav=cur->next)				\

/* Macro for normal loop iteration that doesn't need to be extra safe (NO REMOVING IN LOOP) */
#define list_for(head, cur) 	\
for (cur=head->next; cur!=head; cur=cur->next)
int main() {
	int i;
	struct list *item, *cur, *next;
	struct list *head = malloc(sizeof(*head));
	list_init(head);
	/* ADD ARBITRARY ITEMS TO LIST ... */
	list_for (head, cur) {
		printf("Val = %d\n", cur->next);
	}
	list_safe_for (head, cur, next) {
		list_remove(cur);
		printf("Removed %d\n", cur->val);
		free(cur);
	}
	return 0;
}



USING LIST_API for GENERIC LISTS (GENERIC DOUBLY LINKED LISTS)
#include "list.h"
there's no specified value for each list element. therefore in each program it should be specified:

main.c:
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

#define to_ints(ptr)	\
	container_of(ptr, struct ints, node)

struct ints {
	int val; /* Add custom datatype value variable */
	struct list node; /* Embed of type struct list from list.h */
};
int main(int argc, char **argv) {
	int i;
	struct ints *item;
	struct list *head, *cur, *sav;

	head = malloc(sizeof(*head));
	list_init(head);

	for (i=0; i<argc; i++) {
		item = malloc(sizeof(*item));
		item->val = atoi(argv[i]);
		list_add_before(head, &item->node); /* Use address of embedded NODE (of type struct list) of this item */
	}
	list_for (head, cur) {
		/* now here comes the cool stuff */
		item = to_ints(cur); /* Can be hand written with container_of call but its good to macro it if used a lot */
		printf("%d\n", item->val);
	}
	list_safe_for (head, cur, sav) {
		item = to_ints(cur);
		printf("%d\n", item->val);
		list_remove(&item->node); /* REMOVE NODE */
		free(item); /* FREE ITEM */
	}
	free(head);
	return 0;
}


Generic doubly linked lists can contain:
multiple members of any data type
multiple nodes to different lists!! very powerful











CREATING NEW NAMES FOR EXISTING TYPES
typedef

#include <stdlib.h>

struct person {
	char name[100];
	int age;
};

typedef struct person Person; /* Create typedef for struct person that is called Person */
/* Person shorthand for struct person */

int main() {
	Person bob;
	strcpy(bob.name, "Bob");
	bob.age = 20;
}
/* Don't over typedef */






#define With parameters

#define count(idx, num) for(idx=0; idx<num; idx++)

int main(){
	int i;
	count(i, 10) { /* Places for loop statement here with the parameters */
		printf("%d\n", i);
	}
	return 0;
}

if you need a mutliline #define, you must escape the newline char with \ :
#define count(idx, num) \
	for (idx=0; idx<num; idx++)





OFFSETOF Macro:
comes with compilers
gets the byte offset of a struct member
size_t offsetof(struct, struct *member) /* receieves type */
age_offset = offsetof(struct person, age);

offsetof included in:
#include <stddef.h>


CONTAINER_OF Macro
not included with compiler, must be made by hand
computes address of struct with just address of members

How CONTAINER_OF() works:
to avoid issues with pointer arithmetic:
bob_ptr = (struct person *)((char *)age_ptr - offsetof(struct person, age)); /* Explicit cast to char ptr so +-1 is actually one byte */
/* Then cast entire difference back to correct struct ptr so it can be stored into correct ptr variable type */

Now in macro form:
#define container_of(_mptr, type, member) \
(type *)( (char *)_mptr - offsetof(type, member) )

#include <stddef.h>
int main() {
	
	struct person *bob_ptr;
	bob_ptr = container_of(age_ptr, struct person, age);
	return 0;
}





FILE HANDLING:
on UNIX systems, GUIs need to ask to OS for help to open files
C STDLIB helps manage interfacing with OS specific file shit
stdin, stdout, stderr are considered 'files' abstracted from program 
they are BUFFERED FILESTREAMS


all file functions begin with 'f' for FILE

#include <stdlib.c>
FILE *fopen(char *fpath, const char *mode);
	adds file to OS filedescriptor
	adds filestream to HEAP
fp = fopen("doc.txt", "w+");

FILE * file pointer
Holds address of filesream in HEAP
DO NOT DEREFERENCE!
pass it to libc with various functions
holds position in file as well

ex:
fprintf(fp, "Hello World\n");
/* Just like printf but takes filestream F* arg */

printf("Hello World") = fprintf(stdout, "Hello World") /* Printf sends it to stdout 'file' */


OPENING FILES:
FILE *fopen(char *pathname, const char *mode);
RETURNS NULL PTR on fail (persmissions, invalid name)
	ERROR HANDLE fopen calls


CLOSING FILES
int fclose(FILE *fp);
RETURNS Status
0 - success
EOF - 

#include <stdlib.h>
int main() {
	FILE *fp;
	fp = fopen("passwords.txt", "w+");
	if (fp == NULL) {
		printf("%s", errno);
		return -1;
	}
	fprintf(fp, "sDW&D&7dt");
	if (fclose(fp) != 0) 
		return -1;
	return 0;
}


Plaintext modes:
"r" - Reading, positions stream at beginning of file, fails if file doesn't exist
"r+" - Read PLUS Write, positions steam at beginning of file, fails if file doesn't exist

"w" - Writing, positions stream at beginning of file, creates file if it doesn't exist, erases conents of previous file
"w+" - Writing PLUS Read, positions stream at beginning of buffer, creates file if needed, erases contents of previous file

"a" - Append, Writing, positions stream at end of file
"a+" - Append, Writing AND Reading, stream at end of file, 

FOR BINARY FILES:
Same behavior as plaintext files but add "b" to end of mode:
"rb"
"r+b"
"wb"
"w+b"
"ab"
"a+b"

Difference between Binary and Plain filemodes:
UNIX uses only \n chars for newlines
DOS/Windows uses \r\n for newlines
C automatically converts 2 byte newline characters on Windows 1 byte


FGETC and FPUTC
int fgetc(FILE *fp); /* Returns ASCII->Binary of char at current fileposition and advances position by 1 */
/* EOF isn't a char, it's a number: -1 */
get all chars from file:
#include <stdlib.h>
#include <stdio.h>
int main(){
	int c;
	FILE *fp;
	if ( (fp = fopen("doc.txt", "r") != NULL );
	while ( (c = fgetc(fp)) != EOF )
		printf("%c",c);
	fclose(fp);
	return 0;
}

int fputc(const char *c, FILE *fp); /* Writes current char c at current fileposition in filepointer fp */
/* Overwrites whatever is at current fileposition for fp */
fputc can EXTEND end of file if called when fileposition is at EOF


MOVING AROUND FILES:
int fseek(FILE *fp, long int offset, int whence); /* Seeks to WHENCE + OFFSET */
WHENCE options:
SEEK_SET /* Start of file */
SEEK_END /* End of file */
SEEK_CUR /* Current position */

Textfiles limites what offset can be
Binary can be anything

For textfiles, offset can only be 0 or a val returned from ftell

long int ftell(FILE *fp) /* returns byte offset from start of file of fp */

long int sav;
sav = ftell(fp); /* Save current file position */
fseek(fp, 0, SEEK_END); /* Go to end of file */
fputc('!', fp); /* Put '!' at end of file */
fseek(fp, sav, SEEK_SET); /* Go to previously saved position */
fputc(' ', fp); /* Write ' ' to previous position in file */


REWIND func
void rewind(fp)
is EQUAL to:
fseek(fp, 0, SEEK_SET);
/* Shorthand to reset file position to beginning of file */



String Placement:
char *fgets(char buffer, long int buffer_size, FILE *fp)
Reads from file until NEWLINE CHAR OR after filling Buffer size
	will automatically null terminate buffer even if it runs out of room
Automatically adds newline AND  nullchar to BUFFER 
Returns buffer address on success
Returns NULL ptr on failure, when attempting to read EOF
ex:
#define BUFF_SIZE	(32) /* Predefined in STDLIB */
int main () {
	FILE *fp;
	char buffer[BUFF_SIZE];
	fp = fopen("doc.txt", "r+");
	while (fgets(buffer, BUFF_SIZE, fp)) 
		printf("%s", buffer); /* Leaves previous data in buffer each iteration if not overwritten by line +\n+\0 */
	fclose(fp);
	return 0;
}
if buffer is not large enough
 contuning to iterate that loop will still successfully get the entire string and other lines

unsigned int fputs(const char *buffer, FILE *fp); /* Puts string stored in Buffer to current file position in fp */
int main() {
	FILE *fp;
	char buffer[BUFFER_SIZE];
	fp = fopen("doc.txt", "w");
	scanf("%s", buffer);
	fputs(buffer, BUFFER_SIZE, fp);
	fflush(fp); /* Actually flushes file buffer to file */
	fclose(fp);
	return 0;
}


FFLUSH func
void fflush(FILE *fp); /* Writes data in file buffer to its file */
/* Buffer automatically flushes when it fills */
fflush forces buffer to be flushed to disk
Good for when there is not a predefined amount of writing that will be done to a file
but not very useful overall




Formatted inputs to FILEs

int fprintf(FILE *stream, char *format-string, argument-list); /* Moves current file position */
int fscanf(FILE *stream, const char *format-string, argument-list); /* Scans for format, moves file position after format */
/* Same as printf and scanf but with specified STREAMS */

#include <stdlib.h>
#include <stdio.h>
struct player {
	char name[25];
	unsigned int age;
	int points;
	struct player *next;
};
int main() {
	FILE *fp;
	int ret;
	struct player *item, *players = NULL;
	fp = fopen("data.csv", "r");

	while(1){
		item = malloc(sizeof(*item));
		ret = scanf(fp, "%[^,], %d, %d\n", &item->name, &item->age, &item->points);
		if (ret == EOF) {
			free(item);
			break;
		}
		add_player(&players, item)
	}
	fclose(fp);
	return 0;
}

%[^,] is a SCANSET

SCANSET EXAMPLES: %
[A-Z]	Sequence of uppercase chars
[0-9]	Sequence of digit chars
[^\n]	Everything up to the newline
[^,]	Everything up to the comma
[^z]	Everything up to z


FILE STREAMS
stdin, stdout, stderr

stdout is NEWLINE BUFFERED
meaning printing one char will not immediately be printed to screen
waits for newline or buffer fill

stderr is NOT NEWLINE BUFFERED
it is flushed IMMEDIATELY

printf should be used for program output
fprintf(stderr...) errors

separations are useful because outputs can be parsed
pipe stdout from one file to another or to a file
using fprintf(stderr...) prints errors to screen but not caught by pipe or other stdout streams
EXAMPLE: 
> shell command can be given file descriptors!!
./foo 1> doc.tx /* FD 1 is STDOUT */
./foo 2> err.log /* FD 2 is STDERR */
./foo 0> usr.log /* FD 0 is STDIN */
or
./foo > doc.txt 2> err.log /* Not specifying a FD defaults to FD 1, STDOUT. NOT 0 */

Good practice to separate STDERR and STDOUT printing!!




WORKING WITH BINARY FILES:
binary mode
supply "b" to file mode

FWRITE
size_t fwrite(void *ptr, size_t size, size_t num, FILE *fp) /* Writes to binary file */
/* Returns num elements written, each element is SIZE bytes long. Should return NUM if success */
	void *ptr: Pointer to 1st byte of 1st element to write /* Address in memory of the stuff you want to write */
	size_t size: Size of each element in bytes /* unsigned long in C89 */
	size_t num: Number of elements to write to file
	FILE *fp: File pointer to binary file

FREAD
size_t fread(void *ptr, size_t size, size_t num, FILE *fp) /* Reads NUM SIZE elements from file and returns number read */
	void *ptr: Memory address for first element to be written to
	size_t size: Size of each element in bytes
	size_t num: Number of elements of SIZE to be read
	FILE *fp: File pointer to openen file

Example of fwrite and fread:
#include <stdio.h>
#include <stdlib.h>
struct emplyee {
	unsigned int id;
	unsigned in age;
	float salary;
	unsigned int years;
}; /* 16 bytes per struct instance */
int main() {
	FILE *fp;
	size_t ret;
	struct employee *staff; /* Not necessarily making an instance, but making a type ptr for the array later */
	char *fn = "staff.dat";
	/* Write */
	staff = malloc(2*sizeof(*staff)); /* Creates array for 2 employees */
	/* SET staff vals staff[0].id = 11213; ... */
	fp = fopen(fn, "wb"); /* Write with binary mode */
	if (!fp) {
		fprintf(stderr, "Failed to open %s\n", fn);
		return EXIT_FAILURE;
	}
	ret = fwrite(staff, sizeof(*staff), 2, fp);
	if (ret != 2) {
		fprintf(stderr, "Failed to write to %s\n", fn);
		return EXIT_FAILURE;
	}
	free(staff);
	printf("Wrote %zu employees to %s\n", ret, fn);
	fclose(fp);

	/* Now read */
	fp = fopen(fn, "rb");
	if (!fp) {
		fprintf(stderr, "Failed to open %s\n", fn);
		return EXIT_FAILURE;
	}
	staff = malloc(2*sizeof(*staff));
	ret = fread(staff, sizeof(*staff), 2, fp); /* FREAD 2 elements from fp of size STAFF to staff */
	if (ret != 2) {
		fprintf(stderr, "Read failure: read %zu of 2\n", ret);
		return EXIT_FAILURE;
	}
	fclose(fp);
	free(staff);
	return 0;
}	
/* Byte order is stored by OS Standards */
When writing in little Endian, byte order is okay but sequence order is backwards
00 00 00 01 : 1 in dec gets written as 01 00 00 00 in Little Endian binary coded dec
BE CAREFUL WHEN READING THESE BYTES
binary write was made for BIG ENDIAN


Data is Data
fread can be used to read each byte into memory RAW
unsigned char data[16];
FILE *fp;
int i;
fp = fopen("staff.dat", "rb"); /* handle NULL PTR return */
while ( (ret=fread(data, sizeof(*data), 16, fp)) ) {
	for (i=0; i<ret; i++) {
		printf("%02x ", data[i]);
	}
	printf("\n");
}
fclose(fp); 

BINARY FSEEK AND FTELL
fseek() and ftell() Same for Binary except fseek can take any int for OFFSET
int fseek(FILE *fp, long int offset, int whence); /* Seeks to WHENCE + OFFSET */
long int ftell(FILE *fp); /* returns byte offset from start of file of fp */
void rewind(FILE *fp); /* Goes to file position 0 */

SAME AS TEXT FUNCS BUT:
	offset for fseek can be anynumber
	moving 1 byte ALWAYS moves 1 byte


fseek and ftell GOTCHAS
TEXT MODE:
	fseek offsets:
		-hardcoded to be 0
		-val returned by ftell
	ftell returns:
		-not number of bytes on WINDOWS
		-DO NOT measure filesize with fseek(fp, 0, SEEK_END) and ftell(fp)

BINARY MODE:
	fseek(fp, 0, SEEK_END) IS UNDEFINED BEHAVIOR!!!!
		-may work on implementations but may not be portable

BOTH MODES:
	ftell(fp) returns LONG INT
		-could be issue for large files with 32-bit long int



BINARY or TEXT format?
TEXT MODE:
	-portable between architechtures
		no endian issues or type size issues
	-produce larger files
		61907 is 6 byte string
	-slower read/write
		requires string->rep for read
		requires rep->string for write

BINARY MODE:
	-portability issues
		little v big endian, type size difference
	-produce smaller files
		61907 is 2 bytes short int
	-faster read/write
		no conversion necessary
		file holds native data representations
		big/little endian conversion












Loops:
for (initialization; condition; iterator) {
	// body of for loop
}
initialization is executed first and once, usually variable is delacred and initialized
condition is evaluated next, boolean statement
if condition is true, iterator statement is executed, usualyl changes the value of init variable
again condition is evaluated
continues until condition is false and loop terminates





int n = 5, sum = 0
for (int i=1; i<=n; i++) {
	sum += i;
}
cout << "Sum of first {0} natural numbers = {1}", n, sum); << endl;

Loops with mutiple initialization and iterator expressions:
for (int i=0; j=0; i+j<=5; i++; j++) {
	Console.WriteLine("i = {0} and j = {1}", i, j);
}

For loops without initialization and iterator statement:
int i = 1;
for ( ; i<=5; ) {
	Console.WriteLine("C# For Loop: Iteration {0}", i);
	i++;
}
//If no condition, loop will be infinite

While Loops:
while (condition)
{
	//statements
	iterator;
}

Ex:
int main() {
	int i = 1;
	while (i<6) {
		printf("Hello World\n");
		i++;
	}
	return 0;
}


Do...While Loops:

do
{
	//statements
	iterator;
} while (condition);


If/Else statements; nested

if(condition)
{
	//statements to execute if cond is true
}

if(condition)
   statement1;
   statement2;

// Here if the condition is true, if block 
// will consider only statement1 to be inside 
// its block since no {}

If/Else:
if (condition) {
	//execute if cond is true
}
else {
	//execute if cond is false
}


Nested if:
if (cond1)
{
	//execute if cond1 is true
	if (cond2)
	{
		//execute if cond2 is true
	}
}

else-if ladders:
if (condition)
	statement;
else if (condition)
	statement
.
.
else
	statement;

Jump statements: BREAK
int stop = 50;
for (int i = 0; ; i++) {
	printf("Current index is {0}", i);
	if (i == stop) {
		break;
	}
}

CONTINUE
will immediately repeat the loop from beginning for next iteration
ignores all code below continue; statement
int main() {
	// loop from 1 to 10
	for (int i = 1; i <= 10; i++) {
 
		// If i is equals to 6,
		// continue to next iteration
		// without printing
		if (i == 6)
            		continue;
 
        	else
            		// otherwise print the value of i
            		printf("%d ", i);
	}
	return 0
}

GOTO
Syntax:
goto label1;
.
.
.
label1:

or

label2
.
.
.
goto label2;

EX:
void printNumbers()
{
	int n = 1;
label:
    	printf("%d ",n);
   	n++;
    	if (n <= 10)
    		goto label;
}

Input and Output Redirection in C++:
freopen() to redirect and existing FILE pointer to another stream
prototype:
FILE * freopen ( const char * filename, const char * mode, FILE * stream );

to write the stdout to a textfile:
freopen  "textfile.txt", "w", stdout);

3 Streams:
istream: stream objects of this type can only perform input operations from stream

ostream: objects can only be used for output operations

iostream: can be used for both input and output operations

All operations are performed from buffer which is linked to the source

To redirect from Stream A to Stream B:
get stream buffer to A and store it somewhere
set stream buffer of A to stream buffer of B
if needed to reset the stream buffer of A to previous stream buffer

ios::rdbuf() can perform 2 operations:
	stream_object.rdbuf(): returns pointer to the stream buffer of stream_object
	stream_object.rdbuf(streambuf*p): sets stream buffer to the object pointed by p

using namespace std;

int main() {
	fstream file;
	file.open("cout.txt", ios::out);
	string line;

	// backup streambuffers of cout
	streambuf* stream_buffer_cout = cout.rdbuf();
	streambuf* stream_buffer_cin = cin.rdbuf();

	// get the streambuffer of the file
	streambuf* stream_buffer_file = file.rdbuf();

	// redirect cout to file
	cout.rdbuf(stream_buffer_file);
	
	cout < "This line written to file << endl;

	// redirect cout back to screen
	cout.rdbuf(stream_buffer_cout);
	cout << "This line is written to screen" << endl;

	file.close();
	return 0;
}

Can be condensed into a single step:
auto cout_buf = cout.rdbuf(file.rdbuf())
// sets cout streambuffer and returns the old streambuffer back to cout_buf



Input and Output statements:
cin and cout
int main() {
	int age;

	cout << "Enter your age:";
	cin >> age;
	count << "\nYour age is: " << age;
	return 0;
}

Unbuffered standard error stream:
#include <iostream>
using namespace std;
int main() {
	cerr << "An error occured";
	return 0;
}

unbuffered, cannot store message

Buffered standard error stream
#include <iostream>
using namespace std;
int main() {
	clog << "An error has occured";
	return 0;
}

Clearing the Input buffer in C/C++:
Properly taking inputs into buffer
for C:
int main() {
	char str[80], ch;
	scanf("%s", str);
	while ((getchar()) != '\n');
	ch = getchar();
	printf("%s\n", str);
	printg("%c", ch);
	return 0;
}

for C++:
using namespace std;
int main() {
	int a;
	char str[80];
		
	cin >> a;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cin.getline(str,80);
	cout << a << endl;
	cout << str << endl;
	
	return 0;
}


Arithmetic Operators: 
	+,-,*,/,%,++,--
	are of two types
	Unary operators, works with a single operand
	Binary operators, works with two operands

Relational Operators:
	==,>=,<=

Logical Operators:
	&&

Assignment Operators:
	=,+=,-+,*=,/=

Other Operators:
	sizeof, comma, conditional

Precedence Operator Description:
()	Functionc all
[]	Array subscript
.	Member selection via object name
->	Member selection via pointer
++/--	Postfix increment/decrement 
++/--	Prefix increment/decrement
+/-	Unary plus/minus
!~	Logical negation/bitwise complement
(type)	Cast, convert value to temporary value of type
*	Deference
&	Address, of operand
sizeof	Determine size in bytes on this implementation
*,/,%	Multiplication, division, modulus
+/-	addition/subtraction
<<,>>	Bitwise shift left/right
<,<=	Relational less than / and equal to
>,>=	Relational greater than / and equal to
==,!=	Relational is equal to or is not
&	Bitwise AND
^	Bitwise exclusive OR
|	Bitwise inclusive OR (ORs the numbers in binary, returns result)
&&	Logical AND
||	Logical OR
?:	Ternary conditional
=	Assignment
+=,-=	Addition/Subtraction assignment
*=,/=	Multiplication/Division assignment
%=,&=	Modulus/Bitwise AND assignment
^=,|=	Bitwise exclusive/inclusive OR assignment
<>=	Bitwise shift left,right assignment
,	Expression separator

Variable Scopes:
Statically (or lexically) scoped: 
	binding of a var can be determined by program and is independent of runtime of call stack

Scope Rules
File Scope:	identifiers outside funcs. global
BLock Scope:	begin at opening of block and end at closing. local
Func Proto Scope:	indentifiers delcared in func proto are visible within it
Func Scope:	labels that are within a function

C/C++ Tokens:
Keywords C:
auto, break, case, char, const, continue, default, do, double, else, enum, extern, float, for, goto, if, int
	long, register, return, short, signed, sizeof, static, struct, switch, typedef, uniom, unsigned, void, volatile, while
C++ Additional Keywords:
asm, bool, catch, class, const_cast, delete, dynamic_cast, explicite, export,
	false, friend, inline, mutable, namespace, new, operator, private, protected,
	public, reinterpret_cast, static_cast, template, this, throw, true, try
	typeid, typenam, using, virtual, wchar_t

Constants:
cannot be changed once declared
const data_type var_name;(or) const data_type *var_name;

Types of Constants:
ints, real or floats, octal and hexadecimal, characters, strings

Declaration of strings vs chars
Strings are arrays of chars that end with '\0' NULL value
Strings: "use double quots"
Chars: 'A' // use single quotes

SYNTAX: string[20] allocates 20 bytes of memory
	string[] will allocate memory per requirement, may run out of memory if string changes drastically in a large complex program

Special Symbols: [](){},;*=#
[] 	arrays
() 	func calls and parameters
{}	start and end of a block of code containing more than 1 line of executable code
,	separates more than one statements like params
:	invokes somethinc called initialization list
;	statement terminator, indicates end of one local entity
*	creates pointer var
=	used to assign values
#	preprocessor is a macro that transforms program before actual compilation

List in C++ STL:
sequence containers that allow non-contiguous memory allocation
slow transversal but once position is foumd, insertion and deletion are quick
Functions for lists:
front()		returns val of first item
back()		returns val of last itme
push_front(g)	adds 'g' at beginning
push_back(g)	adds 'g' at end
pop_front()	removes first element and reduces the size of list by 1
pop_back()	removes last element and reduces size of list by 1
begin()		returns iterator pointing to first element
end()		returns iterator pointing to last element
typical ... for rbegin(), rend(), cbegin(), cend(), crbegin(), and crend()
empty()		returns if its empty or not
insert()	inserts new element in the list before the element in specified pos
erase()		removes a single element or range from the list
assign()	assigns new elements by replacing current ones and resizes list
remove()	removes all elements from list which are equal to given one
remove_if(cond)	used to remove all the values of list that correspond true to cond
reverse()	reverses list
size()		returns number of elements
resize()	resizes list
sort()		sorts list in increasing order
max_size()	returns max number of elements a list can hold
unique()	removes all duplicate consecutive elements from list
emplace_front()	insert new item in beginning
emplace_back()	insert new element in end
emplace()	extends list by inserting new element at given pos
clear()		remove all elements in list, making size 0
operator=	assigns new contest to the container by replacement
swap()		swap contents of one list with another of same type and size
splice()	transfer elements from one list to another
merge()		merges two sorted lists into one

Pairs C++ STL:
first element is ref 'first'
second is ref 'second'
pairs two vals together which may be different types
can be assigned, copied and compared

SYNTAX: pair(data_type1, data_type2) Pair_name;
pair<int, char> PAIR1;
PAIR1.first = 100;
PAIR1.second = 'g';

OR
pair<int, char> PAIR1(100, 'g');

Different ways to initialize a pair:
pair  g1;         //default
pair  g2(1, 'a');  //initialized,  different data type
pair  g3(1, 10);   //initialized,  same data type
pair  g4(g3);    //copy of g3
g2 = make_pair(1, 'a');
g2 = {1, 'a'}

aps in C++ STL:
maps are containers with keys and values
no two values can have the same key
like dictionaries from Python

associated functions:
begin(), end(), size(), max_size(), empty(), insert(key,val),
erase(pos), erase(cost g), clear(), count('g'), equal_range(), rend(), rbegin()
find('g'), upper_bound('g'), lower_bound(), operator=, emplace_hint(), value_comp()
key_comp(), operator[], at(), swap()

Initializing Maps:
map<int, int> gquiz1;
Inserting into Maps:
gquiz1.insert(pair<int,int>(1,40));

Sets in C++ STL:
associative containers with each element is unique
same appropriate associative functions as other containers
initialize empty set container:
set<int, greater<int>> s1;
s1.insert(10);

printing an entire set/container with iterators:
set<int, greater<int>>::iterator itr;
for (itr = s1.begin(); itr !=s1.end(); itr++)
	{cout<<*itr<<" ";}
cout<<endl;

Unordered Sets in C++ STL:
unordered_set<string> stringSet;
stringSet.insert("code");

ultisets in C++ STL:
can have same valued items
multiset<int, greater<int>> gquiz1;
gquiz.insert(40);


Dynamic Deallowcating and Reallocating memory:
pointer-variable = new data-type;

// Combine declaration of pointer 
// and their assignment
int *p = new int; 

Initialize with new data:
int *p = new int(25);
float *q = new float(75.25);

Allowcating a block of memory
int *p = new int[10]

Dynamically allocated arrays, even local ones, are never deallocated


Not enough memory during runtime?
int *p = new(nothrow) int;
if (!p)
{
   cout << "Memory allocation failed\n";
}

anually deallocating memory:
delete pointer-variable;

delete p;
delete q;

for an array:
delete[] p;


Pointers and Arrays:

Declare arrays:
by size: int arr1[10]

by size and initialize:
int arr[6] = { 10, 20, 30, 40 }

by user specified size:
int arr[n];

Accessing array elements:
arr1[0] is first element
indexing

int *ptr;
int arr[5];

C:
// C program to demonstrate that
// array elements are stored
// contiguous locations
 
#include <stdio.h>
int main()
{
    // an array of 10 integers. 
    // If arr[0] is stored at
    // address x, then arr[1] is
    // stored at x + sizeof(int)
    // arr[2] is stored at x +
    // sizeof(int) + sizeof(int)
    // and so on.
    int arr[5], i;
 
    printf("Size of integer in this compiler is %lu\n",
           sizeof(int));
 
    for (i = 0; i < 5; i++)
        // The use of '&' before a variable name, yields
        // address of variable.
        printf("Address arr[%d] is %p\n", i, &arr[i]);
 
    return 0;
}

C++:
// C++ program to demonstrate that array elements
// are stored contiguous locations
 
#include <iostream>
using namespace std;
 
int main()
{
    // an array of 10 integers. 
    // If arr[0] is stored at
    // address x, then arr[1] is
    // stored at x + sizeof(int)
    // arr[2] is stored at x +
    // sizeof(int) + sizeof(int)
    // and so on.
    int arr[5], i;
 
    cout << "Size of integer in this compiler is "
         << sizeof(int) << "\n";
 
    for (i = 0; i < 5; i++)
        // The use of '&' before a variable name, yields
        // address of variable.
        cout << "Address arr[" << i << "] is " << &arr[i]
             << "\n";
 
    return 0;
}

Traversing Arrays:
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int arr[6]={11,12,13,14,15,16};
    // Way -1
    for(int i=0;i<6;i++)
        cout<<arr[i]<<" ";
   
  cout<<endl;
      // Way 2
    cout<<"By Other Method:"<<endl;
    for(int i=0;i<6;i++)  
        cout<<i[arr]<<" ";
   
    cout<<endl;
 
    return 0;
}

Initializing Multi-dimensional Arrays:
int x[3][4] = {{0,1,2,3}, {4,5,6,7}, {8,9,10,11}};

//store the address of the first element of arr in ptr:
ptr = arr;
// also equal to ptr = &arr[0];

If ptr is the first element, ptr + 1 is the second:
ptr + 1 is equivalent to &arr[1];
ptr + 2 is equivalent to &arr[2];
ptr + 3 is equivalent to &arr[3];
ptr + 4 is equivalent to &arr[4];

or
// use dereference operator
*ptr == arr[0];
*(ptr + 1) is equivalent to arr[1];
*(ptr + 2) is equivalent to arr[2];
*(ptr + 3) is equivalent to arr[3];
*(ptr + 4) is equivalent to arr[4];

if ptr = &arr[2]; then
ptr - 2 is equivalent to &arr[0];
ptr - 1 is equivalent to &arr[1]; 
ptr + 1 is equivalent to &arr[3];
ptr + 2 is equivalent to &arr[4];

Returning address of pointer: Use &
printf("%p", &x);

Asterisk *: used to declare a pointer before name
or to access the stored value in the address. Dereferencing.

int main() {
	// A normal integer variable
    int Var = 10;
 
    // A pointer variable that holds address of var.
    int *ptr = &Var;
 
    // This line prints value at address stored in ptr.
    // Value stored is value of variable "var"
    cout << "Value of Var = "<< *ptr << endl;
 
    // The output of this line may be different in different
    // runs even on same machine.
    cout << "Address of Var = " <<  ptr << endl;
 
    // We can also use ptr as lvalue (Left hand
    // side of assignment)
    *ptr = 20; // Value at address is now 20
 
    // This prints 20
    cout << "After doing *ptr = 20, *ptr is "<< *ptr << endl;
 
    return 0;
}

OUTPUTS : 
Value of Var = 10
Address of Var = 0x7fffa057dd4
After doing *ptr = 20, *ptr is 20

Pointer Expressions and Pointer Arithmetic:
incremented (++)
decremented (--)
and integer may be added to pointed (+ or +=)
and integer may be subtracted from pointed (- or -=)

meaningless unless performed on an array
adding addresses: meaningless
subtracting addresses: computes offset between two addresses

int main() {
	int v[3] = {10, 100, 200};
	int *ptr;
	ptr = v
	for (int i = 0, i < 3, i++); {
	printf("Value of *ptr = %d\n");
	printg("Value of ptr = %p\n\n");
	ptr++;
	}
}

Output:
Output:Value of *ptr = 10
Value of ptr = 0x7ffcae30c710

Value of *ptr = 100
Value of ptr = 0x7ffcae30c714

Value of *ptr = 200
Value of ptr = 0x7ffcae30c718

Array names as pointers:
with array named val: val and &val[0] can be used interchamgeably

Pointers in multimimensional arrays
In general: nums[i][j] = *(*(nums+i)+j)


Opaque Pointer:
pointer that points to a container whose contents are not exposed at the time of its def
ex:
struct STest* pSTest;

it is safe to assign NULL to an opaque pointer:
pSTest = NULL;

Functions:
user defined:

returnType functionName (para1, para2,...) {
	//function  body
}

void greet() {
	cout << "Hello world";
}

int main() {
	greet();
	return 0;
}

Parameters:
void printNUm(int num) {
	cout << num;
}

int main() {
	int n = 7;
	printNum(n);
	
	return 0;
}

ultiple parameters:
void displayNum( int n1, float n2) {
	cout << "The int number is " << n1;
	cout << "The float number is " << n2;
}
int main() {
	int num1 = 5
	double num2 = 5.5;
	
	displayNum(num1, num2);
	
	return 0;
}

Return type:
// 'int' instead of 'void' bc it returns an int instead of not returning anything
int add (int a, int b) {
	return (a+b);
}

Classes:
template <class T>
class className {
	private:
		T var;
...
	public:
		T functionName( T arg);
		...
};

T is a template argument
class is a keyword
var is a member variable
functionName is a member function
	both of type T

Creating a class template object
inside main() function

className<dataType> classObject;
ex.
className<int> classObject;

C++ class templates
#include <iostream>
using namespace std;

// class template
template <class T>
class Number {
	private:
	//variable of type T
	T num;

	public:
		Number(T, n) : num(n) {} //constructor
		T getNum() {
			return num;
		}
};

int main() {
	// create object with int type
	Number<int>  numberInt(7);

	// create object with double type
	Number<double> numberDouble(7.7);

	cout << “int Number = “ << numberInt.getNum() << endl;
	cout << “double Number = “ << numberDouble.getNum() << endl;

	return 0;
}

Creating a calculator with classes:
#include <iostream>
using namespace std;

template <class T>
class Calculator {
	private:
		T num1, num2;
	public:
		Calculator( T n1, T n2) {
			num1 = n1;
			num2 = n2;
	}
	void displayResult() {
		cout << “Numbers: “ << num1 << “ and “ << num2 <<  “.” << endl;
		cout << num1 << “ + “ << num2 << “ = “ << add() << endl;
		cout << num1 << “ – “ << num2 << “ = “ << subtract() << endl;
		cout << num1 << “ * “ << num2 << “ = “ << multiply() << endl;
		cout << num1 << “ / “ << num2 << “ = “ << divide() << endl;
	}
	T add () { return num1 + num2; }
	T subtract() { return num1 - num2; }
	T multiply() { return num1 * num2; }
	T divide() { return num1 / num2; }
};

int main() {
	Calculator<int> intCalc(2, 1);
	Calculator<float> floatCalc(2.4, 1.2);
	
	cout << "Int results:" << endl;
	int.Calc.displayResult();

	cout << endl
		<< "Float results:" << endl;
	floatCalc.displayResult();
	
	return 0;
}


ultiple parameters
even with default arguments:
template <class T, class U, Class V = char>
class ClassTemplate {
	private:
		T var1;
		U var2;
		V var3;
		...
	public:
		ClassTemplate(T v1, U v2, V v3): var1(v1), var2(v2), var3(v3)
		void printVar() {
			cout << "var1 = " << var1 << endl;
			cout << "var2 = " << var2 << endl;
			cout << "var3 = " << var3 << endl;
		}
};

int main() {
	//create object with int, double, and char types
	ClassTemplate<int, double> obj1(7, 7.7, 'c');
	cout << obj1 values: " << endl;
	obj1.printVar();

	// create object with int double and bool types
	ClassTemplate<double, char, bool> obj2(8.8, 'a', false);
	cout << "\obj2 values: " << endl;
	obj2.printVar();
	
	return 0;

std::string class in C++
not prone to array decay
strings are slower but offer built in functions

Operations on strings:
getline()	used to store a stream of chars as entered by the user
push_back()	used to input a char at the end of a string
pop_back()	C++11^ used to delete the last character from a string

using namespace std;
int main() {
	string str;
	getline(cin,str)
	
	cout << "The initial string is : ";
	cout << str << endl;
	
	str.push_back('s');
	// puts 's' at end of string str

	str.pop_back();
	// deletes last character of string str

	return 0;
}

Capacity Functions
capacity()	returns the capacity allocated to the string which can be >= size of string
resize()	changes the size of the string
length()	finds length of string
shrink_to_fit()	decreases capacity of string, useful to save memory

using namespace std;

int main() {
	string str = geeksforgeeks is for geeks";
	
	cout << str << endl;
	// initial string

	str.resize(13);
	// resize string

	cout << str.capacity() << endl;
	// string capacity

	cout << str.length() << endl;
	// show new length

	str.shrink_to_fit();
	cout << str.capacity() << endl;
	//show new capacity

	return 0;
}

Iterator functions:
begin()		returns an iterator to beginning of the string
end()		returns iterator to end of string
rbegin()	returns a reverse iterator pointing at end of str
rend()		returns reverse iterator pointing at beginning of str

using namespace std;
int main() {
	string str = "geeksforgeeks"
	std::string::iterator it;
	std::string:reverse_iterator: it1;

	cout << "String using forward iterators is : ";
	for (it=str.begin(); it!=str.end(); it++)
	cout << *it;
	cout << endl;

	cout << "String using reverse iterators is : "
	for (it1.str.rbegin(); it!=,str.rend; it1++)
	cout << *it1;
	cout << endl;
	
	return 0;
}


copy("char array", len, pos)	copies the substring in the target character array, needs all 3 arguments
swap()				swaps one string with another

Raw string literals:
\n
\t
\"
\'
are not processed


stringstream in C++

clear()		clear stream
str()		to get and set string object whose content is present in stream

operator << - add a string to the stringstream object
operator >> read something from the stringstream object

including namespace std;

int countWords(string str)
{
	// breaking inout into word using string stream
	stringstream s(str); // used for breaking words
	string word; // to store individual words
	
	int count = 0;
	while (s >> word)
		count++;
	return count;
}

int main()
{
	string = "geeks for geeks geeks"
		"contribution placements";
	cout << "Numbers of words are: " << countWords(s);
	return 0;
}

Frequencies of words in a string:
using namespace std;

void printFrequency(string st) {
	//each word makked to its frequency
	map<string, int> FW;
	string Word;
	
	while (ss >> Word)
	FW[Word]++;
	
	map<string, int>::iterator m;
	for (m = FW.begin(); m!=FW.end(), m++)
		cout << m->first << " ->"
			<< m->secomd << "\n";
}
int main() {
	string s = "Geeks for Geeks Ide"
	printFrequency(s);
	return 0;
}


Default Arguments in C++:
int sum(int x, int y, int z=0, int w=0){
	return (x+y+z+w)
}


Inline Functions:

inline return-type function-name(param){
	//function body
}

Compiler can ignore the request for inlining and may not perform it:
1. function contains a loop
2. contains static variables
3. function is recursive
4. function return type is other than void and return statement doesnt exist in function body
5. function contains switch or goto statement

Inline function advantages:
1. function call overhead doesn't occur
2. it also savles the overhead of push/pop variables on the stack when the function is called
3. it also saves overhead of a return all from a function
4. compiler can do content specific optimization on the body of function
5. useful for embedded systems for small functions

Inline function disadvantages:
1. variables consume additional registers. can cause overhead if variable size increases drastically
2. using too many inline functions increases size of binary executable file
3. reduces instruction cache hit rate, reducing instructing fetch
4. may increase compile time overhead
5. may not be useful for embedded  systems because size matters
6. might cause thrashing

inline int cube(int s) {
	return s*s*s;
}

Inline function and classes:
class S
{
public:
	inline in square(int s) // redundant use of inline
	{
		// this function is automatically inline
		// function of body
	}
};

Bad writing above
better below
class S
{
public:	
	int square(int s); //declare the function
};
inline int S::square(int s) // use inline prefix
{
}


Example of this concept:
#include <iostream>
using namespace std;
class operation
{
    int a,b,add,sub,mul;
    float div;
public:
    void get();
    void sum();
    void difference();
    void product();
    void division();
};
inline void operation :: get()
{
    cout << "Enter first value:";
    cin >> a;
    cout << "Enter second value:";
    cin >> b;
}
  
inline void operation :: sum()
{
    add = a+b;
    cout << "Addition of two numbers: " << a+b << "\n";
}
  
inline void operation :: difference()
{
    sub = a-b;
    cout << "Difference of two numbers: " << a-b << "\n";
}
  
inline void operation :: product()
{
    mul = a*b;
    cout << "Product of two numbers: " << a*b << "\n";
}
  
inline void operation ::division()
{
    div=a/b;
    cout<<"Division of two numbers: "<<a/b<<"\n" ;
}
  
int main()
{
    cout << "Program using inline function\n";
    operation s;
    s.get();
    s.sum();
    s.difference();
    s.product();
    s.division();
    return 0;
}


Returning in void functions:
void functions can return nothing:
void fun(){
	// body
	return; // good practice to have return statement to ease readability
}


Or void functions can return other void functions:
void work(){
	cout << "The void function has returned a void() !!! \n";
}
void test() {
	return work();
}

int main() {
	test();
	return 0;
}

Returning a void value:
void test() {
	cout <<  "Hello";
	return (void)"Doesn't Print";
}
int main() {
	test();
	return 0;
}


Functors in C++ (Function object)
not functions
need a lot more info to pass through a function than is allowed by params
good practice is to avoid the use global variables

instead: Functors
objects can be treated like a function or function pointer
used along with STLs

to make functor, create an object that overloads the operator()
yFunctor(10); is the same as MyFunctor.operator()(10);

// A Functor
class increment
{
private:
    int num;
public:
    increment(int n) : num(n) {  }
  
    // This operator overloading enables calling
    // operator function () on objects of increment
    int operator () (int arr_num) const {
        return num + arr_num;
    }
};
  
// Driver code
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int to_add = 5;
  
    transform(arr, arr+n, arr, increment(to_add));
  
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
}

The line,
transform(arr, arr+n, arr, increment(to_add));

is the same as writing below two lines,
// Creating object of increment
increment obj(to_add); 

// Calling () on object
transform(arr, arr+n, arr, obj);


References in C++
when a varible is declared as a reference, it becomes an alt name for another var

can be delcared as a ref by putting & in declaration

int main() {
	int x = 10;
	
	// ref is a reference to x
	int& ref = x;
	
	// value of x is now changed to 20
	ref = 20;
	cout << "x = " << x << endl;
	
	// value of x is now changed to 30
	x = 30;
	cout << "ref = " << ref << endl;

	return 0;
}
Outputs:
 x = 20
ref = 30

Applications of refs:
1. Modify passed parameters in a function
void swap (int& first, int& second) {
	int temp = first;
	first = second;
	second = first;
}
int main() {
	int a=2, b=3;
	swap(a,b);
	cout << a << " " << b;
	return 0;
}

2. Avoiding a copy of large structures
struct Student {
	string name;
	string address;
	int rollNo;
}
		// if no &, a new copy of the student is created and is inefficient
void print(const Student &s) {
	cout << s.name << " " << s.address << s.rollNo;
}

3. In FOR EACH loops to modify all objects:
int main() {
	vector<int> vect{10,20,30,40};
	
	//modify elements with refs
	for (int &x : vect)
		x = x+5

	//printing elements
	for (int x : vect)
		count << x << " ";
	return 0;
}

4. FOR EACH loops to avoid the copy of objects:
int main() {
	vector<string> vect{"string 1", "string 2", "string 3"};

	// avoid copy of whole string obj by using ref
	for (const auto &x : vect)
		cout << x << endl;
	return 0;
}

Refs vs Pointers:
differences:
1. Pointer can be declared as void but ref is never void
	int a = 10;
	void* aa = &a;. //it is valid
	void &ar = a; // it is not valid
2. Pointer has n-levels/multipel levels of indirection while refs have 1
3. Ref variable cannot be updated
4. Ref variable is an internal pointed
5. Declaration of ref is preceded with & but not read as 'address of...'

int main() {
    int i=10; //simple or ordinary variable.
    int *p=&i; //single pointer
    int **pt=&p; //double pointer
    int ***ptr=&pt; //triple pointer
    // All the above pointers differ in the value they store or point to.
    cout << "i=" << i << "\t" << "p=" << p << "\t" 
         << "pt=" << pt << "\t" << "ptr=" << ptr << "\n";
    int a=5; //simple or ordinary variable 
    int &S=a; 
    int &S0=S;
    int &S1=S0;
    cout << "a=" << a << "\t" << "S=" << S << "\t" 
         << "S0=" << S0 << "\t" << "S1=" << S1 << "\n";
    // All the above references do not differ in their values 
    // as they all refer to the same variable.
 }

References are less powerful that pointers
1. once ref is created, it cannot be made to ref another var later, unlike pointers
2. Ref cannot be NULL, pointers can be to say theyre not pointing to something valid
3. ref must be initialized when delcared, no restriction with pointers

References are safer and easier to use:
1. Safer: refs usually always refer to something valid bc they have to be initialized
2. Easier to use: refs can be used like normal vars. & is only used to initialize. to access members of ref obj, use '.' unlike '->' with pointers

'this' Pointer in C++
passed as hidden argument to all nonstatic member function calls, local variable
not available with static member functions since they cant be called without any object

for class X, pointer type is 'X*'
if member function of X is declared as const pointer type is 'const X*'

C++ lets objects destroy themselves by:
delete this;

Uses of 'this' pointer:
1. When local variables name is same as members name:
class Test
{
private:
	int x;
public:
	void setX (int x) {
	// the 'this' pointer is used to retrieve the objects hidden by local variable 'x'
	this->x = x;
}
	void print() { cout<< "x = " << x << endl; }
};
int main() {
	Test obj;
	int x = 20;
	obj.setX(x);
	obj.print();
	return 0;
}

2. To return reference to the calling object:
/* reference to the calling object can be returned */
Test& Test::func () {
	// some processing
	return *this;
}
//when a ref to a local obj is returned, the ref can be used to chain func
// calls to a single obj
class Test {
private:
	int x;
	int y;
public:
	Test(int x = 0, int y = 0) { this->x = x; this->y = y;}
	Test &setX(int a) {x = a; return *this;}
	Test &setY(int b) {y = b; return *this;}
	void print() { cout<< "x = " << x << " y = " << y << endl;
};
int main() {
	Test obj1(5,5);
	//chained function calls. all calls modify the same obj
	// as the same obj is returned by ref
	obj1.setX(10).setY(20);

	obj1.print();
	return 0;
}

Smart pointers in C++11
automatically deallocates memory when pointer is destroyed

class SmartPtr {
	int* ptr; //actual pointer
public:
	explicit SmartPtr(int* p = NULL) { ptr = p; }
	
	//destructor
	~SmartPtr() {delete (ptr); }
	
	//overloading dereferencing operator
	int& operator*() { return *ptr; }
};
int main() {
	SmartPtr ptr(new int());
	*ptr = 20
	cout << *ptr;
	// dont need to delete ptr bc when obj goes out of scope
	// destructor automatically deletes it
	return 0;
}
this only works for int
instead use Template for all other uses since it can be any type

template <class T>
class SmartPtr {
	T* ptr; //actual pointer
public:
	//constructor
	explicit SmartPtr(T* p = NULL) {ptr=p;}
	
	/destructor
	~SmartPtr() {delete(ptr);}
	
	//overloading dereference operator
	T& operator*() {return *ptr;}

	// overloading arrow operator so that T members can be accessed
	// like a pointer. useful if T represents a calss or struct or union type
	T* operator->() { return ptr; }
};
int main() {
	SmartPtr<int> ptr(new int());
	*ptr = 20
	cout<< *ptr;
	return 0;
}

Types of Smart Pointers:
1. unique_ptr
stores 1 pointer only
int main(){
 
    unique_ptr<Rectangle> P1(new Rectangle(10, 5));
    cout << P1->area() << endl; // This'll print 50
 
    // unique_ptr<Rectangle> P2(P1);
    unique_ptr<Rectangle> P2;
    P2 = move(P1);
 
    // This'll print 50
    cout << P2->area() << endl;
 
    // cout<<P1->area()<<endl;
    return 0;
}

2. shared_ptr
more than one pointer can reference the same object at a time
maintains reference counter using use_count() method
int main()
{
 
    shared_ptr<Rectangle> P1(new Rectangle(10, 5));
    // This'll print 50
    cout << P1->area() << endl;
 
    shared_ptr<Rectangle> P2;
    P2 = P1;
 
    // This'll print 50
    cout << P2->area() << endl;
 
    // This'll now not give an error,
    cout << P1->area() << endl;
 
    // This'll also print 50 now
    // This'll print 2 as Reference Counter is 2
    cout << P1.use_count() << endl;
    return 0;
}

3. weak_ptr
similar to shared_ptr except it does not maintain reference counter


Pointers vs Refs
// A pointer to variable i (or stores
// address of i)
int *ptr = &i; 

// A reference (or alias) for i.
int &ref = i; 

Initialization:
Pointer
int a = 10;
int *p = &a;
	or 
	int *p;
	p = $a; //can be done in 1 line or 2 because ptrs can be NULL

Reference
int a = 10;
int &p=a; //must do in one line

Reassignment:
Pointer
int *p;
p = &a;
p = &b;

Reference:
cannot be reassigned, must be assigned at initialization
however,
int &q = p //is valid

emory Address:
pointer has its own memory address and size
ref shares memory and address with original var

NULL Value:
pointers can be NULL directly when refs cannot

Indirection:
pointers to pointers, offering levels of indirection
refs only offer one level of indirection

int a = 10;
int *p;
int **q; // is valid
p = &a;
q = &p;

int &p = a;
int &&q = p; // is invalid and will throw error

Arithmetic Operations:
only for pointers
can do arithmetic on address of obj pointed by a ref:
&obj + 5

Use REFS:
	in function parameters and return types
Use POINTERS:
	for pointer arithmetic or passing NULL
	implement data structures like linked list tree




Object Oriented Programming in C++:
class person {
	char name[20];
	int id;
public:
	void getdetails(){}
};
int main() {
	person p1; //p1 is an object
}

Encapsulation:
	wrapping of info and data under a single unit
in OOP: binding together data and the functions that manipulate them
in other words: Classes

Abstraction:
	displaying only essential info and hiding the details

Polymorphism:
	ability of data/message to be displayed in more than 1 form
	implemented by: 
	operator overloading
	function overloading

Inheritance: 
	capability of a clas to derive properties and characteristics from another class
	Sub Class: class that inherits properis from another is sub class or derived class
	Super Class: class whose properties are inhereited by another is super class or base class
	Reusability: Deriving a new class from an existing one by reusing fields and methods

Dynamic Binding: 
	code to be executed in response to function call is decided at runtime

essage Passing:
	message for an object is a request for execution of a procedure
	and will invoke a function in the receiving object that generates result.
	involves specifying name of obj and name of func and info

class ClassName {
access specifier: //private, public or protected
data members: //variables to be used
member functions(){}: // methods to access data members
}; // class name ends with a semicolon

int main() {
	// delcare an object of class
	ClassName ObjectName;
	
	// accessing data member
	ObjectName.ClassVar = Val
	
	// accessing member function
	ObjectName.FunctionName(Params);

	return 0;
}

Inside vs Outside class function definition:
Outside: needs to use scope resolution :: operator along with class name and function name
class ClassName(){
	void FunctionName1() {
		// body of inside function
	}
.
.
.
};
void ClassName::FunctionName2() {
	//body of outside function
} // note no semicolon
int main() {
.
.
.
}

Constructors
special class member which are called by the compiler every time obj of class is instantiated
have same name as class and may be defined inside or outside of class def
3 types of constructors:
1. Default constructors
2. Parameterized constructors
3. Copy constructors

class Cars {
	public:
	int id;

	//default constructor
	Cars(){
		cout << "Default Constructor Called" << endl;
		id=-1;
	}
	//parameterized constructor
	Cars(int x) {
		cout << "Parameterized constructor called" << endl;
		id = x;
	}
};

int main() {
	Cars obj1; // will initialize with id = -1
	Cars obj2(21); // will initialize with id=21
	return 0;
}

Destructor:
	Called by compiler when scope of object ends
class Cars {
	public:
	int id;
	
	// def for deconstructor
	~Cars(){
		cout << "Deconstructor has ben called for" << id << endl;
	}
};
int main() {
	Cars obj1;
	int i = 0
	while(i<5){
		Cars obj2;
		obj2.id = i;
		i++;
	} // scope for obj2 ends here
	return 0;
} //scope for obj1 ends here


Inheritance in C++:
ex. for classes Bus, Truck and Car,
methods fuelAmount(), capacity(), and applyBrakes() will be same
without inheritance, these three methods will have to be written seperately for each class
gives duplicate code

Solution: make Super class: Vehicles and inherit down methods

Syntax: class SubclassName : AccessMode BaseClassName {
	//body of subclass
};

ex.
class Parent {
	public:
		int id_p;
};
class Child : public Parent {
	public:
		int id_c;
};
int main() {
	Child obj1;
	//obj of class child has all data members and member functions of class parent
	obj1.id_c = 7;
	obj1.id_p = 91;
	return 0;
}

Access Modes:
Public: public member of base class will be public in derived class, protected from base will be protected in derived
Protected: public and protected members of base will be come protected in derived
Private: public and protected from base will be private in derived

class A
{
public:
    int x;
protected:
    int y;
private:
    int z;
};
 
class B : public A
{
    // x is public
    // y is protected
    // z is not accessible from B
};
 
class C : protected A
{
    // x is protected
    // y is protected
    // z is not accessible from C
};
 
class D : private A    // 'private' is default for classes
{
    // x is private
    // y is private
    // z is not accessible from D
};

Single Inheritance in C++:
class is allowed to inherit from only one class
i.e. one sub class is inhereted by one base class only

ultiple Inheritance in C++:
class can inherit from more than one class.
i.e. one sub class can come from multiple base classes

Syntax of Multiple Inheritance:
class SubclassName : AccessMode BaseClass1, AccessMode BaseClass2 ... etc {
	// body of sub class
};

ultilevel Inheritance:
derived class created from another derived class

class BaseClass {...};
class MidClass :  AccessMode BaseClass {...};
class SubSubClass : AccessMode MidClass {...};

Hierarchical Inheritance:
more than one derived class is created from a single base class

Hybrid (Virtual) Inheritance:
combining more than one type of inheritance

ultipath Inheritance: Special case
Derived Class with two base classes which share a same base class
can create ambiguity since bottom class will have two copies of top base class members
class ClassA {
public:
    int a;
};
 
class ClassB : public ClassA {
public:
    int b;
};
class ClassC : public ClassA {
public:
    int c;
};
 
class ClassD : public ClassB, public ClassC {
public:
    int d;
};
 
void main()
{
 
    ClassD obj;
 
    // obj.a = 10;                   //Statement 1, Error
    // obj.a = 100;                 //Statement 2, Error
 
    obj.ClassB::a = 10; // Statement 3
    obj.ClassC::a = 100; // Statement 4
 
    obj.b = 20;
    obj.c = 30;
    obj.d = 40;
 
    cout << "\n A from ClassB  : " << obj.ClassB::a;
    cout << "\n A from ClassC  : " << obj.ClassC::a;
 
    cout << "\n B : " << obj.b;
    cout << "\n C : " << obj.c;
    cout << "\n D : " << obj.d;
}
to avoid ambiguity, path to top base class members should be specified like above
use scope resolution operator '::' to manually specify path

There are still two copies of classA in classD though
	to avoid this, use keyword 'virtual'
class ClassA
     {
            public:
            int a;
     };
 
     class ClassB : virtual public ClassA
     {
            public:
            int b;
     };
     class ClassC : virtual public ClassA
     {
            public:
            int c;
     };
 
     class ClassD : public ClassB, public ClassC
     {
            public:
            int d;
     };
 
     void main()
     {
 
            ClassD obj;
 
            obj.a = 10;        //Statement 3
            obj.a = 100;      //Statement 4
 
            obj.b = 20;
            obj.c = 30;
            obj.d = 40;
 
            cout<< "\n A : "<< obj.a;
            cout<< "\n B : "<< obj.b;
            cout<< "\n C : "<< obj.c;
            cout<< "\n D : "<< obj.d;
 
     }

Polymorphism in C++:
two main types:
	Compile time polymorphism
		Function overloading
		Operator overloading
	Runtime polymorphism
		Virtual functions

class Cars {
	public:
	
	// func with 1 int param
	void func(int x) {
		cout << "Value of x is " << x << endl;
	}

	// func with same name but 1 double param
	voud func(double x) {
		cout << "value of x is " << x << endl;
	
	// func with same name but 2 int params
	void func(int x, int y) {
		cout << "value of x and y is " << x << ", " << y << endl;
	}
};

Operator Overloading:
class Complex {
private:
	int real, imag;
public:
	Complex(int r = 0, int i = 0) {real = r, imag = j;}
	
	//this is automatically called when + is used b/w two complex objects
	Complex operator + (Complex const &obj) {
		Complex res;
		res.real = real + obj.real;
		res.imag = imag + obj.imag;
		return res;
	}
	void print() { cout << real << " + i" << imag << endl; }
};



Runtime polymorphism:
achieved by function overriding
	when a derived class has a def for one of the member functions of the base class
	funcion is said to be overridden

class base {
public:
	virtual void print() // specifying as virtual
		{ cout << "print base class" << endl;}
	void show() // non virtual
		{ cout << "show base class" << endl; }
};
class derived: public base {
public:
	void print() // print is already virtual
	{ cout << "print derived class" << endl; }
	void show() 
	{ cout << "show derived class" << endl; }
};
int main() {
	base *bptr;
	derived d;
	bptr = &d;
	//virtual function binded at runtime (runtime polymorphism)
	bptr->print();
	//non virtual function binded at compile time
	bptr->show();
	return 0;
}
OUTPUTS:
print derived class
print base class

since show() method is not virtual it is binded at compile time while print class is binded at runtime

Encapsulation in C++:
leads to data abstraction or hiding
use of access modifiers

class Encapsulation {
private:
	//data hidden from outside world
	int x;
public:
	//function to set value of var x

	void set(int a)
	{ x = a; }
	//func to return value of var x
	int get() {return x;}
};
int main() {
	Encapsulation obj;
	obj.set(5);
	cout << obj.get();
	return 0;
}

Since function in public access had authority to return private var,
	it is able to be accessed but only through that func

Abstraction in C++:
displaying only essential info

Abstraction using Classes:
	helps us to group data members and member functions using available access specifiers
	class can decide which data members are public or private

Abstraction in Header files:
	consider pow() method in math.h header file
	underlying algorithm is hiddne when pow() is called

For abstraction in Classes, a publicly defined method must be used to access a privately defined variable


Function Overloading in C++:
using namespace std;
void print(int i) {cout<<" Here is int "<<i<<endl;}
void print(double f) {cout<<" Here is float "<<f<<endl;}
void print(char const *c) {cout<<" Here is char* "<<c<<endl;}
int main() {
	print(10);
	print(10.10);
	print("ten");
	return 0;
}

Operator Overloading in C++:
operators that cannot be overloaded:
	.
	::
	?:
	sizeof

Variable Length Arguments for Macros:
use of '...'
also need "__VA_ARGS__" preprocessing identifier

ex:
#define ERR 2
#define INFO 1
#define STD_OUT stdout
#define STR_ERR stderr
#define LOG_MESSAGE(prio, stream, msg, ...) do {\
				char *str;\
				if(prio==INFO)\
					str="INFO";\
				else if (prio==ERR)\
					str = "ERR";\
				fprintf(stream, "[%s] : %s : %d : "msg" \n",\
					str,__FILE__,__LINE__,##__VA_ARGS__);\
			} while (0)


QuickSort:
qsort(), used to sort an array
qsort prototype: void qsort (void* base, size_t num, size_t size, int (*comparator)(const void*, const void*));

in C++:
sort() sorts elements in ascending order
takes 2 params: beginning of array and length of array which we want to be sorted
main(){
int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 0};
int n = sizeof(arr) / sizeof(arr[0]);
sort(arr, arr + n);
for (int i; i<n; i++)
	cout<<arr[i]<<" ";
return 0;
}

greater() func to sort in descending order:
ex. sort(arr, arr+n, greater<int>());

Custom order:
create your own function to compare:
struct Interval { int start, end; };
bool compareInterval(Interval i1, Interval i2) { return i1.start < i2.start); }
	// any boolean expression can be used. here, if return statement is true, then i1 is before i2
int main () {
	...
	sort(arr, arr+n, compareInterval);

Vector in C++:
Dynamic arrays with the ability to resize automatically
contiguous storage
Iterators:
begin()		iterator pointing at first element
end()		iterator pointing at theoretical element that follows last element
rbegin()	reverse iterator pointed at last element, moves backwards
rend()		reverse iterator pointing to the theoretical element preceding the first element
cbegin()	constant iterator pointing to first element
cend()		constant iterator pointing to theoretical element following last
crbegin()	constant reverse iterator pointing to last element
crend()		constant reverse iterator pointing to theoretical element preceding first

int main() {
	vector<int> g1;
	for (int i = 1; i<=5; i++)
		g1.push_back(i);

Output of begin and end: 1 2 3 4 5 
Output of cbegin and cend: 1 2 3 4 5 
Output of rbegin and rend: 5 4 3 2 1 
Output of crbegin and crend : 5 4 3 2 1

ore operations for vectors:
size()		num of elements
max_size()	max number of elements vector can hold
capacity()	size of storage space allocated to vector
resize(n)	resizes the container so it has 'n' elements
empty()		returns whether the container is empty or not
shrink_to_fit()	reduces capacity of container to fit its size destroys elements past its capacity
reserve()	requests that vector capacity can be at least enought to contain n elements

Element access:
reference operator[g]	returns a reference to the element at position 'g' in vector
at(g)			returns a ref to the element at position 'g'
front()			returns a ref to first element
back()			returns ref to last element
data()			returns a direct pointer to the memory array used internally

odifiers:
assign()	assignes new val to vector elements by replacing old ones
push_back()	push elements into vector from back
pop_back()	pop or remove elements from back of vector
insert()	inserts new elements before element at specified pos
erase()		used to remove element from a specified pos or range
swap()		swap contents of one vector with another of same size. sizes may differ
clear()		used to remove all elements
emplace()	extends the container by instering new element at position
emplace_back()	insert new element into vector at the end

Queues in STL:
containers that operate in first in first out (FIFO) arrangement
elements are inserted from back and deleted from front
any similar functions to vectors
pop() 		deletes first element
push(g)		adds 'g' to back
emplace()	inserts a new element in queue container to end
swap()		exchange contents of two queues of same type, may differ in size
empty()		returns whether queue is empty or not
front()		returns ref to first element
back()		returns ref to last element

Priority Queue in C++ STL:
first element of queue is greatest of all elements in queue
Automatically orders elements in descending order
priority_queue<int> gquiz;
gquiz.push(10);

Reverse order: priority_queue<int, vector<int>, greater<int>> gquiz;
		gquiz.push(10);

Double Ended Queues (deques)
sequence containers can can expand and contract at both ends
similar to vectors but more efficient in cases of inserion and deletion of elements
same functions as vectors but with: 
	push_front() and pop_front()
which allow them to be modified in both directions
SYNTAX:
deque<int> gquiz;
gquiz.push_back(10);
gquiz.push_front(20);
gquiz.push_back(30);
qguiz.push_front(15);



File Handling through C++ Classes:
files are dealt through: fstream, ifstream, ofstream available in fstream header file

ofstream: 	stream class to write on files
ifstream:	stream class to read from files
fstream:	stream class to both read and write from/to files

open file by using constructor:
ifstream (const char* filename,ios_base::openmode mode=ios_base::in);
ifstream fin(filename, openmode) by default openmode = ios::in
ifstream fin("filename");

open file by using open method:
calling default constructor
ifstream fin;
fin.open(filename, openmode)
fin.open("filename");

Open Modes:
in*	input	file open for reading: the internal stream buffer supports input operations
out	output	file open for writing: the internal stream buffer supports output operations
binary	binary	operators are performed in binary rather than text
ate	at end	the output position starts at the end of he file
app	append	all output operations happen at the end of the file, appending to its existing contents
trunc	truncate	any contents that existed in the file before its open are discarded

default open modes:
ifstream	ios::in
ofstream	ios::out
fstream		ios::in | ios::out

IFSTREAM AND OFSTREAM CLASSES:
#include <fstream>
using namespace std;
int main(){
	ofstream fout;
	string line;
	fout.open("sample.txt");
	//ios::out automatically deletes content of file. to append, write
	//fout.open("sample.txt", ios::app);

	while (fout){
		// read a line from standard input
		getline(cin,line);
		//press -1 to exit
		if (line=="-1")
			break;
		//write line in file
		fout<<line<<endl;
	}
	fout.close();
	//creation of ifstream class object to read file
	ifstream fin;
	//by default open mode = ios::in mode
	fin.open("sample.txt");
	//execute a lop until EOF
	while (fin) {
		//read a line from file
		getline(fin, line);
		//print line in console
		cout << line << endl;
	}
	fin.close();
	return 0;
}
	
just FSTREAM class:
#include <fstream>
using namespace std;
int main() {
	//creation of fstream class obj
	fstream fio;
	string line;
	//ios::in and ios::out by deafult, so it deletes previous file
	//use fio.open("sample.txt", ios:in|ios:out|ios::app); to append to file
	fio.open("sample.txt, ios:truc|ios:out|ios::in); 
	//execute a loop if opened
	while (fio){
		//read a line from standard input
		getline(cin, line);
		//press "-1" to exit
		if (line=="-1")
			break;
		fio<<line<<endl;
	}
	//execute a loop until EOF
	fio.seekg(0, ios::beg);
	while (fio) {
		getline(fio, line);
		cout << line << endl;
	}
	fio.close();
	return 0;
}

Read/write class objects from/to file in C++:
to write objects data members in a file:
//file_obj is an object of ofstream
file_obj.write((char *) & class_obj, sizeof(class_obj));

to read files data member into an object:
//file_obj is an object of ifstream
file_obj.read((char *) & class_obj, sizeof(class_obj));

#include <iostream>
#includefstream
using namespacestd;
class Contestant{
public:
	string Name;
	int Age, Ratings;
	int input();
	int output_highest_rated();
};

int Contestant::input() {
	ofstream file_obj; //make file_obj of ofstream class
	file_obj.open("Input.txt", ios::app);
	Contestant obj; //make obj of Contestant class
	string str = "Michael";
	int age = 18, ratings = 2500
	obj.Name = str;
	obj.Age = age;
	obj.Ratings = ratings;
	//writing objects data to file
	file_obj.write((char*)&obj,sizeof(obj));
	
	str = "Terry";
	age = 21;
	ratings = 3200;
	obj.Name = str;
	obj.Age = age;
	obj.Ratings = ratings;
	file_obj.write((char*)&obj, sizeof(obj));
	return 0;
}
int Contestant::output_highest_rated() {
	ifsteam file_obj; //make file_obj of ifstream class
	file_obj.open("Input.txt", ios::in);
	Contestant obj;
	file_obj.read((char*)&obj,sizeof(obj));
	int max = 0;
	string Highest_rated;
	while (!file.obj.eof()) {
		if(obj.Ratings > max) {
			max = obj.Ratings
			Highest_rated = obj.Name;
		}
		file_obj.read((char*)&obj,sizeof(obj));
	}
	cout << Highest_rated;
	return 0;
}
int main() {
	Contestant object;
	object.input();
	object.output_highest_rated();
	return 0;
}


C++ Program to create a file:
#include <bits/stdc++.h>
using namespace std;
int main() {
	fstream file;
	file.open("gfg.txt", ios::out);
	if(!file) {
		cout<<"Error in creating file!!!";
		return 0;
	}
	cout<<"File created successfully";
	file.close;
	return 0;
}

CSV file management using C++:
data fields are deliminated by ,
rows are separated by newline

create operation:
void create()
{
	fstream fout;	
	fout.open("reportcard.csv",ios::out | ios::app);
	cout<<"Enter the details of 5 studetns:"<<" roll name maths phys chem bio";
	<<endl;
	int i, roll, phy, chem, math, bio;
	string name;

	for (i=0; i<5; i++) {
		cin >> roll >> name >> math >> phy >> chem >> bio;

	fout << roll << ", " << name << ", " << math << ", " << phy << ", " << chem << ", " << bio << "\n";
	}
}

Read a particular record
void read_record()
{	
	fstream fin;
	fin.open("reportcard.csv", ios::in);
	int rollnum, roll2, count = 0;
	cout<< "Enter the roll number of student to display details: ";
	cin >> rollnum;
	
	vector<string> row;
	string line, word, temp;
	while(fin >> temp){
		row.clear();
		getline(fin, line);
		stringstream s(line);
		while (getline(s,word,', ')){
			row.push_back(word);
		}
		roll2. stoi(row[0]);
		if (roll2==rollnum) {
			// Print the found data
            		count = 1;
           	 	cout << "Details of Roll " << row[0] << " : \n";
            		cout << "Name: " << row[1] << "\n";
            		cout << "Maths: " << row[2] << "\n";
            		cout << "Physics: " << row[3] << "\n";
            		cout << "Chemistry: " << row[4] << "\n";
            		cout << "Biology: " << row[5] << "\n";
            		break;
		}
		
	}
	if (count == 0)
		cout<< "Record not found\n");
}
		
Update a record:
void update_recode()
{
  
    // File pointer
    fstream fin, fout;
  
    // Open an existing record
    fin.open("reportcard.csv", ios::in);
  
    // Create a new file to store updated data
    fout.open("reportcardnew.csv", ios::out);
  
    int rollnum, roll1, marks, count = 0, i;
    char sub;
    int index, new_marks;
    string line, word;
    vector<string> row;
  
    // Get the roll number from the user
    cout << "Enter the roll number "
         << "of the record to be updated: ";
    cin >> rollnum;
  
    // Get the data to be updated
    cout << "Enter the subject "
         << "to be updated(M/P/C/B): ";
    cin >> sub;
  
    // Determine the index of the subject
    // where Maths has index 2,
    // Physics has index 3, and so on
    if (sub == 'm' || sub == 'M')
        index = 2;
    else if (sub == 'p' || sub == 'P')
        index = 3;
    else if (sub == 'c' || sub == 'C')
        index = 4;
    else if (sub == 'b' || sub == 'B')
        index = 5;
    else {
        cout << "Wrong choice.Enter again\n";
        update_record();
    }
  
    // Get the new marks
    cout << "Enter new marks: ";
    cin >> new_marks;
  
    // Traverse the file
    while (!fin.eof()) {
  
        row.clear();
  
        getline(fin, line);
        stringstream s(line);
  
        while (getline(s, word, ', ')) {
            row.push_back(word);
        }
  
        roll1 = stoi(row[0]);
        int row_size = row.size();
  
        if (roll1 == rollnum) {
            count = 1;
            stringstream convert;
  
            // sending a number as a stream into output string
            convert << new_marks;
  
            // the str() converts number into string
            row[index] = convert.str();
  
            if (!fin.eof()) {
                for (i = 0; i < row_size - 1; i++) {
  
                    // write the updated data
                    // into a new file 'reportcardnew.csv'
                    // using fout
                    fout << row[i] << ", ";
                }
  
                fout << row[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()) {
                for (i = 0; i < row_size - 1; i++) {
  
                    // writing other existing records
                    // into the new file using fout.
                    fout << row[i] << ", ";
                }
  
                // the last column data ends with a '\n'
                fout << row[row_size - 1] << "\n";
            }
        }
        if (fin.eof())
            break;
    }
    if (count == 0)
        cout << "Record not found\n";
  
    fin.close();
    fout.close();
  
    // removing the existing file
    remove("reportcard.csv");
  
    // renaming the updated file with the existing file name
    rename("reportcardnew.csv", "reportcard.csv");
}

Delete a record:
void delete_record()
{
  
    // Open FIle pointers
    fstream fin, fout;
  
    // Open the existing file
    fin.open("reportcard.csv", ios::in);
  
    // Create a new file to store the non-deleted data
    fout.open("reportcardnew.csv", ios::out);
  
    int rollnum, roll1, marks, count = 0, i;
    char sub;
    int index, new_marks;
    string line, word;
    vector<string> row;
  
    // Get the roll number
    // to decide the data to be deleted
    cout << "Enter the roll number "
         << "of the record to be deleted: ";
    cin >> rollnum;
  
    // Check if this record exists
    // If exists, leave it and
    // add all other data to the new file
    while (!fin.eof()) {
  
        row.clear();
        getline(fin, line);
        stringstream s(line);
  
        while (getline(s, word, ', ')) {
            row.push_back(word);
        }
  
        int row_size = row.size();
        roll1 = stoi(row[0]);
  
        // writing all records,
        // except the record to be deleted,
        // into the new file 'reportcardnew.csv'
        // using fout pointer
        if (roll1 != rollnum) {
            if (!fin.eof()) {
                for (i = 0; i < row_size - 1; i++) {
                    fout << row[i] << ", ";
                }
                fout << row[row_size - 1] << "\n";
            }
        }
        else {
            count = 1;
        }
        if (fin.eof())
            break;
    }
    if (count == 1)
        cout << "Record deleted\n";
    else
        cout << "Record not found\n";
  
    // Close the pointers
    fin.close();
    fout.close();
  
    // removing the existing file
    remove("reportcard.csv");
  
    // renaming the new file with the existing file name
    rename("reportcardnew.csv", "reportcard.csv");
}

Four file handling hacks:
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Function to get file size:
unsigned long long int fileSize(const char *filename)
{
	FILE *fh = fopen(filename, "rb");
	fseek(fh, 0, SEEK_END);
	unsigned long long int size = ftell(fh);
	fclose(fh);
	return(size);
}
//Function to tell if file exists or not
bool fileExists(const char * fname)
{
	FILE *file;
	if (file=fopen(fname), 'r'))
	{
		fcloe(file);
		return(true);
	}
	return (false);
}
//Driver program to test functions:
int main()
{
	printf(%llu Bytes\n, fileSize("Passwords.txt"));
	if (fileExists("OldData.txt"))
		printf("File exists\n");
	else
		printf("File does not exist\n");
	//Rename files
	rename("Videos", "English_Videos");
	
	//Remove files
	remove("OldData.txt");


Library in C++ STL:
all functions are of std:: scope unless specified

Non-modifying sequence operations
all_of		test condition on all elements in range
any_of		test if any element in range fulfills cond
none_of		test if no elements fulfill cond
for_each	apply function to range
find		find value in range
find_if		find element in range
find_if_not	find element in range (negative cond)
find_end	find las subsequence in range
find_first_of	find element from set in range
adjacent_find	find equal adjacent elements in range
count		count appearances of value in range
cout_if		return number of elements in range
mismatch	return first position where two ranges differ
equal		test whether elements in two rangers are equal
is_permutation	test whether range is permutation of another
search		search range for subsequence
search_n	search range for element

odifying sequence operations
copy		copy range of elements
copy_n		copy elements
copy_if		copy certain elements of range
copy_backward	copy range of elements backward
move		move range of elements
move_backward	move range of elemens backward
swap		exchange values of two objects
swap_ranges	exchange values of two ranges
iter_swap	exhange values of objects pointed by two iterators
transform	transform range
replace		replace value in range
replace_if	replace values in range
replace_copy	copy range replacing value
replace_copy_if	copy range replacing value
fill		fill range with value
fill_n		fill sequence with value
generatge	generate values for range with function
generate_n	generate values for sequence with function
remove		remove value from range
remove_if	remove elements from range
remove_copy	copy range removing value // not std::
remove_copy_if	copy range removing values // not std::
unique		remove consecutive duplicates in range
unique_copy	copy tange removing duplicates
reverse		reverse range
reverse_copy	copy range reserved
rotate		rotate left the elements in range
rotate_copy	copy range rotated left
random_shuffle	randomyl rearrange elements in range
shuffle		randomly rearrange elements in range using generator

Partition operations
is_partitioned	test whether range is partitioned
partition	partition range in two
stable_partition	partition range in two-stable ordering
partition_copy	partition range into two // not std::
partition_point	getting partition point // not std::

Sorting
sort		sort elements in range
stable_sort	sort elements preserving order of equivalents
partial_sort	partially sort elements in range
partial_sort_copy	copy and partially sort range
is_sorted	check whether range is sorted
is_sorted_until	find first unsorted element in range
nth_element	sort element in range

Binary Search (operating on partitioned/sorted ranges)
lower_bound	return iterator to lower bound
upper_bound	return iterator to upper bound
equal_range	get subrange of equal elements
binary_search	test if value exists in sorted subsequence

erge (operating on sorted ranges)
merge		merge sorted ranges
inplace_merge	merge consecutive sorted ranges
includes	test whether sorted range includes another sorted range
set_union	union of two sorted ranges
set_intersection	intersection of two sorted ranges
set_difference	difference of two sorted ranges
set_symmetric_differences	symmetric difference of two sorted ranges

Heap Operations
push_heap	push element into heap range
pop_heap	pop element from heap range
make_heap	make heap from range
sort_heap	sort elements of heap
is_heap		test if range is heap
is_heap_until	find first element not in heap order
max		return the largest
minmax		return smalles and largest elements
min_element	return smallest element in range
max_element	return largest element in range
minmax_element	return smalles and largest elements in range

Other operations
lexicongraphical_compare	lexicographical less-than compare
next_permutation	transform range to next permutation
prev_permutation	transform range to previous permutation

