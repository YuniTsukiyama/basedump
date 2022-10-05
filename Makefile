BIN = basedump

CFLAGS = -std=c99 -Wextra -Wall -pedantic -g

OBJS = src/atoi.o src/main.o src/options.o

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $^ -o $@

clean:
	$(RM) $(BIN) $(OBJS)

.PHONY: all clean
