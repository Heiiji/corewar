/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 09:11:12 by jjuret            #+#    #+#             */
/*   Updated: 2017/12/07 13:16:47 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	exec(t_vm *env, t_champ *champ)
{
	unsigned char commande;

	champ->pc = champ->pc % MEM_SIZE;
	commande = env->arene[champ->pc];
	champ->pc += 1;
	if (commande == 1)
	{
		if (champ->action != NULL)
			live(env->arene, champ, env);
		else
			champ->cycle += 10;
	}
	exec2(env, champ, commande);
	if (commande > 16 || commande == 0)
		champ->cycle += 1;
	if (champ->action == NULL && commande <= 16 && commande != 0)
	{
		champ->pc -= 1;
		champ->action = &env->arene[champ->pc];
	}
	else if (champ->action != NULL)
		champ->action = NULL;
	rang(env, env->champ);
}
