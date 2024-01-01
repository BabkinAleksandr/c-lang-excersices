#include <assert.h>
#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main(void) {
    assert(invert(1024, 2, 3) == 1031);
    assert(invert(85736, 10, 5) == 84264);
    assert(invert(0, 5, 6) == 63);
    return 0;
}

/** Returns x, but bits in fragment from position p and length of n are inverted
 * other bits stay unchanged*/
unsigned invert(unsigned x, int p, int n) {
    // take all leftmost bits till p
    unsigned left_bits = x >> (p + 1) << (p + 1);
    // take all rightmost bits till p+n
    unsigned right_bits = x & ~(~0 << (p + 1 - n));
    // combine all unchanged bits in one number
    // all `should be changed` bits substituted with zeroes
    unsigned unchanged_x_bits = left_bits | right_bits;
    // create a mask to match p-n bits and apply it to inverted x
    // to get inverted bits only on p-n positions
    unsigned inverted_bits = ~x & (~(~0 << n) << (p + 1 - n));
    unsigned result = unchanged_x_bits | inverted_bits;
    return result;
}
