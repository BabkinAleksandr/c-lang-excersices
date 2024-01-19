/**
 * The task
 *
 * Write the function `strrindex(s, t)`, which returns the position of the
 * rightmost occurrence of `t` in `s`, or `-1` if there is none
 * */

#include <assert.h>
#include <stdio.h>
#include <string.h>

int strrindex(char source[], char searchfor[]);

int main() {
    printf("Starting tests...\n");

    assert(strrindex("1231234512345", "123") == 8);
    assert(strrindex("abcdefghijk", "k") == 10);
    assert(strrindex("abcdefg", "bcdefgh") == -1);
    assert(strrindex("abc", "") == -1);
    assert(strrindex("", "123") == -1);

    printf("Tests completed successfully!\n");

    return 0;
}

int strrindex(char s[], char t[]) {
    int i, j, k, t_length;
    t_length = strlen(t);

    for (i = strlen(s) - 1; i >= 0; i--) {
        for (j = i, k = t_length - 1; j >= 0 && k >= 0 && s[j] == t[k];
             j--, k--)
            ;

        if (k < 0 && t_length > 0) {
            return i - t_length + 1;
        }
    }

    return -1;
}
