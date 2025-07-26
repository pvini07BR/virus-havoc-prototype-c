CFLAGS = -std=c99 -ggdb3 -Iinclude
LDFLAGS = -lraylib -lm 

SOURCE = $(wildcard src/*.c) $(wildcard src/guns/*.c)

virus-havoc: $(SOURCE)
	gcc $(CFLAGS) -o virus-havoc $(SOURCE) $(LDFLAGS)

.PHONY: test clean

test: virus-havoc
	./virus-havoc

.PHONY: clean
clean:
	rm virus-havoc