#include <stdio.h>
#include <stdlib.h>

#define LENGTH 100

char *squeeze(char s1[], char s2[]);

int main(void) {
    char s1[LENGTH];
    char s2[LENGTH];
    char *result;

    printf("Enter the source string\n");
    fgets(s1, sizeof(s1), stdin);

    printf("Enter the set of characters to delete from the source\n");
    fgets(s2, sizeof(s2), stdin);

    result = squeeze(s1, s2);

    printf("The result is: %s\n", result);

    return 0;
}

/** Removes any character from s1 if it appears in s2 and returns pointer to
 * resulted string */
char *squeeze(char s1[], char s2[]) {
    char *result = (char *)malloc(sizeof(char) * LENGTH);
    int i, j, k;

    k = 0;
    for (i = 0; s1[i] != '\0'; i++) {
        // yeah, I know, loop inside loop...
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j])
                break;
        }
        // if j counter points to the end of s2 string
        // it means no occurences of char was found
        if (s2[j] == '\0') {
            result[k++] = s1[i];
        }
    }

    result[k] = '\0';

    return result;
}
