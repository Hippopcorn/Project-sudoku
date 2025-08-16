#include "../include/parse.h"

char *read_file()
{
	int		size_file;
	int 	fd;
	char 	*buf;
	int 	nb_read;

	nb_read = -1;
	size_file = 98;
	buf = malloc(sizeof(char) * (size_file + 1));
	if (!buf)
	{
		return (NULL);
	}

	fd = open("data/grille_sudoku.txt", O_RDONLY);
	if (fd == -1)
	{	
		return (NULL);
	}
	nb_read = read(fd, buf, size_file);
	if (nb_read == -1)
	{
		return (NULL);
	}
	buf[size_file] = '\0';
	close(fd);
	return (buf);
}

struct cell **parse_grid(char *buf)
{
	struct cell		**tab_cell;
	int		i;

	i = 0;

	tab_cell = malloc(9 * sizeof(struct cell*));
	if (!tab_cell)
		return (NULL);
	for (int line = 0; line < 9; line++)
	{
			tab_cell[line] = malloc(9 * sizeof(struct cell));
			for (int col = 0; col < 9; col++)
			{
					while (buf[i] == '\n' || buf[i] == '\r')
							i++;
					
					tab_cell[line][col].value = buf[i++] - '0';
					if (tab_cell[line][col].value == 0)
							tab_cell[line][col].defined = false;
					else 
							tab_cell[line][col].defined = true;
			}
	}
	return (tab_cell);
}
