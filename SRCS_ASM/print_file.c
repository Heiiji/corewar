#include "../includes/corewar.h"

void	ft_print_file(char **tab_file)
{
	int index;

	index = -1;
	while (tab_file[++index])
		ft_put(tab_file[index], '\n', 1, 0);
	exit (0);
}