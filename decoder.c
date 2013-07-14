#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef enum state_e {
    kStart,
    kOne,
    kZero,
} state_e;

char add(bool bit, unsigned char output, int *i) {
    if (*i > 0 && *i % 8 == 0) {
        putchar(output);
        output = *i = 0;
    }
    return output | ((bit ? 1 : 0) << (*i)++);
}

int main(int argc, char **argv) {
    state_e state = kStart;

    int i = 0;
    unsigned char c;
    unsigned char output = 0;

    while (fread(&c, 1, 1, stdin) == 1 && !feof(stdin)) {
        reparse:
        switch (state) {
            case kStart:
                state = isspace(c) ? kZero : kOne;
                goto reparse;
            case kOne:
                if (isspace(c)) {
                    output = add(1, output, &i);
                    state = kZero;
                }
                break;
            case kZero:
                if (isspace(c)) {
                    output = add(0, output, &i);
                } else {
                    state = kOne;
                }
                break;
        }
    }

    if (state == kOne) {
        add(1, output, &i);
    }

    putchar(output);
    return 0;
}