BIN = basedump

CFLAGS = -std=c99 -Wextra -Wall -pedantic -g

OBJS = src/atoi.o src/main.o src/options.o

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $^ -o $@

install: $(BIN)
	install -Dm755 $(BIN) /usr/bin
	install -Dm644 "LICENSE" /usr/share/licenses/$(BIN)/LICENSE

uninstall:
	$(RM) /usr/bin/$(BIN)
	$(RM) -r /usr/share/licenses/$(BIN)

clean:
	$(RM) $(BIN) $(OBJS)

.PHONY: all clean install uninstall
