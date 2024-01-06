/**
 * The task
 *
 * Write the function `itob(n,s,b)` that converts the integer `n` into a base b
 * character representation in the string `s`. In particular, `itob(n, s, 16)`
 * formats `n` as a hexadecimal integer in `s`. */

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);
void run_test(int n, int base, char result[]);

int main(void) {
    run_test(501, 16, "1f5");
    run_test(10000, 22, "kec");
    run_test(81937, 2, "10100000000010001");
    run_test(-799173826, 36, "-d7t2gy");
    run_test(88888, 8, "255470");
    run_test(12345, 10, "12345");
    run_test(12345678, 5, "11130030203");

    return 0;
}

void run_test(int n, int base, char result[]) {
    char s[100];

    itob(n, s, base);

    printf("\n-----\n");
    printf("Decimal: %d, base: %d\n", n, base);
    printf("Conversion result: %s\n", s);
    assert(!strcmp(s, result));
}

void itob(int n, char s[], int b) {
    int i = 0, r, sign;

    // conversion doesn't work properly with negative number, so we need to
    // convert them to positive, but because of the edge case with INT_MIN
    // conversion, we need to process it
    if (n == INT_MIN) {
        n++;
    } else if (n == INT_MAX) {
        n--;
    }

    if ((sign = n > 0 ? 1 : -1) < 0) {
        n = -n;
    }

    // algorithm is simple:
    do {
        // get remainder of division n by base
        r = n % b;
        // set remainder as next item in s, converting it to digit or letter
        s[i++] = r <= 9 ? r + '0' : r - 10 + 'a';
        // divide n by base dropping fractional part
        n /= b;
    } while (n > 0);

    if (sign < 0) {
        s[i++] = '-';
    }

    s[i] = '\0';
    // reverse string at the end
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
