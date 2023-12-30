#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int htoa(char s[]);
int hex_to_digit(char c);
int get_line_length(char s[]);
int is_hexadecimal(char c);

/** Converts hexadecimal number to integer */
int main(void) {
    char s[100];
    int result;

    fgets(s, sizeof(s), stdin);
    result = htoa(s);
    printf("%d", result);
}

int htoa(char s[]) {
    int result;
    int start, end, i;

    // do not consider hex-number prefix '0x'
    start = 0;
    if (s[0] == '0' && (tolower(s[1]) == 'x')) {
        start = 2;
    }

    // should be iterated backwards to correctly evaluate current power of 16
    end = get_line_length(s);
    result = 0;
    for (i = end - 1; i >= start; i--) {
        if (is_hexadecimal(s[i])) {
            result += hex_to_digit(s[i]) * pow(16, end - i - 1);
        } else {
            printf("Invalid symbol: %c [%d ANSI]\n", s[i], s[i]);
            exit(1);
        }
    }

    return result;
}

int get_line_length(char s[]) {
    int end = 0;
    while (s[end] != '\0' && s[end] != EOF && s[end] != '\n') {
        end++;
    }
    return end;
}

int hex_to_digit(char c) {
    char lc = tolower(c);

    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    if (lc >= 'a' && lc <= 'f') {
        return lc - 'a' + 10;
    }

    perror("Not a hexidecimal char\n");
    return 0;
}

int is_hexadecimal(char c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') ||
           (c >= 'A' && c <= 'F');
}
