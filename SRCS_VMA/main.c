/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 13:00:45 by jjuret            #+#    #+#             */
/*   Updated: 2017/11/06 13:02:18 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_vm_error(char *error)
{
	ft_put(error, ft_strlen(error), 2, 0);
	exit(0);
}

int	put_name(int *cur, char **av)
{
	static int	name = 0;

	if (ft_strcmp(av[*cur], "-n") == 0)
	{
		*cur += 1;
		if (av[*cur][0] < (char)'0' || av[*cur][0] > (char)'9')
			ft_vm_error("Erreur de format de la commande\n");
		return (ft_atoi(av[*cur]));
	}
	else
	{
		name++;
		return (name);
	}
}

void	crawler(t_vm *env)
{
	t_champ				*champ;
	int					activity;
	unsigned long long	cycle;

	cycle = 0;
	while (cycle < CYCLE_TO_DIE)
	{
		activity = 0;
		champ = env->champ;
		while (cycle == champ->cycle)
		{
			activity += 1;
			champ = champ->next;
			exec(env, env->champ);
		}
		cycle += 1;
		// parse(env, activity);
	}
}

int main(int ac, char **av)
{
	int		cur;
	t_vm	env;
	t_champ	*champ;

	if (ac < 2)
		ft_vm_error("Erreur d'argument\n");
	if (!(champ = (t_champ*)malloc(sizeof(t_champ))))
		ft_vm_error("Erreur de malloc sur le premier champions\n");
	env.champ = champ;
	champ->next = NULL;
	cur = 1;
	if (ft_strcmp(av[1], "-dump") == 0)
	{
		env.nbr_cycles = ft_atoi(av[2]);
		cur += 2;
	}
	while (cur < ac)
	{
		if (champ->next)
			champ = champ->next;
		champ->id = put_name(&cur, av);
		champ->action = NULL;
		if (!(champ->fd = open(av[cur], O_RDONLY)))
			ft_vm_error("Erreur d'ouverture des fichier\n");
		ft_memset(champ->registre, 0, REG_SIZE * REG_NUMBER);
		if (!(champ->next = (t_champ*)malloc(sizeof(t_champ))))
			ft_vm_error("Erreur de malloc sur les champions\n");
		cur++;
	}
	free (champ->next);
	champ->next = NULL;
	make_arene(&env);
	crawler(&env);
	return (0);
}
