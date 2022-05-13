#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


/* prints a line of 10 bytes (max) in hex with a space between each byte */
void print_bytes_hex(unsigned char *b, unsigned int nbytes)
{
	unsigned int i;
	for (i=0; i<nbytes; i++) {
		printf("%02x ", b[i]);
	}
	for (; i<10; i++) {
		printf("   ");
	}
	printf(" ");
	return;
}


/* prints a line of 10 bytes (max) in as characters.
 * non-printable bytes are printed as the period character. */
void print_bytes_char(unsigned char *b, unsigned int nbytes)
{
	unsigned int i;
	for (i=0; i<nbytes; i++){
		if (isprint(b[i]))
			printf("%c", b[i]);
		else
			printf(".");
	}
	return;
}


int main()
{
	FILE *fp;
	unsigned char buffer[10];
	char fn[] = "ascii_chars.txt";
	unsigned int ret, offset, dig, temp;
	fp = fopen(fn, "rb");
	if (!fp) {
		fprintf(stderr, "Failed opening %s\n", fn);
		return EXIT_FAILURE;
	}

	printf("Offset              Bytes              Characters\n");
	printf("------  -----------------------------  ----------\n");

	offset = 0;
	while ( (ret = fread(buffer, sizeof(*buffer), 10, fp)) ) {
		/* TODO: look up if there is a way to pad zeroes to be 6 chars total */
		temp = offset;
		dig = 0;
		do {
			temp /= 10;
			dig++;
		} while (temp);
		for (temp = 0; temp<6-dig; temp++) {
			printf(" ");
		} 
		printf("%d  ", offset);
		print_bytes_hex(buffer, ret);
		print_bytes_char(buffer, ret);
		printf("\n");
		offset += 10;
	}
	fclose(fp);
	return 0;
}
