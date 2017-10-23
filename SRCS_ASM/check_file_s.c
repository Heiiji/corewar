#include "../includes/corewar.h"

/*
** On verifie la presence du .name et de sa syntaxe
** Il ne peut en y avoir qu un
*/

static void	ft_check_comment(t_asm *s_asm, char *str)
{
	int	index;
	int	lenght;

	index = 0;
	lenght = 0;
	while (str[index] == 32 || str[index] == '\t')
		index++;
	if (strncmp(str + index, COMMENT_CMD_STRING, 8) == 0)
	{
		s_asm->bool_comment++;
		index += 8;
		while (str[index] == 32 || str[index] == '\t')
			index++;
		if (str[index++] != '\"')
			ft_error(5, s_asm->av[s_asm->ac - 1]);
		while (str[index] && str[index] != '\"' && lenght < COMMENT_LENGTH)
		{
			s_asm->comment[lenght] = str[index];
			lenght++;
			index++;
		}
		s_asm->comment[lenght] = '\0';
		(str[index] != '\"') ? ft_error(5, s_asm->av[s_asm->ac - 1]) : 0;
		(lenght > COMMENT_LENGTH) ? ft_error(6, NULL) : 0;
	}
}

/*
** On verifie la presence du .comment et de sa syntaxe
** Il ne peut en y avoir qu un
*/

static void	ft_check_name(t_asm *s_asm, char *str)
{
	int	index;
	int	lenght;

	index = 0;
	lenght = 0;
	while (str[index] == 32 || str[index] == '\t')
		index++;
	if (strncmp(str + index, NAME_CMD_STRING, 5) == 0)
	{
		index += 5;
		s_asm->bool_name++;
		while (str[index] == 32 || str[index] == '\t')
			index++;
		if (str[index++] != '\"')
			ft_error(5, s_asm->av[s_asm->ac - 1]);
		while (str[index] && str[index] != '\"' && lenght < PROG_NAME_LENGTH)
		{
			s_asm->prog_name[lenght] = str[index];
			lenght++;
			index++;
		}
		s_asm->prog_name[lenght] = '\0';
		(str[index] != '\"') ? ft_error(5, s_asm->av[s_asm->ac - 1]) : 0;
		(lenght > PROG_NAME_LENGTH) ? ft_error(6, NULL) : 0;
	}
}

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
			ft_check_name(s_asm, s_asm->file[index]);
			ft_check_comment(s_asm, s_asm->file[index]);
		}
	}
	if (s_asm->bool_name != 1 && s_asm->bool_comment != 1)
		ft_error(4, s_asm->av[s_asm->ac - 1]);
}