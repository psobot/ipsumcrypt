#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef enum state_e {
    kStart,
    kOne,
    kSeparator,
    kZero,
} state_e;

void flush(unsigned char output) {
    putchar(output);
}

char add(bool bit, unsigned char output, int *i) {
    if (*i > 0 && *i % 8 == 0) {
        flush(output);
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
                    state = kSeparator;
                }
                break;
            case kSeparator:
                if (isspace(c)) {
                    state = kZero;
                    output = add(0, output, &i);
                } else {
                    state = kOne;
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

    switch (state) {
        case kOne:
            add(1, output, &i);
            break;
        default:
            break;
    }

    flush(output);

    return 0;
}