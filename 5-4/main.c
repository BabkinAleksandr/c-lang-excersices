/**
 * The task
 *
 * Write the function `strend(s,t)`, which returns 1 if the string `t` occurs at
 * the end of the string `s`, and zero otherwise.
 * */

#include <assert.h>

int strend(char *, char *);

int main(void) {
    assert(strend("hello", "llo") == 1);
    assert(strend("hello", "alo") == 0);

    return 0;
}

int strend(char *s, char *t) {
    char *t_i = t; // save initial t address

    // find ends of both strings
    while (*s++)
        ;
    while (*t++)
        ;

    s--;
    t--;

    // loop backwards until find diff chars or reach start of t
    while (*s-- == *t-- && t > t_i)
        ;

    // t occurs and the end of s if saved pointer and decremented are the same
    // (we reached the start of string), and first element occurs as well
    return (t == t_i && *s == *t) ? 1 : 0;
}
