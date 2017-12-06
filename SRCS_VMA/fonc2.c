/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 07:51:18 by jjuret            #+#    #+#             */
/*   Updated: 2017/12/06 11:10:55 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	and(unsigned char *arene, t_champ *champ)
{
	int				val;
	int				val2;
	int				refn;
	unsigned char	ref;

	ref = arene[champ->pc];
	refn = champ->pc - 1;
	champ->pc += 1;
	if (oct_codage(1, 1, ref) == 1)
		val = get_int(&champ->registre[arene[champ->pc]]);
	else if (oct_codage(3, 1, ref) == 1)
	{
		val = get_short(&arene[champ->pc]);
		champ->pc += 1;
	}
	else
	{
		val = get_int(&arene[champ->pc - 2 + get_int(&arene[champ->pc % \
			MEM_SIZE]) % MEM_SIZE]);
		champ->pc += 3;
	}
	champ->pc += 1;
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
	champ->pc += 1;
	val = val & val2;
	memcpy(&(champ->registre[REG_SIZE * (arene[champ->pc % MEM_SIZE]) % \
	REG_NUMBER]), (unsigned char*)(&val), 4);
	champ->pc += 1;
}

void	or(unsigned char *arene, t_champ *champ)
{
	int				val;
	int				val2;
	int				refn;
	unsigned char	ref;

	ref = arene[champ->pc];
	refn = champ->pc - 1;
	champ->pc += 1;
	if (oct_codage(1, 1, ref) == 1)
		val = champ->registre[arene[champ->pc]];
	else if (oct_codage(3, 1, ref) == 1)
	{
		val = get_short(&arene[champ->pc]);
		champ->pc += 1;
	}
	else
	{
		val = get_int(&arene[champ->pc - 2 + get_int(&arene[champ->pc % \
			MEM_SIZE])]);
		champ->pc += 3;
	}
	champ->pc += 1;
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

void	xor(unsigned char *arene, t_champ *champ)
{
	int				val;
	int				val2;
	int				refn;
	unsigned char	ref;

	ref = arene[champ->pc];
	refn = champ->pc - 1;
	champ->pc += 1;
	if (oct_codage(1, 1, ref) == 1)
		val = champ->registre[arene[champ->pc]];
	else if (oct_codage(3, 1, ref) == 1)
	{
		val = get_short(&arene[champ->pc]);
		champ->pc += 1;
	}
	else
	{
		val = get_int(&arene[champ->pc - 2 + get_int(&arene[champ->pc % \
			MEM_SIZE])]);
		champ->pc += 3;
	}
	champ->pc += 1;
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
	champ->pc += 1;
	val = val ^ val2;
	memcpy(&(champ->registre[REG_SIZE * arene[champ->pc % MEM_SIZE]]), \
	(char*)(&val), 4);
	champ->pc += 1;
}

void	ldi(unsigned char *arene, t_champ *champ)
{
	unsigned char	ref;
	long			refn;
	int				val;
	int				val2;

	ref = arene[champ->pc];
	refn = champ->pc - 1;
	champ->pc += 1;
	if (oct_codage(1, 1, ref) == 1)
		val = champ->registre[arene[champ->pc]];
	else
	{
		val = get_short(&champ->registre[arene[champ->pc % MEM_SIZE]]);
		if (oct_codage(2, 1, ref) == 1)
			val = get_short(&arene[(refn + (val % IDX_MOD)) % MEM_SIZE]);
		champ->pc += 1;
	}
	champ->pc += 1;
	if (oct_codage(1, 2, ref) == 1)
		val2 = champ->registre[arene[champ->pc]];
	else
	{
		val2 = get_short(&champ->registre[arene[champ->pc % MEM_SIZE]]);
		val2 = get_short(&arene[(refn + (val2 % IDX_MOD)) % MEM_SIZE]);
		champ->pc += 1;
	}
	champ->pc += 1;
	ft_memcpy(&champ->registre[(arene[champ->pc] % REG_NUMBER) * REG_SIZE], \
	&arene[(val + val2) % MEM_SIZE], REG_SIZE);
	champ->pc += 1;
}

void	sti(unsigned char *arene, t_champ *champ)
{
	long			refn;
	unsigned char	ref;
	unsigned char	reg;
	unsigned char	add;

	ref = arene[champ->pc % MEM_SIZE];
	refn = champ->pc - 1;
	reg = arene[(champ->pc + 1) % MEM_SIZE];
	champ->pc += 2;
	if (oct_codage(1, 2, ref) == 1)
		add = champ->registre[arene[champ->pc % MEM_SIZE] % (REG_NUMBER * \
			REG_SIZE)];
	else
	{
		add = get_short(&arene[champ->pc % MEM_SIZE]);
		champ->pc += 1;
	}
	champ->pc += 1;
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

void	lldi(unsigned char *arene, t_champ *champ)
{
	unsigned char	ref;
	long			refn;
	int				val;
	int				val2;

	ref = arene[champ->pc];
	refn = champ->pc - 1;
	champ->pc += 1;
	if (oct_codage(1, 1, ref) == 1)
		val = champ->registre[arene[champ->pc]];
	else
	{
		val = get_short(&champ->registre[arene[champ->pc % MEM_SIZE]]);
		if (oct_codage(2, 1, ref) == 1)
			val = get_short(&arene[(refn + val) % MEM_SIZE]);
		champ->pc += 1;
	}
	champ->pc += 1;
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
