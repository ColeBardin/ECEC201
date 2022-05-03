#include "strlib.h"

int my_strlen(const char *str){
	int len = 0;
	/* Increment len variable and index the string by it until reaching the null char */
	while ( str[len] != '\0' ){
		len++;
	}
	/* Return lenght of chars before null char in string */
	return len;
}

int my_strcmp(const char *str1, const char *str2) {
	int index = 0;
	/* Repeat until a null char is reached in either string */
	while ( (str1[index] != '\0') || (str2[index] != '\0') ) {
		/* Compare characters at the current. If different, return their difference */
		if ( str1[index] - str2[index] != 0 )
			return str1[index] - str2[index];
		/* Increment index */
		index++;
	}
	/* If program has not yet return, return the difference between the last two chars */
	return str1[index] - str2[index];
}
