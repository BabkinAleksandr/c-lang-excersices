#include <stdio.h>

void escape(char s[], char t[]);
void decode(char s[], char t[]);

int main(void) {
    char s[500] =
        "Lorem ipsum dolor sit amet,\t\tconsectetur adipiscing elit, "
        "sed do eiusmod tempor incididunt ut labore et dolore magna\n"
        "aliqua. Ut enim ad minim veniam, quis nostrud exercitation\r\n"
        "ullamco laboris nisi ut aliquip\t\tex ea commodo consequat\n";
    char t[500];
    char d[500];

    escape(s, t);
    decode(t, d);
    printf("Original string:\n-----\n%s\n-----\n", s);
    printf("Encoded string:\n-----\n%s\n-----\n", t);
    printf("Decoded string:\n-----\n%s\n-----\n", d);

    return 0;
}

/** Copies s to t with printing \n \t \r escape sequences as visible symbols */
void escape(char s[], char t[]) {
    int i, k;

    for (i = 0, k = 0; s[i] != '\0'; i++, k++) {
        switch (s[i]) {
        case '\n':
            t[k] = '\\';
            t[++k] = 'n';
            break;
        case '\r':
            t[k] = '\\';
            t[++k] = 'r';
            break;
        case '\t':
            t[k] = '\\';
            t[++k] = 't';
            break;
        default:
            t[k] = s[i];
            break;
        }
    }

    t[k] = '\0';
}

/** Copies s to t with decoding previously escaped escape sequences in function
 * 'escape' */
void decode(char s[], char t[]) {
    int i, k;

    for (i = 0, k = 0; s[i] != '\0'; i++, k++) {
        if (s[i] == '\\') {
            switch (s[i + 1]) {
            case 'n':
                t[k] = '\n';
                i++;
                break;
            case 'r':
                t[k] = '\r';
                i++;
                break;
            case 't':
                t[k] = '\t';
                i++;
                break;
            default:
                t[k] = s[i];
                break;
            }
        } else {
            t[k] = s[i];
        }
    }

    t[k] = '\0';
}
