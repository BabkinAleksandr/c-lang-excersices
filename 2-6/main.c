#include <assert.h>
#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, int y);

int main(void) {
    assert(setbits(1024, 0, 1, 1) == 1025);
    assert(setbits(1024, 10, 1, 0) == 0);
    assert(setbits(85736, 10, 5, 333) == 84840);
}

/** returns x, but with the n bits that begin at position p
 * set to the rightmost n bits of y,
 * leaving other bits unchanged */
unsigned setbits(unsigned x, int p, int n, int y) {
    // take all leftmost bits till p
    unsigned left_bits = (x >> (p + 1) << (p + 1));
    // take all rightmost bits till p+n
    unsigned right_bits = x & ~(~0 << (p + 1 - n));
    // combine all unchanged bits in one number
    // all `should be changed` bits substituted with zeroes
    unsigned unchanged_x_bits = left_bits | right_bits;
    // take n rightmost bits of y and shift them left,
    // so their position matches of `should be changed` bits
    unsigned y_bits = (y & ~(~0 << n)) << (p + 1 - n);
    // combine unchanged bits with taken y bits
    unsigned result = unchanged_x_bits | y_bits;

    return result;
}
