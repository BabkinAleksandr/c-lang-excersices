/**
 * The task
 *
 * Write a function `expand(s1, s2)` that expands shorthand
 * notations like `a-z` in the string `s1` into the equivalent complete
 * list `abc...xyz` in `s2`. Allow for letters of either case and digits,
 * and be prepared to handle cases like `a-b-c` and `a-z0-9` and `-a-z`.
 * Arrange that a leading or trailing `-` is taken literally.
 * */

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void expand(char s1[], char s2[]);
void fill(char s[], int p, char from, char to);
void run_test(char s1[], char result[]);

int main(void) {
    run_test("a-z", "abcdefghijklmnopqrstuvwxyz");
    run_test("a-b-c", "abc");
    run_test("a-z0-9", "abcdefghijklmnopqrstuvwxyz0123456789");
    run_test("-a-z", "-abcdefghijklmnopqrstuvwxyz");
    run_test("helloa-zhello", "helloabcdefghijklmnopqrstuvwxyzhello");
    run_test("string", "string");

    return 0;
}

void run_test(char s1[], char result[]) {
    char s2[100];

    printf("\n-----\n");
    printf("String before:\n%s\n", s1);

    expand(s1, s2);
    printf("Result:\n%s\n", s2);
    assert(!strcmp(s2, result));
}

/** Expands folded sequences like `a-z` and `0-9` to full ones like `abc...xyz`
 * Takes string from s1 and writes it to s2
 * */
void expand(char s1[], char s2[]) {
    int i, k;

    for (i = 0, k = 0; s1[i] != '\0' && s1[i] != '\n'; i++, k++) {
        if (s1[i] == '-' && i > 0) {
            if (isalnum(s1[i - 1]) && isalnum(s1[i + 1])) {
                fill(s2, k - 1, s1[i - 1], s1[i + 1]);
                k += s1[i + 1] - s1[i - 1] - 1;
                i++;
                continue;
            }
        }

        s2[k] = s1[i];
    }

    s2[k] = '\0';
}

/** Fills string s from index p with char sequence */
void fill(char s[], int p, char from, char to) {
    int i;
    for (i = 0; from + i <= to; i++) {
        s[p + i] = from + i;
    }
}
