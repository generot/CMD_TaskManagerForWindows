CC = gcc
CFLAGS = -Wall
TOOLS = tools.h

DIR = src//
BIN = bin//

OBJ = $(DIR)tman.o $(DIR)proc.o $(DIR)iofuncs.o

all: tman.exe proc.dll iofuncs.dll

iofuncs.dll: $(DIR)iofuncs.o
	$(CC) $(CFLAGS) -shared -o $(BIN)$@ $<

proc.dll: $(DIR)proc.o $(DIR)iofuncs.o
	$(CC) $(CFLAGS) -shared -o $(BIN)$@ $^

tman.exe: $(OBJ)
	$(CC) $(CFLAGS) -o $(BIN)$@ $^

%.o: %.c $(TOOLS)
	$(CC) $(CFLAGS) -c $(DIR)$<

.PHONY: clean

clean:
	rm $(DIR)*.o