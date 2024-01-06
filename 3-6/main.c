/**
 * The task
 *
 * Write a version of `itoa` that accepts three arguments instead of two. The
 * third argument is a minimum field width; the converted number must be padded
 * with blanks on the left if necessary to make it wide enough.
 * */

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

void itoa(int n, char s[], int w);
void reverse(char s[]);
void run_test(int n, int w, char result[]);

int main(void) {
    run_test(123, 10, "       123");
    run_test(12345, 3, "12345");
    return 0;
}

void run_test(int n, int w, char result[]) {
    char s[100];

    itoa(n, s, w);

    printf("\n-----\n");
    printf("Decimal: %d, min width: %d\n", n, w);
    printf("Result: |%s|\n", s);
    assert(!strcmp(s, result));
}

void itoa(int n, char s[], int w) {
    int i, sign;

    if (n == INT_MIN) {
        n++;
    } else if (n == INT_MAX) {
        n--;
    }

    if ((sign = n > 0 ? 1 : -1) < 0) {
        n = -n;
    }

    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) {
        s[i++] = '-';
    }

    while (i < w) {
        s[i++] = ' ';
    }

    s[i] = '\0';
    reverse(s);

    if (n == INT_MAX || n == INT_MIN) {
        s[strlen(s) - 1] += 1;
    }
}

void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
