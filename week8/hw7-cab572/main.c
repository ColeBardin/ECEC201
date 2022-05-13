#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


/* prints a line of 10 bytes (max) in hex with a space between each byte */
void print_bytes_hex(unsigned char *b, unsigned int nbytes)
{
	unsigned int i;
	/* Print each byte from the buffer */
	for (i=0; i<nbytes; i++) {
		printf("%02x ", b[i]);
	}
	/* If nbytes was less than 10, fill whitespace for char placement */
	for (; i<10; i++) {
		printf("   ");
	}
	/* Print extra space to separate cols */
	printf(" ");
	return;
}


/* prints a line of 10 bytes (max) in as characters.
 * non-printable bytes are printed as the period character. */
void print_bytes_char(unsigned char *b, unsigned int nbytes)
{
	unsigned int i;
	/* Print each character in the buffer */
	for (i=0; i<nbytes; i++){
		/* If it's printable convert int to char */
		if (isprint(b[i]))
			printf("%c", b[i]);
		/* If non-printable, print '.' */
		else
			printf(".");
	}
	/* Print extra newline for next sequence */
	printf("\n");
	return;
}


int main()
{
	FILE *fp;
	unsigned char buffer[10];
	char fn[] = "ascii_chars.txt";
	unsigned int ret, offset, dig, temp;
	offset = 0;
	/* Open the input file in Binary Read mode */
	fp = fopen(fn, "rb");
	/* Check if filepont is NULL ptr */
	if (!fp) {
		/* If so, display error to stderr and exit */
		fprintf(stderr, "Failed opening %s\n", fn);
		return EXIT_FAILURE;
	}

	printf("Offset              Bytes              Characters\n");
	printf("------  -----------------------------  ----------\n");

	/* Read file binary to buffer until it returns NULL */
	while ( (ret = fread(buffer, sizeof(*buffer), 10, fp)) ) {
		/* TODO: look up if there is a way to pad zeroes to be 6 chars total */
		temp = offset;
		dig = 0;
		do {
			temp /= 10;
			dig++;
		} while (temp);
		/* Print respective whitespace for offset integer */
		for (temp = 0; temp<6-dig; temp++) {
			printf(" ");
		} 
		/* Print Offset and end spacing */
		printf("%d  ", offset);
		/* Call functions to print hex and char */
		print_bytes_hex(buffer, ret);
		print_bytes_char(buffer, ret);
		offset += 10;
	}
	/* Close the filepointer */
	fclose(fp);
	return 0;
}
