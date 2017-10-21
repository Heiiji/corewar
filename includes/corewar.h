#ifndef COREWAR_H
# define COREWAR_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)

# define BUFF_SIZE 32


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
 }				t_asm;

void		ft_error(size_t id_error, char *name);
void		ft_print_file(char **tab_file);
void 		ft_check_file_s(t_asm *s_asm);
void		ft_open_check_and_get_file(t_asm *s_asm);

/*
** Virtual Machine Part
*/

typedef struct	s_vm
{
	int		ac;
	char	**av;
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

int			get_next_line(int const fd, char **line);
char		**ft_malloc_tabtab(char **tab, char *str);

#endif