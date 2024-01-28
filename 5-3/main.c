/**
 * The task
 *
 * Write a pointer versuib if the fybctuin `strcat` that we showed in Chapter2:
 * `strcat(s,t)` copies the string `t` to the end of `s`.
 * */

#include <assert.h>
#include <string.h>

void strcat_(char *, char *);

int main(void) {
    char s[100] = "hello,";
    char t[] = " world!";

    strcat_(s, t);

    assert(strcmp(s, "hello, world!") == 0);
    return 0;
}

void strcat_(char *s, char *t) {
    while (*s++)
        ;
    s--; // decrement to rewrite '\0' symbol
    while ((*s++ = *t++))
        ;
}
