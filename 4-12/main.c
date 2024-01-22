/**
 * The task
 *
 * Adapt the ideas of `printd` to write a recursive version of `itoa`; that is,
 * convert an integer into a string by calling a recursive routine.
 * */

#include <assert.h>
#include <string.h>

void itoa(int n, char s[]);
static int itoa_routine(int, char[], int);
static void reverse(char s[]);

int main(void) {
    char s1[100];

    itoa(12345, s1);
    assert(strcmp("12345", s1) == 0);

    itoa(-12345, s1);
    assert(strcmp("-12345", s1) == 0);

    return 0;
}

void itoa(int n, char s[]) {
    int is_negative = n < 0;
    if (is_negative) {
        n = -n;
    }

    int last_idx = itoa_routine(n, s, 0);

    if (is_negative) {
        s[++last_idx] = '-';
    }

    s[last_idx + 1] = '\0';
    reverse(s);
}

int itoa_routine(int n, char s[], int i) {
    int l = i;
    if (n / 10) {
        l = itoa_routine(n / 10, s, i + 1);
    }
    s[i] = n % 10 + '0';
    return l;
}

void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
