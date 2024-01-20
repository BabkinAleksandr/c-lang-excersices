/**
 * The task
 *
 * Extend `atof` to handle scientific notation of the form
 *   `123.45e-6`
 * where a floating-point number may be followed by `e` or `E` and na optionally
 * signed exponent.
 * */

#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

double atof(char s[]);
void slice(char s[], char t[], int start, int length);

int main() {
    printf("Starting tests...\n");

    assert(atof("1234.56") == 1234.56);
    assert(atof("0.80008") == 0.80008);
    assert(atof("10000.0") == 10000.0);
    assert(atof("123.45e-6") == 0.00012345);
    assert(atof("123.45e2") == 12345.0);

    printf("Tests completed successfully!\n");

    return 0;
}

double atof(char s[]) {
    char exp_part[100];
    double val, power, result, exponent;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }

    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }

    if (s[i] == '.') {
        i++;
    }

    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    result = sign * val / power;

    if (tolower(s[i]) != 'e') {
        return result;
    } else {
        i++;
    }

    // using recursion to parse exponent part
    slice(s, exp_part, i, strlen(s) - i);
    exponent = atof(exp_part);

    // printf("exp part: %f\n", exponent);

    return result * pow(10.0, exponent);
}

/** Takes part of string `s`, from start till start+length, and puts it in to
 * `t` */
void slice(char s[], char t[], int start, int length) {
    int i;
    for (i = 0; i < length && s[start + i] != '\0'; i++) {
        t[i] = s[start + i];
    }
    t[i] = '\0';
}
