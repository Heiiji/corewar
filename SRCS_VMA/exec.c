/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 10:47:32 by jjuret            #+#    #+#             */
/*   Updated: 2017/11/03 12:10:41 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	exec(t_vm *env, t_champ *champ)
{
	unsigned char commande;

	commande = env->arene[champ->pc];
	champ->pc += 1;
	if (commande == 1)
	{
		live(env->arene, champ);
		champ->cycle += 10;
	}
	if (commande == 2)
	{
		ld(env->arene, champ);
		champ->cycle += 5;
	}
	if (commande == 3)
	{
		st(env->arene, champ);
		champ->cycle += 5;
	}
	exec2(env, champ, commande);
	if  (commande > 16)
		champ->cycle += 1;
	rang(env, champ);
}

void	exec2(t_vm *env, t_champ *champ, unsigned char commande)
{
	if (commande == 4)
	{
		add(env->arene, champ);
		champ->cycle += 10;
	}
	if (commande == 5)
	{
		sub(env->arene, champ);
		champ->cycle += 10;
	}
	if (commande == 6)
	{
		and(env->arene, champ);
		champ->cycle += 6;
	}
	if (commande == 7)
	{
		or(env->arene, champ);
		champ->cycle += 6;
	}
	if (commande == 8)
	{
		xor(env->arene, champ);
		champ->cycle += 6;
	}
}
