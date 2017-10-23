#include "../includes/corewar.h"

void	ft_error(size_t id_error, char *name)
{
	if (id_error == 1)
		ft_put("Malloc failed with", 32, 2, 0);
	else if (id_error == 2)
	{
		ft_put("Usage: ./asm [-a] <sourcefile.s>", '\n', 2, 0);
		ft_put("    -a : Instead of creating a .cor file, outputs a stripped", 0, 2, 0);
		ft_put("and annotated version of the code to the standard output", '\n', 2, 0);
	}
	else if (id_error == 3)
		ft_put("Can't read source file", 32, 2, 0);
	else if (id_error == 4)
		ft_put("wrong number of .name/.comment of", 32, 2, 0);
	else if (id_error == 5)
		ft_put("wrong name/comment's syntax of", 32, 2, 0);
	else if (id_error == 6)
		ft_put("Champion name/comment too long (Max length 128/2048)", 10, 2, 0);
	if (name)
		ft_put(name, '\n', 2, 0);
	exit (1);
}