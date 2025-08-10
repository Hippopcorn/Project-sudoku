#include "header/check.h"

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

