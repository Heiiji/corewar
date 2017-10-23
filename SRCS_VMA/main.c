#include "../includes/corewar.h"

int	put_name(int *cur, char **av)
{
	static	name = 0;

	if (ft_strcmp(av[*cur], "-n"))
	{
		*cur++;
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
		ft_error(); //voir comment fonctionne la gestion d'erreur
	env.champ = champ;
	cur = 1;
	if (ft_strcmp(av[1], "-dump") == 0)
	{
		env.nbr_cycles = ft_atoi(av[2]);
		cur += 2;
	}
	while (cur < ac)
	{
		champ->name = put_name(&cur, av);
		if (!(champ.next = (t_champ*)malloc(sizeof(t_champ))))
			ft_error(); //voir comment fonctionne la gestion d'erreur
		champ = champ->next;
		cur++;
	}
	champ->next = NULL;
	// DEBUG
	champ = env.champ;
	while (champ)
	{
		// print les champion
	}
	return (0);
}
