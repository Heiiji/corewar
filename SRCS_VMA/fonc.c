/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 12:45:17 by jjuret            #+#    #+#             */
/*   Updated: 2017/11/17 10:42:59 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		oct_codage(char target, char place, unsigned char value)
{
	if (value >= 192 && target == 3 && place == 1)
		return (1);
	if (value >= 128 && target == 2 && place == 1)
		return (1);
	if (value >= 128)
		value -= 128;
	if (value >= 64 && target == 1 && place == 1)
		return (1);
	if (value >= 64)
		value -= 64;
	if (value >= 48 && target == 3 && place == 2)
		return (1);
	if (value >= 32 && target == 2 && place == 2)
		return (1);
	if (value >= 32)
		value -= 32;
	if (value >= 16 && target == 1 && place == 2)
		return (1);
	if (value >= 16)
		value -= 16;
	if (value >= 12 && target == 3 && place == 3)
		return (1);
	if (value >= 8 && target == 2 && place == 3)
		return (1);
	if (value >= 8)
		value -= 8;
	if (value >= 4 && target == 1 && place == 3)
		return (1);
	return (0);
}

void	live(unsigned char *arene, t_champ *champ, t_vm *env)
{
	char	*tmp;

	tmp = ft_itoa(get_int(&arene[champ->pc]));
	ft_put(tmp, 4, 1, 0);
	ft_put(" is alive !", 10, 1, 0);
	free(tmp);
	env->winner = get_int(&arene[champ->pc]);
	champ->carry = (champ->carry == 1) ? 0 : 1;
	champ->live = 1;
	champ->pc += 4;
}

void	ld(unsigned char *arene, t_champ *champ)
{
	unsigned char		value;
	unsigned char		*elem;
	int					val;
	short				val2;
	unsigned long long	ref;

	ref = champ->pc - 1;
	if (oct_codage(3, 1, arene[champ->pc]) == 1)
	{
		champ->pc += 1;
		val2 = get_short(&arene[champ->pc]);
		champ->pc += 2;
		ft_memcpy(&champ->registre[REG_SIZE * arene[champ->pc]], &arene[(ref + (val2 % IDX_MOD)) % MEM_SIZE], REG_SIZE);
	}
	else
	{
		champ->pc += 1;
		val = get_int(&arene[champ->pc]);
		val = get_int(&arene[(ref + val) % MEM_SIZE]);
		champ->pc += 4;
		ft_memcpy(&champ->registre[arene[champ->pc]], &arene[(ref + (val % IDX_MOD)) % MEM_SIZE], REG_SIZE);
	}
	champ->carry = (champ->carry == 1) ? 0 : 1;
	champ->pc += 1;
}

void	st(unsigned char *arene, t_champ *champ)
{
	unsigned char	*reg;
	unsigned char	*elem;

	if (oct_codage(1, 2, arene[champ->pc]) == 1)
	{
		champ->pc += 1;
		elem = &arene[champ->pc];
		reg = &champ->registre[(REG_SIZE * *elem) % (REG_SIZE * REG_NUMBER)];
		champ->pc += 1;
		ft_memcpy(&champ->registre[(REG_SIZE * *elem + 1) % (REG_SIZE * REG_NUMBER)], reg, REG_SIZE);
	}
	else
	{
		champ->pc += 1;
		reg = &champ->registre[(REG_SIZE * champ->pc) % (REG_SIZE * REG_NUMBER)];
		champ->pc += 1;
		elem = ft_memdup(&arene[champ->pc], 2);
		ft_memcpy(&champ->registre[(REG_SIZE * get_short(elem)) % (REG_SIZE * REG_NUMBER)], reg, REG_SIZE);
		champ->pc += 2;
		free(elem);
	}
	champ->carry = (champ->carry == 1) ? 0 : 1;
	champ->pc += 1;
}

void	add(unsigned char *arene, t_champ *champ)
{
	champ->pc += 1;
	champ->registre[arene[champ->pc + 2]] = champ->registre[arene[champ->pc + 1] * REG_SIZE] + champ->registre[arene[champ->pc] * REG_SIZE];
	champ->carry = (champ->carry == 1) ? 0 : 1;
	champ->pc += 3;
}
