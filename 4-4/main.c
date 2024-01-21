/**
 * The task
 *
 * Add commands to print the top element of the stack without popping, to
 * duplicate it, and to swap the top two elements. Add a command to clear the
 * stack.
 * */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100  // max size of operand and operator
#define NUMBER '0' // signal that a number was found
#define MAXVAL 100 // maximum depth of val stack
#define BUFSIZE 100

int getop(char[]);
int getch(void);
void ungetch(int);
void push(double);
double pop(void);

/* reverse Polish calculator */
int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;

        case '+':
            push(pop() + pop());
            break;

        case '*':
            push(pop() * pop());
            break;

        case '-':
            op2 = pop();
            push(pop() - op2);
            break;

        case '/':
            op2 = pop();
            if (op2 != 0.0) {
                push(pop() / op2);
            } else {
                printf("Error: zero divisor\n");
            }
            break;

        case '%':
            op2 = pop();
            if (op2 != 0.0) {
                push((int)pop() % (int)op2);
            } else {
                printf("Error: modulo of zero\n");
            }

        case '\n':
            printf("\t%.8g\n", pop());
            break;

        default:
            printf("Error: unknown command %s\n", s);
            break;
        }
    }

    return 0;
}

int sp = 0;
double val[MAXVAL];

/* push f onto value stack */
void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("Error: stack full, can't push %g\n", f);
    }
}

/* pop and return top value from stack */
double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("Error: stack empty\n");
        return 0.0;
    }
}

/* Prints top element on the stack */
void print_top(void) {
    if (sp > 0) {
        printf("Stack top element: %f\n", val[sp - 1]);
    } else {
        printf("Stack is empty, nothing to print!\n");
    }
}

/* duplicates stack
 * p.s. Not sure what the task demands, because for me "duplicates it" is not
 * clear. Duplicates what – the stack, the last element? So I decided to
 * implement duplicating entire stack
 *
 */
void duplicate(double to[]) {
    int i;
    for (i = 0; i < sp; i++) {
        to[i] = val[i];
    }
}

/* swap two top elements on the stack */
void swap(void) {
    double tmp;
    if (sp > 1) {
        tmp = val[sp];
        val[sp] = val[sp - 1];
        val[sp - 1] = tmp;
    } else {
        printf("Stack size is not enough to swap elements. Current stack size "
               "is: %d\n",
               sp);
    }
}

/* clears the stack */
void clear(void) {
    sp = 0;
}

/* gets next operator or numeric operand */
int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-') {
        return c; // not a number
    }

    i = 0;
    if (isdigit(c) || c == '-') {
        // collect integer part
        while (isdigit(s[++i] = c = getch()))
            ;
    }

    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }

    return NUMBER;
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
