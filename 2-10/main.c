#include <assert.h>

int lower(int c);

int main(void) {
    assert(lower('a') == 'a');
    assert(lower('1') == '1');
    assert(lower('A') == 'a');
    assert(lower('Z') == 'z');
    return 0;
}

/** returns lowercased char c */
int lower(int c) { return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c; }
