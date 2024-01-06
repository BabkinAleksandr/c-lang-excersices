/**
 * The task
 *
 * In a two's complement number representation, our version of `itoa` does not
 * handle the largest negative number, that is, the value of `n` equal to
 * `-(2^wordsize-1)`. Explain why not. Modify it to print that value correctly,
 * regardless of the machine on which it runs.
 * */

#include <limits.h>
#include <stdio.h>
#include <string.h>

void itoa(int n, char s[]);
void itoa_new(int n, char s[]);
void reverse(char s[]);

int main(void) {
    char s_old_min[100];
    char s_old_max[100];
    char s_new_min[100];
    char s_new_max[100];

    // old version
    itoa(INT_MIN, s_old_min);
    itoa(INT_MAX, s_old_max);

    // new version
    itoa_new(INT_MIN, s_new_min);
    itoa_new(INT_MAX, s_new_max);

    printf("Min integer: %d\n", INT_MIN);
    printf("Max integer: %d\n", INT_MAX);
    printf("-----\n");

    printf("[old ver. - min integer]: %s\n", s_old_min);
    printf("[old ver. - max integer]: %s\n", s_old_max);
    printf("[new ver. - min integer]: %s\n", s_new_min);
    printf("[new ver. - max integer]: %s\n", s_new_max);

    return 0;
}

/** In a new version we just substract 1 from integer to avoid ofervlow and then
 * adds 1 to the last digit.
 * Problems could occur for round number, like 1000, but min and max integers
 * are always a power of 2, so should be fine*/
void itoa_new(int n, char s[]) {
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

    s[i] = '\0';
    reverse(s);

    if (n == INT_MAX || n == INT_MIN) {
        s[strlen(s) - 1] += 1;
    }
}

/** In this version of function negative number is reversed to positive, but
 * after that INT_MIN becomes larger than INT_MAX, that's why it cannot print
 * that number correctly */
void itoa(int n, char s[]) {
    int i, sign;

    if ((sign = n) < 0) {
        n = -n;
    }

    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) {
        s[i++] = '-';
    }

    s[i] = '\0';

    reverse(s);
}

void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
