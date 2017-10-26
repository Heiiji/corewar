/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:00:13 by jjuret            #+#    #+#             */
/*   Updated: 2017/10/26 11:00:37 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	make_player(t_vm *env, int nbr)
{
	int		max_size;
	int		cur;
	char	*line;
	s_champ	*champ;

	cur = 0;
	max_size = MEM_SIZE/nbr;
	champ = env->champ;
	while (champ)
	{
		while (get_next_line(champ->fd, &line) == 1)
		{
			// un memset dans le gn a '0' serait bien
			ft_memcpy(arene[cur * max_size], line, max_size);
			cur ++;
			// on ecrit tout dans l'arene avec un decalage de max_size pour chaque champion (champion n decaler de max_size*(n-1))
		}
		champ = champ->next;
	}
}

void	make_arene(t_vm *env)
{
	t_champ	*cur;
	int		nbr;

	if (!(env->arene = (char*)malloc(MEM_SIZE)))
		ft_vm_error("Erreur de malloc pour l'arene");
	cur = env->champ;
	while (cur)
	{
		cur = cur->next;
		nbr++;
	}
	make_player(env, nbr);
}
