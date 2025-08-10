#ifndef SOLVE_H
# define SOLVE_H

#include "print_grid.h"
#include <stdbool.h>

bool is_valid_line(int **board, int line, int col);

bool is_valid_col(int **board, int line, int col);

bool is_valid_square(int **board, int line, int col);

void solve_grid(int **board, int line, int col);

#endif
