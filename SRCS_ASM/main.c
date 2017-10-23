#include "../includes/corewar.h"

static t_asm *ft_init_variables(int ac, char **av)
{
	t_asm	*s_asm;
	if (!(s_asm = (t_asm *)malloc(sizeof(t_asm))))
		ft_error(1, "s_asm");
	if ((s_asm->ac = ac) == 1)
		ft_error(2, NULL);
	s_asm->av = av;
	s_asm->file = NULL;
	s_asm->bool_name = 0;
	s_asm->bool_comment = 0;
	s_asm->magic = COREWAR_EXEC_MAGIC;
	s_asm->prog_size = 0; // Hmmm
	return (s_asm);
}

//  ⛵ Le Maiiiiin ! 🆒

int main(int argc, char **argv)
{
	t_asm *s_asm;

	s_asm = ft_init_variables(argc, argv);
	ft_open_check_and_get_file(s_asm);

// Besoin de verifier le .s
	// ft_ ....
	ft_check_file_s(s_asm);

	// Afficher le .s si -a en argv[1] et exit, sinon transforme le .s en .cor
	if (strcmp(argv[1], "-a") == 0)
		ft_print_file(s_asm->file);
	else
	{
	// Besoin de transformer le .s en .cor
		//ft_ ....
		;
	}
getchar(); // Pour verifier les fuites. Ne pas mettre le flag -a.
	return (0);
}