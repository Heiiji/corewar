/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 10:47:32 by jjuret            #+#    #+#             */
/*   Updated: 2017/11/06 13:13:07 by jjuret           ###   ########.fr       */
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
		if (champ->action != NULL)
			live(env->arene, champ);
		else
			champ->cycle += 10;
	}
	if (commande == 2)
	{
		if (champ->action != NULL)
			ld(env->arene, champ);
		else
			champ->cycle += 5;
	}
	if (commande == 3)
	{
		if (champ->action != NULL)
			st(env->arene, champ);
		else
			champ->cycle += 5;
	}
	exec2(env, champ, commande);
	if  (commande > 16)
		champ->cycle += 1;
	if (champ->action == NULL)
	{
		champ->pc -= 1;
		champ->action = &env->arene[champ->pc];
		rang(env, champ);
	}
}

void	exec2(t_vm *env, t_champ *champ, unsigned char commande)
{
	if (commande == 4)
	{
		if (champ->action != NULL)
			add(env->arene, champ);
		else
			champ->cycle += 10;
	}
	if (commande == 5)
	{
		if (champ->action != NULL)
			sub(env->arene, champ);
		else
			champ->cycle += 10;
	}
	if (commande == 6)
	{
		if (champ->action != NULL)
			and(env->arene, champ);
		else
			champ->cycle += 6;
	}
	if (commande == 7)
	{
		if (champ->action != NULL)
			or(env->arene, champ);
		else
			champ->cycle += 6;
	}
	if (commande == 8)
	{
		if (champ->action != NULL)
			xor(env->arene, champ);
		else
			champ->cycle += 6;
	}
}
