/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:02:08 by jjuret            #+#    #+#             */
/*   Updated: 2017/11/03 10:46:54 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	rang(t_vm *env, t_champ *champ)
{
	t_champ	*cur;

	cur = champ->next;
	if (cur->cycle >= champ->cycle)
		return ;
	while (cur->cycle < champ->cycle)
		cur = cur->next;
	env->champ = champ->next;
	champ->next = cur->next;
	cur->next = champ;
}
