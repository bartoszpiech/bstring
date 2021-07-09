CC=gcc
CFLAGS=-Wall -pedantic -std=c11
OBJ=bstring.o ../blist/blist.o
BIN=bstringtest

all: $(BIN)


%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN): $(BIN).c $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) -r $(OBJ) $(BIN) *.dSYM
