#include "../includes/corewar.h"

/*
** On check si il s agit d une ligne inutile (vide ou commentaire seulement)
** renvoie 1 si ce n est pas le cas
*/

static char	ft_check_useless_line(char *str)
{
	int	index;
	int	bool_sharp;

	index = -1;
	bool_sharp = 0;
	if (str[++index] == '\0')
		return (1);
	while (str[++index])
	{
		if (str[index] == '#')
			bool_sharp = 1;
		else
		{
			if (str[index] != '\t' && str[index] != 32)
				if (bool_sharp != 1)
					return (1);
		}
	}
	if (str[index] != '\0')
		return (1);
	return (0);
}

/*
** Fonction qui va traiter que toutes les donnees du .s sont justes.
*/

void 		ft_check_file_s(t_asm *s_asm)
{
	int index;

	index = -1;
	while (s_asm->file[++index])
	{
		if (ft_check_useless_line(s_asm->file[index]) == 1)
		{
			;
		}
	}
}