#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char *get_line(char *buf, int i)
{
		int i_line;
		char *line;

		i_line = 0;
		while (buf[i] != '\n')
		{
				line[i_line] = buf[i];
				i++;
				i_line++;
		}
		line[i_line] = '\0';
		return (line);
}

char **parse_file(char *buf)
{
		char **tab_lines;
		int i;
		int i_tab;

		i = 0;
		i_tab = 0;
		tab_lines = malloc(sizeof(char) * (98 + 1));
		while (buf[i] != '\0')
		{
				if (i == 0 || buf[i - 1] == '\n')
				{
						tab_lines[i_tab] = get_line(buf, i);
						printf("%s\n", tab_lines[i_tab]);
						i_tab++;
				}
				i++;
		}
		return (tab_lines);
}	

//	faire un tableau de tableau de char pour stocker toutes les lignes : 
//	pour malloc : malloc un tableau de char* puis faire une boucle for pour malloc 10 caracteres par ligne :)
//	faire un tableau de int a la place de char et pas de \0;

int	main()
{
		char **tab;
		int i;

		i = 0;
		tab = parse_file(read_file());
		/*
		while (i < 8)
		{
				printf("%s\n", tab[i]);
				i++;
		}*/

		return (0);
}




			



