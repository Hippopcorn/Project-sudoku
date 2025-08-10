#ifndef SOLVE_H
# define SOLVE_H

#include "print_grid.h"
#include <stdbool.h>
#include "struct_values.h"

bool is_valid_line(struct cell **board, int line, int col);

bool is_valid_col(struct cell **board, int line, int col);

bool is_valid_square(struct cell **board, int line, int col);

void solve_grid(struct cell **board, int line, int col);

#endif
