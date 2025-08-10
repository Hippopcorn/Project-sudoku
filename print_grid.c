
#include "header/print_grid.h"

void	print_grid(struct cell **grid)
{
		for (int i = 1; i < 20; i++)
		{			
				if (i == 1)
					write(1,"┌", 3);
				else if (i == 19)
					write(1,"┐", 3);	
				else if (i % 2 == 0)
					ft_putchar('-');
				else 
					write(1,"┬", 3);
		}
				ft_putchar('\n');

		
		for (int line = 0; line < 9; line++)
		{
				for (int col = 0; col < 9; col++)
				{
						ft_putchar('|');
						ft_putchar(grid[line][col].value + '0');
				}
				ft_putchar('|');
				ft_putchar('\n');
				for (int i = 1; i < 20; i++)
				{
						if (i == 1 && line == 8)
							write(1,"└", 3);
						else if (i == 19 && line == 8)
							write(1,"┘", 3);
						else if (line == 8 && i % 2 != 0)
							write(1,"┴", 3);
						else if (i == 1)
							write(1,"├", 3);
						else if (i == 19)
							write(1,"┤", 3);	
						else if (i % 2 == 0)
							ft_putchar('-');
						else 
							write(1,"┼", 3);
				}
				ft_putchar('\n');
		}

}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

