#include "header/solve.h"

bool is_valid_line(struct cell **board, int line, int col)
{
		for (int x = 0; x < 9; x++)
		{
				if (board[line][x].value == board[line][col].value && x != col)
						return (false);
		}
		return (true);
}

bool is_valid_col(struct cell **board, int line, int col)
{
		for (int y = 0; y < 9; y++)
		{
			if (board[y][col].value == board[line][col].value && y != line)
				return (false);
		}
	return (true);
}

bool is_valid_square(struct cell **board, int line, int col)
{
		int x_start;
		int y_start;

		x_start = col - (col % 3);
		y_start = line - (line % 3);

		for (int y = y_start; y < y_start + 3; y++)
		{
				for (int x = x_start; x < x_start + 3; x++)
				{
						if (board[y][x].value == board[line][col].value && y != line && x != col)
								return (false);
				}
		}
		return (true);
}


void solve_grid(struct cell **board, int line, int col)
{
		if (line == 9)
		{
				print_grid(board);
				return;
		}
		if (board[line][col].defined == true)
		{
				if (col == 8)
						solve_grid(board, line + 1, 0);
				else
						solve_grid(board, line, col + 1);	
		}
		else
		{
				board[line][col].value = 1;
				
				while (board[line][col].value <=  9)
				{
						if (is_valid_line(board, line, col) && is_valid_col(board, line, col) && is_valid_square(board, line, col))
						{	
								if (col == 8)
										solve_grid(board, line + 1, 0);
								else
										solve_grid(board, line, col + 1);	
						}
						board[line][col].value++;
				}
		}
}
