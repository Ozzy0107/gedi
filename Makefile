CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRC_DIR = src
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/analyzer.c
OBJ = $(SRC:.c=.o)
EXEC = gcat

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(EXEC)
