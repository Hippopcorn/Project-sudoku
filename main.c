#include <stdio.h>
#include "struct_values.h"
#include "header/print_grid.h"
#include "header/parse.h"
#include "header/solve.h"


int	main()
{
		char *sudoku;
		int **grid;
		struct cell *parsing_cells;   
		int i;

		i = 0;
		sudoku = read_file();
		grid = convert_grid(sudoku);
		print_grid(grid);
		parsing_cells = parse_grid(grid);

		return (0);
}
