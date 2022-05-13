#include <stdio.h>
#include <stdlib.h>

#define BUFF_SIZE	(32)

int main()
{
	/* Your code goes here! */
	FILE *fp_l, *fp_o;
	char fn_l[] = "lorum.txt";
	char fn_o[] = "count.txt";
	int line, count, c;

	fp_l = fopen(fn_l, "r");
	if (!fp_l) {
		fprintf(stderr, "Failed to open %s\n", fn_l);
		return EXIT_FAILURE;
	}

	fp_o = fopen(fn_o, "w");
	if (!fp_o) {
		fprintf(stderr, "Failed to open %s\n", fn_o);
		return EXIT_FAILURE;
	}

	line = 1;
	count = 0;
	while ( (c = fgetc(fp_l)) != EOF ) {
		if (c == '\n') {
			printf("%d: %d\n", line, count);
			fprintf(fp_o, "%d: %d\n", line, count);
			line++;
			count = 0;
		} else {
			count++;
		}
	}	
	
	fclose(fp_o);
	fclose(fp_l);
	return 0;
}
