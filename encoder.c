#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define len(x)  (sizeof(x) / sizeof(x[0]))

typedef union bits_t {
    char byte;
    struct {
        unsigned char bit1 : 1;
        unsigned char bit2 : 1;
        unsigned char bit3 : 1;
        unsigned char bit4 : 1;
        unsigned char bit5 : 1;
        unsigned char bit6 : 1;
        unsigned char bit7 : 1;
        unsigned char bit8 : 1;
    } bits;
} bits_t;

char *getword(unsigned int i) {
    char *words[] = {
        "Lorem", "ipsum", "dolor", "sit", "amet,", "consectetur", "adipiscing",
        "elit.", "Sed", "commodo", "at", "eros", "ut", "facilisis.",
        "Aliquam", "vitae", "venenatis", "neque.", "In", "ut", "posuere",
        "neque.", "Nulla", "et", "felis", "arcu.", "Quisque", "facilisis",
        "porttitor", "auctor.", "Nam", "interdum,", "purus", "eget", "dictum",
        "placerat,", "justo", "dolor", "pharetra", "justo,", "ac", "interdum",
        "diam", "erat", "ut", "risus.", "Morbi", "quis", "elit", "vel",
        "lacus", "consequat", "vulputate.", "Phasellus", "dictum",
        "malesuada", "dictum.", "Fusce", "sed", "bibendum", "sapien,", "eget",
        "sodales", "nunc.", "Cras", "viverra", "pellentesque", "tellus",
        "blandit", "sagittis.", "Morbi", "tincidunt", "odio", "in", "mi",
        "mattis", "vestibulum.", "Praesent", "eu", "elit", "in", "mi",
        "vestibulum", "placerat", "ut", "sed", "orci.",
    };
    return words[i % len(words)];
}

int main(int argc, char **argv) {
    int i = 0;
    bits_t c;
    char *empty = "";

    while (fread(&c.byte, 1, 1, stdin) == 1 && !feof(stdin)) {
        printf("%s ", c.bits.bit1 ? getword(i++) : empty);
        printf("%s ", c.bits.bit2 ? getword(i++) : empty);
        printf("%s ", c.bits.bit3 ? getword(i++) : empty);
        printf("%s ", c.bits.bit4 ? getword(i++) : empty);
        printf("%s ", c.bits.bit5 ? getword(i++) : empty);
        printf("%s ", c.bits.bit6 ? getword(i++) : empty);
        printf("%s ", c.bits.bit7 ? getword(i++) : empty);
        printf("%s ", c.bits.bit8 ? getword(i++) : empty);
    }

    return 0;
}