CC := g++
CFLAGS := -Wall

SRCFILES := $(wildcard src/*.cpp)

all: $(SRCFILES:src/%.cpp=obj/%.o)
	$(CC) $(CFLAGS) obj/*.o -o bin/saida -lncurses

obj/%.o : src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I./inc

.PHONY: clean
clean:
	rm -rf obj/*.o
	rm -rf bin/*

run:
	bin/saida
