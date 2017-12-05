/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:51:00 by jjuret            #+#    #+#             */
/*   Updated: 2017/12/05 09:03:23 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
** cur->live est une booleen a 1 si le champion est en vie
*/

void	give_live(t_champ *champ, int id)
{
	t_champ	*cur;

	cur = champ;
	while (cur)
	{
		if (cur->id == id)
			cur->live = 1;
		cur = cur->next;
	}
}

int		check(t_champ *champ)
{
	t_champ	*cur;

	cur = champ;
	while (cur)
	{
		if (champ->id != cur->id)
			return (1);
		cur->live = 0;
		cur = cur->next;
	}
	return (0);
}

long	check_live(t_vm *env)
{
	t_champ							*cur;
	t_champ 						*prev;
	static unsigned long die =		CYCLE_TO_DIE;
	static unsigned long eck =		0;

	if (eck == 0)
		die = env->nbr_cycles;
	eck += 1;
	cur = env->champ;
	prev = NULL;
	while (cur)
	{
		if (cur->live != 1)
		{
			if (prev)
				prev->next = cur->next;
			else
			{
				prev = cur->next;
				env->champ = prev;
			}
			free(cur);
			cur = prev;
		}
		prev = cur;
		cur = cur->next;
	}
	die -= CYCLE_DELTA;
	if (check(env->champ) == 0 || die <= 0)
		return (0);
	return(die);
}
