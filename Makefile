SRC=${wildcard src/*.c}
OBJ=${SRC:.c=.o}
CFLAGS=-g -p -Wall -I.

.c.o:
	@echo CC -c $< -o $@
	@${CC} ${CFLAGS} -c $< -o $@

out/foof: ${OBJ}
	@mkdir -p out
	@echo CC -o $@ ${OBJ}
	@${CC} ${LDFLAGS} -o $@ ${OBJ}

all: out/foof

clean:
	rm -rf ${OBJ} out

.PHONY: all
