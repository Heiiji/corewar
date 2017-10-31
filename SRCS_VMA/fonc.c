/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 12:45:17 by jjuret            #+#    #+#             */
/*   Updated: 2017/10/31 10:08:38 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		oct_codage(char target, char place, unsigned char value)
{
	if (value >= 192 && target == 3 && place == 1)
		return (1);
	if (value >= 128 && target == 2 && place == 1)
		return (1);
	value -= 128;
	if (value >= 64 && target == 1 && place == 1)
		return (1);
	value -= 64;
	if (value >= 48 && target == 3 && place == 2)
		return (1);
	if (value >= 32 && target == 2 && place == 2)
		return (1);
	value -= 32;
	if (value >= 16 && target == 1 && place == 2)
		return (1);
	value -= 16;
	if (value >= 12 && target == 3 && place == 3)
		return (1);
	if (value >= 8 && target == 2 && place == 3)
		return (1);
	value -= 8;
	if (value >= 4 && target == 1 && place == 3)
		return (1);
	return (0);
}

void	live(unsigned char **pc)
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

void	ld(unsigned char **pc, char *arene)
{
	char	value;

	if (oct_codage(3, 1, **pc) == 1)
	{
		*pc++;
		// cest un T_IND
	}
	value = **pc;
	*pc++;
	arene[**pc * REG_SIZE] += value;
	*pc++;
}

void	st(unsigned char **pc, char *arene)
{
	char	*target;

	target = &arene[**pc * REG_SIZE];
}
