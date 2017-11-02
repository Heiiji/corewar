/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:02:08 by jjuret            #+#    #+#             */
/*   Updated: 2017/11/02 16:15:58 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	sort_champ(t_champ *champ)
{
	t_champ	*cur;
	t_champ	*prev

	prev = NULL;
	cur = champ;
	while (cur->next)
	{
		if (cur->cycle  >  cur->next->cycle)
		{
			if (prev)
			{
				prev->next = cur->next;
				cur->next = cur->next->next;
				prev->next = cur;
				prev = NULL;
			}
			cur = champ;
		}
		prev  = cur;
		cur = cur->next;
	}
}
