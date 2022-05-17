#include <stdio.h>

int main()
{
	FILE *fp_l, *fp_o;
	char fn_l[] = "lorum.txt";
	char fn_o[] = "count.txt";
	int line, count, c;

	/* Open lorum.txt in Read mode to fp_l file pointer */
	fp_l = fopen(fn_l, "r");
	/* Check if the file pointer is void */
	if (!fp_l) {
		/* If so, print error to stderr and exit */
		fprintf(stderr, "Failed to open %s\n", fn_l);
		return -1;
	}

	/* Open count.txt in Write mode to fp_o file pointer */
	fp_o = fopen(fn_o, "w");
	/* Check if the file pointer is void */
	if (!fp_o) {
		/* If so, print error to stderr and exit */
		fprintf(stderr, "Failed to open %s\n", fn_o);
		return -1;
	}

	line = 1;
	count = 0;
	/* Get each character of the file until reaching EOF */
	while (1) {
		c = fgetc(fp_l);
		if (c == EOF) {	
			printf("%d: %d\n", line, count);
			/* Write the final  line and char data to count.txt */
			fprintf(fp_o, "%d: %d\n", line, count);
			/* Break out of for loop */
			break;
		} else if (c == '\n') {
		/* If the character pulled is a newline */
			printf("%d: %d\n", line, count);
			/* Write the current line and char data to count.txt */
			fprintf(fp_o, "%d: %d\n", line, count);
			/* Increment line number and reset character count */
			line++;
			count = 0;
			fflush(fp_o);
			fflush(stdout);
		} else if (c != '\r') {
			/* Increment character count if char is anything other than newline */
			count++;
		}
	}
	
	/* After parsing entire lorum.txt file, close both file pointers */
	fclose(fp_o);
	fclose(fp_l);
	return 0;
}
