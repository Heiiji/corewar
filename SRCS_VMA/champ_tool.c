/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:02:08 by jjuret            #+#    #+#             */
/*   Updated: 2017/11/17 15:47:45 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	rang(t_vm *env, t_champ *champ)
{
	t_champ	*cur;
	t_champ *prev;

	prev = champ;
	cur = champ->next;
	if (!cur || !prev)
		return ;
	if (cur->cycle >= champ->cycle)
		return ;
	while (cur->next && cur->cycle < champ->cycle)
	{
		prev = prev->next;
		cur = cur->next;
	}
	env->champ = champ->next;
	if (cur->cycle < champ->cycle)
	{
		champ->next = cur->next;
		cur->next = champ;
	}
	else
	{
		champ->next = cur;
		if (prev != champ)
			prev->next = champ;
	}
}

t_champ	*find_by_id(t_vm *env, int id)
{
	t_champ	*cur;

	cur = env->champ;
	while (cur)
	{
		if (cur->id == id)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

short		get_short(unsigned char *read)
{
	unsigned char tmp[2];

	tmp[0] = *(read + 1);
	tmp[1] = *read;
	return (*((short*)(&tmp[0])));
}

int		get_int(unsigned char *read)
{
	unsigned char tmp[4];

	tmp[0] = *(read + 3);
	tmp[1] = *(read + 2);
	tmp[2] = *(read + 1);
	tmp[3] = *read;
	return (*((int*)(&tmp[0])));
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
	if (!env->champ->next)
		return (0);
	return(CYCLE_TO_DIE);
}
