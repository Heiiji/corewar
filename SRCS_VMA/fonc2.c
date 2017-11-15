/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 07:51:18 by jjuret            #+#    #+#             */
/*   Updated: 2017/11/15 11:40:29 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	sub(unsigned char *arene, t_champ *champ)
{
	champ->pc += 1;
	champ->registre[arene[champ->pc + 2]] = champ->registre[arene[champ->pc + 1\
	]] - champ->registre[arene[champ->pc]];
	champ->carry = 1;
	champ->pc += 3;
}

void	and(unsigned char *arene, t_champ *champ)
{
	int 			val;
	int				val2;
	int				refn;
	unsigned char	ref;

	ref = arene[champ->pc];
	refn = champ->pc - 1;
	champ->pc += 1;
	if (oct_codage(1,1, ref) == 1)
	{
		val = champ->registre[arene[champ->pc]];
		champ->pc += 1;
	}
	else if (oct_codage(3,1, ref) == 1)
	{
		val = get_short(&arene[champ->pc]);
		champ->pc += 2;
	}
	else
	{
		val = get_int(&arene[champ->pc - 2 + get_int(&arene[champ->pc % MEM_SIZE])]);
		champ->pc += 4;
	}
	if (oct_codage(1,2, ref) == 1)
	{
		val2 = champ->registre[arene[champ->pc % MEM_SIZE]];
		champ->pc += 1;
	}
	else if (oct_codage(3,2, ref) == 1)
	{
		val2 = get_short(&arene[champ->pc % MEM_SIZE]);
		champ->pc += 2;
	}
	else
	{
		val2 = get_int(&arene[refn + get_int(&arene[champ->pc % MEM_SIZE])]);
		champ->pc += 4;
	}
	val = val & val2;
	memcpy(&(champ->registre[REG_SIZE * arene[champ->pc % MEM_SIZE]]), (char*)(&val), 4);
	champ->pc += 1;
}

void	or(unsigned char *arene, t_champ *champ)
{
	int 			val;
	int				val2;
	int				refn;
	unsigned char	ref;

	ref = arene[champ->pc];
	refn = champ->pc - 1;
	champ->pc += 1;
	if (oct_codage(1,1, ref) == 1)
	{
		val = champ->registre[arene[champ->pc]];
		champ->pc += 1;
	}
	else if (oct_codage(3,1, ref) == 1)
	{
		val = get_short(&arene[champ->pc]);
		champ->pc += 2;
	}
	else
	{
		val = get_int(&arene[champ->pc - 2 + get_int(&arene[champ->pc % MEM_SIZE])]);
		champ->pc += 4;
	}
	if (oct_codage(1,2, ref) == 1)
	{
		val2 = champ->registre[arene[champ->pc % MEM_SIZE]];
		champ->pc += 1;
	}
	else if (oct_codage(3,2, ref) == 1)
	{
		val2 = get_short(&arene[champ->pc % MEM_SIZE]);
		champ->pc += 2;
	}
	else
	{
		val = get_int(&arene[refn + get_int(&arene[champ->pc % MEM_SIZE])]);
		champ->pc += 4;
	}
	val = val | val2;
	memcpy(&(champ->registre[REG_SIZE * arene[champ->pc % MEM_SIZE]]), (char*)(&val), 4);
	champ->pc += 1;
}

void	xor(unsigned char *arene, t_champ *champ)
{
	int 			val;
	int				val2;
	int				refn;
	unsigned char	ref;

	ref = arene[champ->pc];
	refn = champ->pc - 1;
	champ->pc += 1;
	if (oct_codage(1,1, ref) == 1)
	{
		val = champ->registre[arene[champ->pc]];
		champ->pc += 1;
	}
	else if (oct_codage(3,1, ref) == 1)
	{
		val = get_short(&arene[champ->pc]);
		champ->pc += 2;
	}
	else
	{
		val = get_int(&arene[champ->pc - 2 + get_int(&arene[champ->pc % MEM_SIZE])]);
		champ->pc += 4;
	}
	if (oct_codage(1,2, ref) == 1)
	{
		val2 = champ->registre[arene[champ->pc % MEM_SIZE]];
		champ->pc += 1;
	}
	else if (oct_codage(3,2, ref) == 1)
	{
		val2 = get_short(&arene[champ->pc % MEM_SIZE]);
		champ->pc += 2;
	}
	else
	{
		val = get_int(&arene[refn + get_int(&arene[champ->pc % MEM_SIZE])]);
		champ->pc += 4;
	}
	val = val ^ val2;
	memcpy(&(champ->registre[REG_SIZE * arene[champ->pc % MEM_SIZE]]), (char*)(&val), 4);
	champ->pc += 1;
}

void	zjump(unsigned char *arene, t_champ *champ)
{
	short	value;

	value = get_short(&arene[champ->pc]);
	if (champ->carry == 1)
		champ->pc = champ->pc - 1 + value;
	else
		champ->pc += 2;
	champ->carry = 1;
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
	if (oct_codage(1,1, ref) == 1)
	{
		val = champ->registre[arene[champ->pc]];
		champ->pc += 1;
	}
	else
	{
		val = get_short(&champ->registre[arene[champ->pc % MEM_SIZE]]);
		if (oct_codage(2,1, ref) == 1)
			val = get_short(&arene[(refn + (val % IDX_MOD)) % MEM_SIZE]);
		champ->pc += 2;
	}
	if (oct_codage(1,2, ref) == 1)
	{
		val2 = champ->registre[arene[champ->pc]];
		champ->pc += 1;
	}
	else
	{
		val2 = get_short(&champ->registre[arene[champ->pc % MEM_SIZE]]);
		val2 = get_short(&arene[(refn + (val2 % IDX_MOD)) % MEM_SIZE]);
		champ->pc += 2;
	}
	ft_memcpy(&champ->registre[(arene[champ->pc] % REG_NUMBER) * REG_SIZE], &arene[(val + val2) % MEM_SIZE], REG_SIZE);
	champ->pc += 1;
}

void	sti(unsigned char *arene, t_champ *champ)
{
	long			refn;
	unsigned char	ref;
	unsigned char	reg;
	unsigned char	add;

	ref = arene[champ->pc];
	refn = champ->pc - 1;
	champ->pc += 1;
	reg = arene[champ->pc];
	champ->pc += 1;
	if (oct_codage(1,2, ref) == 1)
	{
		add = champ->registre[arene[champ->pc % MEM_SIZE] % (REG_NUMBER * REG_SIZE)];
		champ->pc += 1;
	}
	else
	{
		add = get_short(&arene[champ->pc % MEM_SIZE]);
		champ->pc += 2;
	}
	if (oct_codage(1,3, ref) == 1)
	{
		ft_memcpy(&(arene[(add + get_short(&champ->registre[arene[champ->pc % MEM_SIZE]])) % MEM_SIZE]), &champ->registre[reg * REG_SIZE], REG_SIZE);
		champ->pc += 1;
	}
	else
	{
		ft_memcpy(&(arene[(add + get_short(&arene[champ->pc]) + refn) % MEM_SIZE]), &champ->registre[reg * REG_SIZE], REG_SIZE);
		champ->pc += 2;
	}
}

void	ft_fork(unsigned char *arene, t_champ *champ, t_vm *env)
{
	long			refn;
	short			target;
	t_champ			*new;

	refn = champ->pc - 1;
	target = get_short(&arene[champ->pc]);
	new = (t_champ*)malloc(sizeof(t_champ));
	new->action = NULL;
	new->next = env->champ;
	new->pc = refn + (target % IDX_MOD);
	new->id = champ->id;
	ft_memcpy(new->registre, champ->registre, REG_SIZE * REG_NUMBER);
	new->carry = champ->carry;
	new->cycle = champ->cycle;
	new->head = champ->head;
	rang(env, new);
	champ->pc += 2;
}

void	lld(unsigned char *arene, t_champ *champ)
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
		ft_memcpy(&champ->registre[arene[champ->pc]], &arene[(ref + val2) % MEM_SIZE], REG_SIZE);
		champ->pc += 1;
	}
	else
	{
		champ->pc += 1;
		val = get_int(&arene[champ->pc]);
		val = get_int(&arene[(ref + val) % MEM_SIZE]);
		champ->pc += 4;
		ft_memcpy(&champ->registre[arene[champ->pc]], &arene[(ref + val) % MEM_SIZE], REG_SIZE);
		champ->pc += 1;
	}
	champ->carry = 1;
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
	if (oct_codage(1,1, ref) == 1)
	{
		val = champ->registre[arene[champ->pc]];
		champ->pc += 1;
	}
	else
	{
		val = get_short(&champ->registre[arene[champ->pc % MEM_SIZE]]);
		if (oct_codage(2,1, ref) == 1)
			val = get_short(&arene[(refn + val) % MEM_SIZE]);
		champ->pc += 2;
	}
	if (oct_codage(1,2, ref) == 1)
	{
		val2 = champ->registre[arene[champ->pc]];
		champ->pc += 1;
	}
	else
	{
		val2 = get_short(&champ->registre[arene[champ->pc]]);
		val2 = get_short(&arene[(refn + val2) % MEM_SIZE]);
		champ->pc += 2;
	}
	ft_memcpy(&champ->registre[arene[champ->pc]], &arene[(val + val2) % MEM_SIZE], REG_SIZE);
	champ->pc += 1;
}

void	ft_lfork(unsigned char *arene, t_champ *champ, t_vm *env)
{
	long			refn;
	short			target;
	t_champ			*new;

	refn = champ->pc - 1;
	target = get_short(&arene[champ->pc]);
	new = (t_champ*)malloc(sizeof(t_champ));
	new->action = NULL;
	new->next = env->champ;
	new->pc = refn + target;
	new->id = champ->id;
	ft_memcpy(new->registre, champ->registre, REG_SIZE * REG_NUMBER);
	new->carry = champ->carry;
	new->cycle = champ->cycle;
	new->head = champ->head;
	rang(env, new);
	champ->pc += 2;
}

void	aff(unsigned char *arene, t_champ *champ)
{
	champ->pc += 1;
	ft_put((char*)&arene[champ->pc], 1, 1, 0);
	champ->pc += 1;
}
