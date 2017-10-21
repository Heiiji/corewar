#include "../includes/corewar.h"

/*
** Verification du dernier param :
** - > Doit etre un fichier.
** - > Doit se terminer par un .s
** Recuperatuion du fichier si valide :
** - > s_asm->file (char **) contient le fichier.s
*/

void	ft_open_check_and_get_file(t_asm *s_asm)
{
	int		fd;
	int		ret;
	char	*str_gnl;

	if ((fd = open(s_asm->av[s_asm->ac - 1], O_RDONLY)) < 2)
		ft_error(3, s_asm->av[s_asm->ac - 1]);
	if (ft_strlen(s_asm->av[s_asm->ac - 1]) < 2)
		ft_error(3, s_asm->av[s_asm->ac - 1]);
	if (s_asm->av[s_asm->ac - 1][ft_strlen(s_asm->av[s_asm->ac - 1]) - 1] != 's')
		ft_error(3, s_asm->av[s_asm->ac - 1]);
	if (s_asm->av[s_asm->ac - 1][ft_strlen(s_asm->av[s_asm->ac - 1]) - 2] != '.')
		ft_error(3, s_asm->av[s_asm->ac - 1]);
	while ((ret = get_next_line(fd, &str_gnl)) == 1)
	{
		s_asm->file = ft_malloc_tabtab(s_asm->file, str_gnl);
		ft_strdel(&str_gnl);
	}
	if (ret != 0)
		ft_error(3, s_asm->av[s_asm->ac - 1]);
	close(fd);
}