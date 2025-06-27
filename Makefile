CC = gcc
CFLAGS = -Isrc -Wall -Wextra -O2
LDFLAGS = -lm

SRC = src/main.c src/calc.c
OUT = bin/main

.PHONY: all run clean install

all: $(OUT)

$(OUT): $(SRC)
	@mkdir -p bin
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

run: $(OUT)
	./$(OUT)

install: $(OUT)
	cp $(OUT) /usr/local/bin/mycalc

clean:
	rm -rf bin

