#include "header/parse.h"

char *read_file()
{
	int		size_file;
	int 	fd;
	char 	*buf;
	int 	nb_read;
	int		i;

	i = 0;
	nb_read = -1;
	size_file = 98;
	buf = malloc(sizeof(char) * (size_file + 1));
	if (!buf)
	{
		write(2, "Error", 5);
		return (NULL);
	}

	fd = open("grille_sudoku.txt", O_RDONLY);
	if (fd == -1)
	{	
		write(2, "Error", 5);
		return (NULL);
	}
	nb_read = read(fd, buf, size_file);
	if (nb_read == -1)
	{
		write(2, "Error", 5);
		return (NULL);
	}
	buf[size_file] = '\0';
	close(fd);
	return (buf);
}

int **convert_grid(char *buf)
{
	int		**grid;
	int		i;

	i = 0;

	grid = malloc(9 * sizeof(int*));

	for (int line = 0; line < 9; line++)
	{
			grid[line] = malloc(9 * sizeof(int));
			for (int col = 0; col < 9; col++)
			{
					while (buf[i] == '\n' || buf[i] == '\r')
							i++;
					grid[line][col] = buf[i++] - '0';
			}
	}
	return (grid);
}
				
					

struct cell *parse_grid(int **grid)
{
		struct	cell *tab_cell;
		int i;

		i = 0;
		tab_cell = malloc(81 * sizeof(struct cell));
		if (!tab_cell)
				return (NULL);
		for (int line = 0; line < 9; line++)
		{
				for (int col = 0; col < 9; col++)
				{
						tab_cell[i].value = grid[line][col];
						tab_cell[i].line = line;
						tab_cell[i].col = col;
						if (grid[line][col] == 0)
								tab_cell[i].defined = false;
						else
								tab_cell[i].defined = true;
						i++;
				}
		}
		return (tab_cell);
}
