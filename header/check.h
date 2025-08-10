#ifndef CHECK_H
# define CHECK_H

#include <stdbool.h>

bool is_valid_line(int **board, int line, int col);

bool is_valid_col(int **board, int line, int col);

bool is_valid_square(int **board, int line, int col);

#endif
