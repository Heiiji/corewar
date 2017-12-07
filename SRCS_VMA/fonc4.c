/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonc4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:20:28 by jjuret            #+#    #+#             */
/*   Updated: 2017/12/07 13:44:07 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static int	and2(unsigned char *arene, t_champ *champ, unsigned char ref)
{
	if (oct_codage(1, 1, ref) == 1)
	{
		champ->pc += 1;
		return (get_int(&champ->registre[arene[(champ->pc - 1) % MEM_SIZE]]));
	}
	else if (oct_codage(3, 1, ref) == 1)
	{
		champ->pc += 2;
		return (get_short(&arene[(champ->pc - 2) % MEM_SIZE]));
	}
	champ->pc += 4;
	return (get_int(&arene[champ->pc - 6 + get_int(&arene[champ->pc - 4 % \
		MEM_SIZE]) % MEM_SIZE]));
}

void		and(unsigned char *arene, t_champ *champ)
{
	int				val;
	int				val2;
	int				refn;
	unsigned char	ref;

	ref = arene[champ->pc];
	refn = champ->pc - 1;
	champ->pc += 1;
	val = and2(arene, champ, ref);
	if (oct_codage(1, 2, ref) == 1)
		val2 = champ->registre[arene[champ->pc % MEM_SIZE]];
	else if (oct_codage(3, 2, ref) == 1)
	{
		val2 = get_short(&arene[champ->pc % MEM_SIZE]);
		champ->pc += 1;
	}
	else
	{
		val2 = get_int(&arene[champ->pc % MEM_SIZE]);
		champ->pc += 3;
	}
	val = val & val2;
	memcpy(&(champ->registre[REG_SIZE * (arene[champ->pc + 1 % MEM_SIZE]) % \
	REG_NUMBER]), (unsigned char*)(&val), 4);
	champ->pc += 2;
}

static int	or2(unsigned char *arene, t_champ *champ, unsigned char ref)
{
	champ->pc += 1;
	if (oct_codage(1, 1, ref) == 1)
	{
		champ->pc += 1;
		return (champ->registre[arene[champ->pc - 1]]);
	}
	else if (oct_codage(3, 1, ref) == 1)
	{
		champ->pc += 2;
		return (get_short(&arene[champ->pc - 2]));
	}
	champ->pc += 4;
	return (get_int(&arene[champ->pc - 6 + get_int(&arene[champ->pc - 4 % \
			MEM_SIZE])]));
}

void		or(unsigned char *arene, t_champ *champ)
{
	int				val;
	int				val2;
	int				refn;
	unsigned char	ref;

	ref = arene[champ->pc];
	refn = champ->pc - 1;
	val = or2(arene, champ, ref);
	if (oct_codage(1, 2, ref) == 1)
		val2 = champ->registre[arene[champ->pc % MEM_SIZE]];
	else if (oct_codage(3, 2, ref) == 1)
	{
		val2 = get_short(&arene[champ->pc % MEM_SIZE]);
		champ->pc += 1;
	}
	else
	{
		val = get_int(&arene[refn + get_int(&arene[champ->pc % MEM_SIZE])]);
		champ->pc += 3;
	}
	val = val | val2;
	memcpy(&(champ->registre[REG_SIZE * arene[champ->pc + 1 % MEM_SIZE]]), \
	(char*)(&val), 4);
	champ->pc += 2;
}
