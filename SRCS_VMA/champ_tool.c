/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:02:08 by jjuret            #+#    #+#             */
/*   Updated: 2017/11/10 11:02:36 by jjuret           ###   ########.fr       */
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
	printf("champ : %u, cur : %u, env : %u\n", champ->id, cur->id, env->champ->id);
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
