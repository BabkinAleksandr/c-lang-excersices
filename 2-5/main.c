#include <stdio.h>
#include <stdlib.h>

#define LENGTH 100

signed int any(char s1[], char s2[]);

int main(void) {
    char s1[LENGTH];
    char s2[LENGTH];
    signed int result;

    printf("Enter the source string\n");
    fgets(s1, sizeof(s1), stdin);

    printf("Enter the set of characters to find in the source:\n");
    fgets(s2, sizeof(s2), stdin);

    result = any(s1, s2);

    if (result == -1) {
        printf("No occurrences found\n");
    } else {
        printf("The position of first occurence is: %d\n", result);
    }

    return 0;
}

/** Finds position of first occurrence of any character from s2
 * in s1, or -1 if no occurrences was found */
signed int any(char s1[], char s2[]) {
    int i, j;

    for (i = 0; s1[i] != '\0' && s1[i] != '\n'; i++) {
        // yeah, I know, loop inside loop...
        for (j = 0; s2[j] != '\0' && s2[j] != '\n'; j++) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }

    return -1;
}
