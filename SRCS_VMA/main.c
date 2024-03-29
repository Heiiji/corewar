/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 13:00:45 by jjuret            #+#    #+#             */
/*   Updated: 2017/12/08 10:02:18 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_vm_error(char *error)
{
	ft_put(error, ft_strlen(error) - 1, 2, 0);
	exit(0);
}

void	crawler(t_vm *env)
{
	t_champ						*champ;
	int							activity;
	static unsigned long long	cycle = 0;
	unsigned long long			maxcycle;

	maxcycle = CYCLE_TO_DIE;
	while (cycle < maxcycle)
	{
		activity = 0;
		champ = env->champ;
		while (champ && cycle >= champ->cycle)
		{
			activity += 1;
			exec(env, champ);
			if (champ->next)
				champ = champ->next;
			else
				champ = env->champ;
			if (champ->cycle >= cycle && env->champ->cycle <= cycle)
				champ = env->champ;
		}
		cycle += 1;
		if (cycle >= maxcycle)
			maxcycle += check_live(env);
	}
}

void	passive_check(int ac)
{
	if (ac < 2)
		ft_vm_error("Erreur d'argument\n");
	if (CYCLE_TO_DIE < 1 || CYCLE_DELTA < 1 || IND_SIZE != 2 || REG_SIZE != 4)
		ft_vm_error("Erreur de variables d'environnement\n");
}

t_champ	*champions(int cur, t_champ *champ, char **av, int ac)
{
	t_champ *target;

	target = NULL;
	while (cur < ac)
	{
		if (!(champ = (t_champ*)malloc(sizeof(t_champ))))
			ft_vm_error("Erreur de malloc sur les champions\n");
		champ->id = put_name(&cur, av);
		champ->action = NULL;
		if ((champ->fd = open(av[cur], O_RDONLY)) < 0)
			ft_vm_error("Erreur d'ouverture des fichier\n");
		ft_memset(champ->registre, 0, REG_SIZE * REG_NUMBER);
		cur++;
		champ->next = target;
		target = champ;
		champ = NULL;
	}
	return (target);
}

int		main(int ac, char **av)
{
	int		cur;
	t_vm	env;
	t_champ	*champ;

	passive_check(ac);
	cur = 1;
	if (ft_strcmp(av[1], "-dump") == 0)
	{
		env.nbr_cycles = ft_atoi(av[2]);
		cur += 2;
	}
	else
		env.nbr_cycles = CYCLE_TO_DIE;
	env.champ = champions(cur, champ, av, ac);
	make_arene(&env);
	crawler(&env);
	ft_put(env.champ->head.prog_name, ft_strlen(env.champ->head.prog_name) - \
	1, 1, 0);
	ft_put(" Win !\n", 7, 1, 0);
	return (0);
}
