/**
 * The task
 *
 * Define a macro `swap(t,x,y)` that interchanges two arguments of type t.
 * (Block structure will help.)
 * */

#include <assert.h>
#define swap(x, y, t)                                                          \
    {                                                                          \
        t c;                                                                   \
        c = x;                                                                 \
        x = y;                                                                 \
        y = c;                                                                 \
    }

int main(void) {
    {
        int a = 1, b = 2;
        assert(a == 1);
        assert(b == 2);

        swap(a, b, int);

        assert(a == 2);
        assert(b == 1);
    }

    {
        char a = '0', b = '9';
        assert(a == '0');
        assert(b == '9');

        swap(a, b, char);

        assert(a == '9');
        assert(b == '0');
    }
    return 0;
}
