#include <assert.h>
#include <stdio.h>

int bitcount(unsigned x);

int main(void) {
    assert(bitcount(1023) == 10);
    assert(bitcount(1024) == 1);
    assert(bitcount(85736) == 9);
    assert(bitcount(1126) == 5);
    assert(bitcount(0) == 0);
    return 0;
}

/** Counts the number of 1-bits in x */
int bitcount(unsigned x) {
    int b;

    for (b = 0; x != 0; x &= (x - 1)) {
        b++;
    }

    return b;
}

/** Original bitcount function that needs to be rewritte with x &= (x - 1)
 * expression.
 * The reason, why x&=x-1 works is that (x-1) expression always changes
 * rightmost 1-bit to 0, and then x&=x-1 always will erase this rightmost bit
 *
 * It means, that we can remove all rightmost bits one-by-one until x become 0
 * */
int bitcount_original(unsigned x) {
    int b;

    for (b = 0; x != 0; x >>= 1) {
        if (x & 01) {
            b++;
        }
    }

    return b;
}
