/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:00:13 by jjuret            #+#    #+#             */
/*   Updated: 2017/10/30 13:56:36 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	make_player(t_vm *env, int nbr)
{
	int		max_size;
	int		cur;
	char	*line;
	t_champ	*champ;

	cur = 0;
	max_size = MEM_SIZE/nbr;
	champ = env->champ;
	while (champ)
	{
		if (read(champ->fd, &env->head, sizeof(t_header)) <= 0)
			ft_vm_error("ERROR: incorect file\n");
		if (COREWAR_EXEC_MAGIC != env->head.magic)
			ft_vm_error("ERROR: incorect magic number\n");
		if (read(champ->fd, &env->arene[cur * max_size], env->head.prog_size + 1) != env->head.prog_size)
			ft_vm_error("ERROR: incorect file\n");
		cur ++;
		champ = champ->next;
	}
}

void	make_arene(t_vm *env)
{
	t_champ	*cur;
	int		nbr;

	if (!(env->arene = (char*)malloc(MEM_SIZE)))
		ft_vm_error("Erreur de malloc pour l'arene\n");
	cur = env->champ;
	while (cur)
	{
		cur = cur->next;
		nbr++;
	}
	make_player(env, nbr);
}
