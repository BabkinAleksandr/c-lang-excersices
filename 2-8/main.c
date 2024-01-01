#include <assert.h>
#include <math.h>
#include <stdio.h>

unsigned rightrot(unsigned x, int n);
unsigned get_leftmost_bit_position(unsigned x);

int main(void) {
    assert(rightrot(1024, 3) == 128);
    assert(rightrot(85736, 5) == 35447);
    assert(rightrot(0, 5) == 0);
    return 0;
}

/** Returns x, but all n rightmost bits are moved to the leftmost position
 * when all other bits are moved by the same amount of positions as well */
unsigned rightrot(unsigned x, int n) {
    // bits that are truncated from the right to be added from left side
    unsigned truncated_rightmost_bits = x & ~(~0 << n);
    // previously truncated bits is put in proper position
    unsigned moved_rightmost_bits = truncated_rightmost_bits
                                    << (get_leftmost_bit_position(x) - n + 1);
    // remaining bits that are not truncated
    unsigned remaining_bits = x >> n;

    return remaining_bits | moved_rightmost_bits;
}

/** Returns position (index) of leftmost bit of unsigned integer
 * In other words, returns (length - 1) of bit representation of an integer */
unsigned get_leftmost_bit_position(unsigned x) {
    int i = 0;
    unsigned tmp = x;

    while (tmp > 1) {
        tmp = tmp / 2;
        i++;
    }

    return i;
}
