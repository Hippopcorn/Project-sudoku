#include <unistd.h>
#include "../include/struct_values.h"
#include "../include/print_grid.h"
#include "../include/parse.h"
#include "../include/solve.h"


int	main()
{
		char *sudoku;
		struct cell **parsing_cells;   

		sudoku = read_file();
		if (sudoku == NULL)
		{
				write(2, "Error, file not read", 20);
				return (1);
		}

		parsing_cells = parse_grid(sudoku);
		if (parsing_cells == NULL)
		{
				write(2, "Error during the parsing", 24);
				return (1);
		}	
		solve_grid(parsing_cells, 0, 0);

		return (0);
}
