CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iinclude

TARGET = sudoku
SRC = src/main.c src/parse.c src/print_grid.c src/solve.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
	rm -rf $(TARGET).dSYM

re: clean all
