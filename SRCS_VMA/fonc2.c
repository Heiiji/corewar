/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 07:51:18 by jjuret            #+#    #+#             */
/*   Updated: 2017/12/07 14:14:31 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static int		sti2(unsigned char *arene, t_champ *champ, unsigned char ref)
{
	champ->pc += 2;
	if (oct_codage(1, 2, ref) == 1)
	{
		champ->pc += 1;
		return (champ->registre[arene[(champ->pc - 1) % MEM_SIZE] % (\
			REG_NUMBER * REG_SIZE)]);
	}
	champ->pc += 2;
	return (get_short(&arene[(champ->pc - 2) % MEM_SIZE]));
}

void			sti(unsigned char *arene, t_champ *champ)
{
	long			refn;
	unsigned char	ref;
	unsigned char	reg;
	unsigned char	add;

	ref = arene[champ->pc % MEM_SIZE];
	refn = champ->pc - 1;
	reg = arene[(champ->pc + 1) % MEM_SIZE];
	add = sti2(arene, champ, ref);
	if (oct_codage(1, 3, ref) == 1)
		ft_memcpy(&(arene[(add + get_short(&champ->registre[arene[champ->pc % \
		MEM_SIZE]])) % MEM_SIZE]), &champ->registre[reg * REG_SIZE], REG_SIZE);
	else
	{
		ft_memcpy(&(arene[(add + get_short(&arene[champ->pc % MEM_SIZE]) + \
refn) % MEM_SIZE]), &champ->registre[(reg % REG_NUMBER) * REG_SIZE], REG_SIZE);
		champ->pc += 1;
	}
	champ->pc += 1;
}

static int		lldi2(unsigned char *arene, t_champ *champ, unsigned \
	char ref, long refn)
{
	int	val;

	champ->pc += 1;
	if (oct_codage(1, 1, ref) == 1)
	{
		champ->pc += 1;
		return (champ->registre[arene[champ->pc - 1]]);
	}
	champ->pc += 2;
	val = get_short(&champ->registre[arene[(champ->pc - 2) % MEM_SIZE]]);
	if (oct_codage(2, 1, ref) == 1)
		val = get_short(&arene[(refn + val) % MEM_SIZE]);
	return (val);
}

void			lldi(unsigned char *arene, t_champ *champ)
{
	unsigned char	ref;
	long			refn;
	int				val;
	int				val2;

	ref = arene[champ->pc];
	refn = champ->pc - 1;
	val = lldi2(arene, champ, ref, refn);
	if (oct_codage(1, 2, ref) == 1)
		val2 = champ->registre[arene[champ->pc]];
	else
	{
		val2 = get_short(&champ->registre[arene[champ->pc]]);
		val2 = get_short(&arene[(refn + val2) % MEM_SIZE]);
		champ->pc += 1;
	}
	ft_memcpy(&champ->registre[arene[champ->pc + 1]], &arene[(val + val2) % \
	MEM_SIZE], REG_SIZE);
	champ->pc += 2;
}
