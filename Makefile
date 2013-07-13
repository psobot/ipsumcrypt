CFLAGS = -Wall -MMD -g
CC = clang

.PHONY: clean all test

DECODER_SOURCES = $(wildcard decoder*.c)
DECODER_OBJECTS = $(DECODER_SOURCES:.c=.o)
DECODER_DEPENDS = $(DECODER_SOURCES:.c=.d)
DECODER_EXEC = decoder

ENCODER_SOURCES = $(wildcard encoder*.c)
ENCODER_OBJECTS = $(ENCODER_SOURCES:.c=.o)
ENCODER_DEPENDS = $(ENCODER_SOURCES:.c=.d)
ENCODER_EXEC = encoder

all: ${DECODER_EXEC} ${ENCODER_EXEC}

clean:
	rm -f *.d *.o */*.d */*.o */*/*.o */*/*.d ${DECODER_EXEC} ${ENCODER_EXEC}
	rm -rf *.dSYM */*.dSYM */*/*.dSYM

test: ${DECODER_EXEC}
	bash -c 'diff -q <(./DECODER < test.derp) test'

${DECODER_EXEC}: ${DECODER_OBJECTS}
	${CC} ${CFLAGS} $^ -o $@

${ENCODER_EXEC}: ${ENCODER_OBJECTS}
	${CC} ${CFLAGS} $^ -o $@