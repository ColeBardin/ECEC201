#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Stores parameters that specify how to the program should behave.
 *
 * Populated by the get_parms() function.	You don't really need to
 * worry about this bit.	I wrote it for you. */
struct parms {
	char *filename;
	unsigned char mode;
};

typedef struct parms Parms;



/** U S E R	 I N T E R F A C E ****************************************/


/* This function simply displays helpful usage information if the
 * program is called improperly or with no command line arguments.
 *
 * You don't need to know how this function works. */
void print_usage(const char *cmd)
{
	printf("Usage: %s MODE filename\n\n"
		"Available Modes:\n"
		"  -c     Compress: Performs RLE compression on \"filename\"\n"
		"                   and writes result to \"filename.rle\"\n\n"
		"  -x     Expand: Performs RLE expansion on \"filename\". The\n"
		"                 supplied \"filename\" must have the extension\n"
		"                 \".rle\" The result is written to \"filename\"\n"
		"                 with the extension \".rle\" removed.\n\n"
		"  -d     Debug: Prints a hexdump of \"filename\" to the screen.\n\n"
		"  -g     Generate: Writes the test file described in the Project 2\n"
		"                   assignment document to disk as \"filename\". Use\n"
		"                   this file to test and debug your program.\n\n"
		"Examples:\n"
		"  %s -c test.bin\n\tProduces RLE encoded file test.bin.rle\n"
		"  %s -x test.bin.rle\n\tExpands test.bin.rle to disk as test.bin\n"
		"  %s -d test.bin.rle\n\tDisplays raw contents of test.bin.rle\n"
		"  %s -g test.bin\n\tGenerates test file with known contents to disk as test.bin\n",
		cmd, cmd, cmd, cmd, cmd);
}


/* This function parses the command line arguments supplied in
 * argc/argv and populates the Params struct with the mode and filename
 * specified by the user on the command line.
 *
 * You don't need to know how this function works. */
int get_parms(Parms *parms, const char *modes, int argc, char **argv)
{
	int i = 0;

	if (argc != 3 || *argv[1] != '-')
		return 0;

	while (modes[i] && modes[i] != *(argv[1] + 1))
		i++;

	if ( (parms->mode = i) == strlen(modes) ) {
		fprintf(stderr, "Invalid Mode %s\n", argv[1]);
		return 0;
	}

	parms->filename = argv[2];

	return 1;
}



/** H E L P E R	 F U N C T I O N S ************************************/


/* Returns a newly allocated string on the heap containing the supplied
 * filename with the specified extension added to its end.	This
 * function effectively just concatenates two strings. */
char *filename_add_ext(const char *filename, const char *ext)
{
	/* Your code goes here! */
	int len;
	char *dst;
	/* Get the length of both strings */
	len = strlen(filename) + strlen(ext);
	/* Malloc a char ptr long enough for both strings and a null char */
	dst = malloc(len+1);
	/* Check for error in malloc call */
	if (!dst) {
		fprintf(stderr, "Error: filename_add_ext failed to malloc\n");
		return dst;
	}
	/* Copy the flename to the destination string */
	strcpy(dst, filename);
	/* Concatenate the extension to the destination string */
	strcat(dst, ext);
	/* Return address of full filename.ext */
	return dst; 
}


/* Returns a newly allocated string on the heap containing the supplied
 * filename with its extension removed.
 *
 * For example:
 *	 if `filename` contains the string "test.txt.rle", then this
 *	 function will return a string on the heap containing
 *	 "test.txt" */
char *filename_rm_ext(const char *filename)
{
	/* Your code goes here! */
	char *dst;
	int len, index;
	/* Count total length of filename string */
	len = strlen(filename);
	/* Count backwards from end of filename until hitting a period */
	for (index=len; filename[index] != '.'; index--); /* Makes index var the index of last period in filename */
	/* Malloc space up to last period of filename */
	dst = malloc(index);
	/* Check for error in malloc call */
	if (!dst) {
		fprintf(stderr, "Error: filename_rm_ext failed to malloc\n");
		return dst;
	}
	/* Copy the characters from the filename excluding the extension (index # of chars) */
	strncpy(dst, filename, index);
	/* Return memory address of filename without ext on HEAP */
	return dst;
}


/* This function returns zero if the supplied filename does not have the
 * extension ".rle"; otherwise it returns a non-zero value. */
int check_ext(const char *filename)
{
	/* Your code goes here! */
	int len;
	/* Get the string length */
	len = strlen(filename);
	/* Compare last 4 chars of filename to ".rle" */
	if (!strcmp(&filename[len-4], ".rle"))
		/* Return 1 if they match */
		return 1;
	else
		/* Return 0 if filename does not end with ".rle" */
		return 0;
}


/* This function returns zero if the supplied file does not have the
 * !RLE "magic" byte sequence as its first four bytes; otherwise it
 * returns a non-zero value. */
int check_magic(FILE *fp)
{
	/* Your code goes here! */
	char dst[] = "0000"; /* Create dst string with 4 chars and a NULL char */
	char rle[] = "!RLE";
	int ret;
	/* Attempt to read 4 bytes from filepointer */
	ret = fread(dst, sizeof(*dst), 4, fp);
	if (ret == 4) {
		/* If 4 bytes were read, compare them to magic byte sequence */
		if(!strcmp(dst, rle)) {
			/* Return 1 if they  match */
			return 1;
		/* Return 0 if they don't match */
		} else {
			return 0;
		}
	/* If fread failed to read 4 chars, print to stderr and return 0 */
	} else {
		fprintf(stderr, "Error: check_magic failed to retireve 4 bytes from file\n");
		return 0;
	}
}



/** M O D E S **********************************************************/


/* This function performs the run length encoding (RLE) algorithm on the
 * bytes of the specified file (which must not be modified).	The result
 * is written to a new file having the supplied filename PLUS the ".rle"
 * extension.	Called when -c is supplied for mode on the command line.
 *
 *	 For example, if the supplied filename is "test.bin", this function
 *	 should create the file "test.bin.rle", whose contents will be the
 *	 run length encoded bytes of "test.bin".
 *
 * This function is also responsible for writing the !RLE "magic" byte
 * sequence to the first four bytes of the output file, thus marking it
 * as a genuine RLE encoded file. */
void compress(const char *filename)
{
	/* Your code goes here! */
	FILE *rle_fp;
	FILE *input_fp;
	int c;
	int c_next;
	unsigned int count = 1;
	char *rle_fn = filename_add_ext(filename, ".rle");
	char magic[] = "!RLE";

	/* Open the input file with filepointer input_fp */
	input_fp = fopen(filename, "rb");
	/* Make sure filepointer is not NULL */
	if (!input_fp) {
		fprintf(stderr, "Error: compress() count not open %s in \"rb\" mode\n", filename);
		return;
	}
	/* Open the output file with filepointer rle_fp */
	rle_fp = fopen(rle_fn, "wb");
	/* Make sure filepointer is not NULL */
	if (!rle_fp) {
		fprintf(stderr, "Error: compress() could not create %s in \"wb\" mode\n", rle_fn);
		return;	
	}
	/* Write the rle magic bytes to the output file */
	fwrite(magic, sizeof(*magic), 4, rle_fp);

	/* TODO: use fwrite and fread */
	/* Get the first char of the input file */
	c = fgetc(input_fp);
	/* Repeat until hitting input file EOF */
	while ( c != EOF ) {
		/* Get the next char in input file */
		c_next = fgetc(input_fp);
		/* If current char is equal to the next char */
		if (c == c_next) {
			/* Test if count will overflow one byte */
			if ( count == 255 ) {
				/* If so, flush count and char to output file */
				fprintf(rle_fp, "%c%c", count, c);
				/* Reset count to 1 */
				count = 1;
			}
			/* If count will not overflow, increment count */
			else {
				count++;
			}
		}
		/* If next character is different */ 
		else {
			/* Flush count and char to output file */
			fprintf(rle_fp, "%c%c", count, c);
			/* Set current char to next one */
			c = c_next;
			/* Reset count to 1 */
			count = 1;	
		}
	}
	/* Close input and output file */
	fclose(rle_fp);
	fclose(input_fp);
	return;
}


/* This function performs run length decoding on the bytes of the
 * supplied filename and writes the result to disk as the contents of a
 * newly created file with the supplied filename MINUS the ".rle"
 * extension.	Called when -x is supplied for mode on the command line.
 *
 *	 For example, if the supplied filename is "test.bin.rle", this
 *	 function will create the file "test.bin", whose contents will be
 *	 the run length decoded bytes of "test.bin.rle".
 *
 * This function also checks that the supplied filename has both the
 * ".rle" extension and !RLE "magic" byte sequence.	If either is not
 * present, this function prints an appropriate error message to stderr,
 * does not create a new file, and simply returns without performing
 * any run length decoding. */
void expand(const char *filename)
{
	/* Your code goes here! */
	FILE *rle_fp;
	FILE *out_fp;
	char *count;
	char *c; 
	int i, ret;
	/* Create filename without extension */	
	char *fn = filename_rm_ext(filename);
	
	/* Malloc blocks on HEAP for fread() */
	c = malloc(sizeof(*c));
	count = malloc(sizeof(*count));

	/* Check if the provided filename the correct extension */
	if (!check_ext(filename)) {
		fprintf(stderr, "Error: expand() recieved a file with invalid expansion\n");
		return;
	}
	/* Try to open rle file */
	rle_fp = fopen(filename, "rb");
	/* Handle rle file not opening properly */
	if (!rle_fp) {
		fprintf(stderr, "Error: expand() could not open .rle file\n");
		return;
	}
	/* Try to create output file */
	out_fp = fopen(fn, "wb");
	/* Handle output file not opening properly */
	if (!out_fp) {
		fprintf(stderr, "Error: expand() could not create output file\n");
		return;
	}
	/* Check to make sure file has proper magic bytes */
	if (!check_magic(rle_fp)) {
		fprintf(stderr, "Error: expand() recieved a file without !RLE magic bytes\n");
		return;
	}

	printf("read first 4 chars\n");	
	while ( 1 ) {
		/* Read count from file */
		ret = fread(count, sizeof(*count), 1, rle_fp);
		/* If read is not successful (EOF), break loop */
		if ( ret != 1 ) {
			break;
		}
		/* Read char from file */
		ret = fread(c, sizeof(*c), 1, rle_fp);
		/* If read is not successful (EOF), break loop */
		if (ret != 1) {
			break;
		}
		/* Use fwite() */
		/* Write the char to the file count times */
		for (i=0; i<*count; i++) {
			fprintf(out_fp, "%c", *c);
		}
	}
	/* Free memory on HEAP for allocated for char and count variables */
	free(c);
	free(count);
	/* Close both files */
	fclose(rle_fp);
	fclose(out_fp);
	return;
}


/* This function prints a raw byte dump of the specified file to the
 * screen.	Called when -d is supplied for mode on the command line.
 * This allows you to look at the raw bytes of any file you want, which
 * should very much help you debug your program.
 *
 * You don't need to know how this function works. */
void debug(const char *filename)
{
	unsigned char b[16];
	unsigned int nbytes, i;

	unsigned int offset = 0;
	FILE *fp = fopen(filename, "rb");

	if (!fp) {
		fprintf(stderr, "error -- failed to open file '%s'\n", filename);
		return;
	}

	while ( (nbytes = fread(b, sizeof(*b), 16, fp)) > 0 ) {
		printf("%08x: ", offset);
		for (i=0; i<16; i++) {
			i   < nbytes ? printf("%02x", b[i])  : printf("  ");
			++i < nbytes ? printf("%02x ", b[i]) : printf("   ");
		}

	  printf(" ");

	for (i=0; i<nbytes; i++)
		printf("%c", isprint(b[i]) ? b[i] : '.');

		printf("\n");
		offset += 16;
	}

	fclose(fp);
}


/* This function generates the test file discussed in the Project
 * description document.	Called when -g is supplied for mode on the
 * command line.	This provides a file you understand the contents of,
 * which should very much help you debug your program.
 *
 * You don't need to know how this function works. */
void generate(const char *filename)
{
	FILE *fp = fopen(filename, "wb");
	unsigned char test[] =
	  "\xee\x5d\x41\x41\x41\x8e\x2a\x3a\x3a\x3a\x3a\xe8\xbd"
	  "\x22\x88\x0a\xac\xac\xac\x9a\x51\x3a\x3a\x3a\xaa\xaa"
	  "\xaa\x31\x61\x27\xa7\x7e\x6d\x52\xd8\x74\x6a\x6f\x6e"
	  "\x4e\xe8\x90\xa0\x7d\x88\x64\x12\x21\xdb\xae\xf7\xf7"
	  "\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7"
	  "\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7"
	  "\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7"
	  "\xf7\xf7\xf7\xf7\xf7\xaa\xaa\xbb\xbb";

	if (!fp) {
		fprintf(stderr, "error -- failed to open '%s'\n", filename);
		return;
	}

	if (1 != fwrite(test, sizeof(test) - 1, 1, fp))
		fprintf(stderr, "failed to write '%s' (oh no!)\n", filename);

	fclose(fp);
}



/** M A I N ************************************************************/


int main(int argc, char **argv)
{
	Parms parms;

	/* simply an array of function pointers */
	void (*action[])(const char *filename) = {
		compress,
		expand,
		debug,
		generate
	};

	/* get mode and filename from command line arguments;
	 * prints the usage and exits if improper arguments are supplied */
	if(!get_parms(&parms, "cxdg", argc, argv)) {
		print_usage(argv[0]);
		return EXIT_FAILURE;
	}

	/* call the function for the specified mode and pass
	 * it the filename supplied at the command line */
	action[parms.mode](parms.filename);

	return 0;
}
