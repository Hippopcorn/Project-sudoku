#include "header/solve.h"

bool is_valid_line(int **board, int line, int col)
{
		for (int x = 0; x < 9; x++)
		{
				if (board[line][x] == board[line][col] && x != col)
						return (false);
		}
		return (true);
}

bool is_valid_col(int **board, int line, int col)
{
		for (int y = 0; y < 9; y++)
		{
			if (board[y][col] == board[line][col] && y != line)
					return (false);
		}
	return (true);
}

bool is_valid_square(int **board, int line, int col)
{
		int x_start;
		int y_start;

		x_start = col - (col % 3);
		y_start = line - (line % 3);

		for (int y = y_start; y < y_start + 3; y++)
		{
				for (int x = x_start; x < x_start + 3; x++)
				{
						if (board[y][x] == board[line][col] && y != line && x != col)
								return (false);
				}
		}
		return (true);
}


void solve_grid(int **board, int line, int col)
{
		if (line == 9 && col == 0)
		{
				print_grid(board);
				return;
		}
		if (board[line][col].defined == false)
		{
				board[line][col] = 1;

				while (board[line][col] <=  9)
				{
						if (is_valid_line(board, line, col) && is_valid_col(board, line, col) && is_valid_square(board, line, col) && col == 8)
										solve_grid(board, line + 1, 0);
						else if (is_valid_line(board, line, col) && is_valid_col(board, line, col) && is_valid_square(board, line, col))
								solve_grid(board, line, col + 1);	
						board[line][col]++;
				}
		}
}
