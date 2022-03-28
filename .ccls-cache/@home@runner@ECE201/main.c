#include <stdio.h>
#include <string.h>

#define CHAR_MAX (5)

int main(void) {
    char var0[CHAR_MAX];
    int ret_val = scanf(var0, CHAR_MAX);
    printf("%s\n",var0);
    
    return 0;
}