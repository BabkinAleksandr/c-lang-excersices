/**
 * The task
 *
 * Write a recursive version of the function `reverse(s)`, whichreverses the
 * string `s` in place.
 * */

#include <assert.h>
#include <string.h>

void reverse(char s[]);
static void reverse_routine(char[], int, int);

int main(void) {
    char s1[] = "123456";
    char s2[] = "abcdef--";

    reverse(s1);
    reverse(s2);
    assert(strcmp(s1, "654321") == 0);
    assert(strcmp(s2, "--fedcba") == 0);

    return 0;
}

void reverse(char s[]) { reverse_routine(s, 0, strlen(s) - 1); }

void reverse_routine(char s[], int l, int r) {
    char c;

    if (l >= r) {
        return;
    }

    c = s[l];
    s[l] = s[r];
    s[r] = c;

    reverse_routine(s, l + 1, r - 1);
}
