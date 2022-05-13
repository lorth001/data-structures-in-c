CC=gcc
CFLAGS=-Wall
SRC=src
OBJ=obj
SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

BINDIR=bin
BIN = $(BINDIR)/main

all:$(BIN)

release: CFLAGS=-Wall -O2 -DNDEBUG
release: clean
release: $(BIN)

$(OBJS): | $(OBJ)
$(OBJ):
	-mkdir $(OBJ) 2>/dev/null

$(BIN): | $(BINDIR)
$(BINDIR):
	-mkdir $(BINDIR) 2>/dev/null

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(BINDIR)/* $(OBJ)/*
