/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:51:00 by jjuret            #+#    #+#             */
/*   Updated: 2017/11/20 10:19:24 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

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
		cur = cur->next;
	}
	return (0);
}

long	check_live(t_vm *env)
{
	t_champ	*cur;
	t_champ *prev;

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
	if (!env->champ)
		return (0);
	if (!env->champ->next || check(env->champ) == 1)
		return (0);
	return(CYCLE_TO_DIE);
}
