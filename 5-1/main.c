/**
 * The task
 *
 * As written, `getint` treats a `+` or `-` not followed by a digit as a valid
 * representation of zero. Fix it to push such a character back on the input.
 * */

#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100
#define SIZE 10

static int getch(void);
static void ungetch(int);
int getint(int *);

int main(void) {
    int n, array[SIZE];
    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        ;

    printf("Printing values:\n");
    for (n = 0; n < SIZE; n++) {
        printf("%d: %d\n", n + 1, array[n]);
    }
    printf("we're done!\n");

    return 0;
}

// Didn't get what the function really does, but my assumption is that it takes
// input char by char and write only integer to provided pointer. Given
// implementation wasn't able to pass through non-integer values
int getint(int *pn) {
    int c, sign;

    // skip non digit chars
    do {
        c = getch();
    } while (!isdigit(c) && c != '+' && c != '-' && c != EOF);

    if (c == EOF) {
        return c;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-') {
        c = getch();
    }

    if (!isdigit(c)) {
        return -1;
    }

    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;

    if (c != EOF) {
        ungetch(c);
    }

    return c;
}

char buf[BUFSIZE]; // buffer for ungetch
int bufp = 0;

/* get a (possibly pushed back) character */
int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

/* push character back on input */
void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("Ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}
