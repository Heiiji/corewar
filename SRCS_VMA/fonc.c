/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 12:45:17 by jjuret            #+#    #+#             */
/*   Updated: 2017/10/26 11:20:08 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	live(char **pc)
{
	char	*tmp;

	tmp = (char *)malloc(5);
	ft_memcpy(tmp, target, 4);
	tmp[4] = '\0';
	ft_put(tmp, 4, 1, 0);
	ft_put(" is alive !", 11, 1, 0);
	free(tmp);
	*pc += 4;
}

void	ld(char **pc)
{
	char	value;
	char	*target;

	value = **pc;
	*pc++;
	target = *pc + (**pc * REG_SIZE);
	target += value;
	*pc++;
}
