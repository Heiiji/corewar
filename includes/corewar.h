#ifndef COREWAR_H
# define COREWAR_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include "op.h"

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)

#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"

# define COREWAR_EXEC_MAGIC		0xea83f3 // Doit se trouver au debut du .cor


# define BUFF_SIZE (CHAMP_MAX_SIZE)
# define OPEN_MAX 666


/*
** Assembler part
*/

 typedef struct s_asm
 {
 	int		ac;
 	char	**av;
 	char	**file;
 	char	bool_name;
 	char	bool_comment;

	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
 }				t_asm;

void		ft_error(size_t id_error, char *name);
void		ft_print_file(char **tab_file);
void 		ft_check_file_s(t_asm *s_asm);
void		ft_open_check_and_get_file(t_asm *s_asm);

/*
** Virtual Machine Part
*/

typedef struct	s_champ
{
	int				name;
	int				fd;
	long			pc; //point d'entree
	struct t_champ	*next;
}				t_champ;

typedef struct	s_vm
{
	int		nbr_cycles;
	t_champ	*champ;
	char	*arene;
}				t_vm;


/*
** Generics functions
*/

void		ft_strdel(char **as);
void		ft_put(char *str, char c, char fd, char bool_free);
size_t		ft_strlen(const char *str);
int			ft_strcmp(const char *s1, const char *s2);
void		*ft_memmove(void *dst, const void *src, size_t len);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *src);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
void		ft_memdel(void **ap);
int			ft_atoi(const char *str);
char		*ft_itoa(int n);
void		*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);

int			get_next_line(int const fd, char **line);
char		**ft_malloc_tabtab(char **tab, char *str);

#endif
