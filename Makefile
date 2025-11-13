CC = gcc
CFLAGS = -std=c23 -Wall -Wextra -pedantic -Iinclude -D_POSIX_C_SOURCE=200809L
SOURCES = $(wildcard src/*.c)
TEST_SOURCES = $(wildcard tests/*.c)
OBJECTS = $(SOURCES:.c=.o)
EXEC = secdev

.PHONY: all build test clean clang-tidy splint static-analysis

all: build test

build: $(SOURCES)
	$(CC) $(CFLAGS) -c $(SOURCES)

test: $(SOURCES) $(TEST_SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) $(TEST_SOURCES) -o $(EXEC)
	./$(EXEC)

clang-tidy:
	clang-tidy $(SOURCES) $(TEST_SOURCES) -- $(CFLAGS)

splint:
	splint -f .splintrc -Iinclude $(SOURCES) $(TEST_SOURCES)

static-analysis: clang-tidy splint

clean:
	rm -f $(OBJECTS) $(EXEC) data1 data2
