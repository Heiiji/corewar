/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:00:13 by jjuret            #+#    #+#             */
/*   Updated: 2017/11/20 11:02:12 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int				magic_check(unsigned int m1, unsigned int m2)
{
	unsigned char	*cur1;
	unsigned char	*cur2;

	cur1 = (unsigned char*)&m1 + 3;
	cur2 = (unsigned char*)&m2;
	while (*cur1 == 0)
		cur1 -= 1;
	while (*cur2 == 0)
		cur2 += 1;
	while (*cur2)
	{
		if (*cur1 != *cur2)
			return (-1);
		cur1 -= 1;
		cur2 += 1;
	}
	return (0);
}

unsigned int	inv_uint(unsigned int target)
{
	char	*cur;
	char	tmp;

	cur = (char*)&target;
	tmp = cur[3];
	cur[3] = cur[0];
	cur[0] = tmp;
	tmp = cur[2];
	cur[2] = cur[1];
	cur[1] = tmp;
	return (target);
}

void			make_player(t_vm *env, int nbr)
{
	int		max_size;
	int		cur;
	long	tmp;
	char	*line;
	t_champ	*champ;

	cur = 0;
	max_size = MEM_SIZE/nbr;
	champ = env->champ;
	while (champ)
	{
		if (read(champ->fd, &champ->head, sizeof(t_header)) <= 0)
			ft_vm_error("ERROR: incorect file\n");
		if (magic_check(COREWAR_EXEC_MAGIC, champ->head.magic) != 0)
			ft_vm_error("ERROR: incorect magic number\n");
		champ->head.prog_size = inv_uint(champ->head.prog_size);
		if (read(champ->fd, &env->arene[cur * max_size], champ->head.prog_size + 5) != champ->head.prog_size)
			ft_vm_error("ERROR: incorect file\n");
		champ->pc = cur * max_size;
		tmp = -champ->id;
		tmp = get_int((unsigned char*)&tmp);
		ft_memcpy(&champ->registre[REG_SIZE], &tmp, 4);
		printf("Joueur n°%d\n", cur);
		printf("id n°%d\n", champ->id);
		printf("Name : %s\n", champ->head.prog_name);
		printf("Size : %u\n", champ->head.prog_size);
		printf("Comment : %s\n\n", champ->head.comment);
		cur ++;
		champ = champ->next;
	}
}

/*
** Construction de l'arene et check des joueurs (pour la securités)
*/

void	make_arene(t_vm *env)
{
	t_champ	*cur;
	int		nbr;

	if (!(env->arene = (unsigned char*)malloc(MEM_SIZE)))
		ft_vm_error("Erreur de malloc pour l'arene\n");
	cur = env->champ;
	while (cur)
	{
		cur = cur->next;
		nbr++;
	}
	printf("Nombre de joueurs : %d\n\n", nbr);
	make_player(env, nbr);
}
