/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 13:00:45 by jjuret            #+#    #+#             */
/*   Updated: 2017/10/26 10:37:31 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_vm_error(char *error)
{
	ft_put(error, ft_strlen(error), 2, 0);
	exit(0);
}

void	make_player(t_vm *env, int nbr)
{
	int		max_size;
	int		cur;
	char	*line;
	s_champ	*champ;

	cur = 0;
	max_size = MEM_SIZE/nbr;
	champ = env->champ;
	while (champ)
	{
		while (get_next_line(champ->fd, &line) == 1)
		{
			// un memset dans le gn a '0' serait bien
			ft_memcpy(arene[cur * max_size], line, max_size);
			cur ++;
			//on ecrit tout dans l'arene avec un decalage de max_size pour chaque champion (champion n decaler de max_size*(n-1))
		}
		champ = champ->next;
	}
}

void	make_arene(t_vm *env)
{
	t_champ	*cur;
	int		nbr;

	if (!(env->arene = (char*)malloc(MEM_SIZE)))
		ft_vm_error("Erreur de malloc pour l'arene");
	cur = env->champ;
	while (cur)
	{
		cur = cur->next;
		nbr++;
	}
	make_player(env, nbr);
}

int	put_name(int *cur, char **av)
{
	static int	name = 0;

	if (ft_strcmp(av[*cur], "-n"))
	{
		*cur += 1;
		if (av[*cur][0] < (char)'0' || av[*cur][0] > (char)'9')
			ft_vm_error("Erreur de format de la commande");
		return (ft_atoi(av[*cur]));
	}
	else
	{
		name++;
		return (name);
	}
}

int main(int ac, char **av)
{
	int		cur;
	t_vm	env;
	t_champ	*champ;

	if (!(champ = (t_champ*)malloc(sizeof(t_champ))))
		ft_vm_error("Erreur de malloc sur le premier champions");
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
		champ->name = put_name(&cur, av);
		if (!(champ->fd = open(av[cur], O_RDONLY)))
			ft_vm_error("Erreur d'ouverture des fichier");;
		if (!(champ->next = (t_champ*)malloc(sizeof(t_champ))))
			ft_vm_error("Erreur de malloc sur les champions");
		cur++;
	}
	free (champ->next);
	champ->next = NULL;
	make_arene(&env);
	// DEBUG
	champ = env.champ;
	while (champ)
	{
		ft_put(champ->name, ft_strlen(champ->name), 1, 0);
		champ = champ->next;
	}
	return (0);
}
