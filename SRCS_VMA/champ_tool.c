/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:02:08 by jjuret            #+#    #+#             */
/*   Updated: 2017/11/08 13:11:34 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	rang(t_vm *env, t_champ *champ)
{
	t_champ	*cur;
	t_champ *prev;

	prev = champ;
	cur = champ->next;
	if (!champ->next || !cur)
		return ;
	if (cur->cycle >= champ->cycle)
		return ;
	while (cur->next && cur->cycle < champ->cycle)
	{
		prev = prev->next;
		cur = cur->next;
	}
	env->champ = champ->next;
	champ->next = cur->next;
	if (!cur->next)
		cur->next = champ;
	if (prev->next != champ)
		prev->next = champ;
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
