/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 12:45:17 by jjuret            #+#    #+#             */
/*   Updated: 2017/11/02 16:33:41 by jjuret           ###   ########.fr       */
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
	ft_memcpy(tmp, *pc, 4);
	tmp[4] = '\0';
	ft_put(tmp, 4, 1, 0);
	ft_put(" is alive !", 11, 1, 0);
	free(tmp);
	*pc += 4;
}

void	ld(unsigned char **pc, char *arene, t_champ *champ)
{
	unsigned char	value;
	unsigned char	*elem;
	short			val;
	int				val2;
	unsigned char	*ref;

	ref = *pc - 1;
	if (oct_codage(3, 1, **pc) == 1)
	{
		*pc += 1;
		elem = ft_memdup(*pc, 4);
		val2 = (int)(*elem);
		*pc += 4;
		champ->registre[(REG_SIZE * **pc) % (REG_SIZE * REG_NUMBER)] = value;
	}
	else
	{
		*pc += 1;
		elem = ft_memdup(*pc, 2);
		val = (short)(*elem);
		*pc += 2;
		champ->registre[(REG_SIZE * **pc) % (REG_SIZE * REG_NUMBER)] = value;
	}
	*pc += 1;
}

void	st(unsigned char **pc, unsigned char *arene, t_champ *champ)
{
	unsigned char	*reg;
	unsigned char	*ref;
	unsigned char	*elem;

	ref = *pc - 1;
	if (oct_codage(1, 2, **pc) == 1)
	{
		*pc += 1;
		reg = champ->registre[(REG_SIZE * **pc) % (REG_SIZE * REG_NUMBER)];
		*pc += 1;
		ft_memcpy(champ->registre[(REG_SIZE * **pc) % (REG_SIZE * REG_NUMBER)], reg, REG_SIZE);
	}
	else
	{
		*pc += 1;
		reg = champ->registre[(REG_SIZE * **pc) % (REG_SIZE * REG_NUMBER)];
		*pc += 1;
		elem = ft_memdup(*pc, 2);
		ft_memcpy(champ->registre[(REG_SIZE * (short)(*elem)) % (REG_SIZE * REG_NUMBER)], reg, REG_SIZE);
		*pc += 2;
		free(elem);
	}
	champ->>carry = 1;
	*pc += 1;
}

void	add(unsigned char **pc, t_champ *champ)
{
	unsigned char	*reg;
	unsigned char	*reg2;

	*pc += 1;
	champ->registre[*(*pc + 2)] = champ->registre[*(*pc + 1)] + champ->registre[**pc];
	champ->carry = 1;
	*pc += 3;
}

void	sub(unsigned char **pc, t_champ *champ)
{
	unsigned char	*reg;
	unsigned char	*reg2;

	*pc += 1;
	champ->registre[*(*pc + 2)] = champ->registre[*(*pc + 1)] - champ->registre[**pc];
	champ->carry = 1;
	*pc += 3;
}

void	and(unsigned char **pc, t_champ *champ)
{

}
