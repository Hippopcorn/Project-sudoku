#include <stdio.h>
#include "header/struct_values.h"
#include "header/print_grid.h"
#include "header/parse.h"
#include "header/solve.h"


int	main()
{
		char *sudoku;
		struct cell **parsing_cells;   

		sudoku = read_file();
		parsing_cells = parse_grid(sudoku);
		solve_grid(parsing_cells, 0, 0);

		return (0);
}
