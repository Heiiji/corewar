/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuret <jjuret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:59:01 by jjuret            #+#    #+#             */
/*   Updated: 2017/12/07 16:17:44 by jjuret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE
# define IDX_MOD				(MEM_SIZE / 8)

# define REG_NUMBER				16
# define MEM_SIZE				(4*1024)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define COREWAR_EXEC_MAGIC		0xea83f3

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50

# define BUFF_SIZE (CHAMP_MAX_SIZE)
# ifndef OPEN_MAX
#  define OPEN_MAX 666
# endif

/*
** Assembler part
*/

typedef struct			s_header
{
  unsigned int			magic;
  char					prog_name[PROG_NAME_LENGTH + 1];
  unsigned int			prog_size;
  char					comment[COMMENT_LENGTH + 1];
}						t_header;

typedef struct			s_asm
{
	int					ac;
	char				**av;
	char				**file;
	char				bool_name;
	char				bool_comment;
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}						t_asm;

void					ft_error(size_t id_error, char *name);
void					ft_print_file(char **tab_file);
void					ft_check_file_s(t_asm *s_asm);
void					ft_open_check_and_get_file(t_asm *s_asm);

/*
** Virtual Machine Part
*/

typedef struct			s_champ
{
	int					id;
	t_header			head;
	int					fd;
	unsigned char		*action;
	unsigned long long	cycle;
	unsigned long long	pc;
	char				carry;
	char				live;
	unsigned char		registre[REG_SIZE * REG_NUMBER];
	struct s_champ		*next;
}						t_champ;

typedef struct			s_vm
{
	int					nbr_cycles;
	int					winner;
	t_champ				*champ;
	unsigned char		*arene;
}						t_vm;

void					ft_vm_error(char *error);
long					check_live(t_vm *env);
int						put_name(int *cur, char **av);
void					make_arene(t_vm *env);
void					make_player(t_vm *env, int nbr);
void					rang(t_vm *env, t_champ *champ);
void					set_carry(t_champ *champ, t_champ *ref);
void					give_live(t_champ *champ, int id);
void					exec(t_vm *env, t_champ *champ);
void					exec2(t_vm *env, t_champ *champ, unsigned char \
						commande);
void					exec3(t_vm *env, t_champ *champ, unsigned char \
						commande);
void					exec4(t_vm *env, t_champ *champ, unsigned char \
						commande);
void					exec5(t_vm *env, t_champ *champ, unsigned char \
						commande);
void					exec6(t_vm *env, t_champ *champ, unsigned char \
						commande);
short					get_short(unsigned char *read);
int						get_int(unsigned char *read);
int						oct_codage(char target, char place, unsigned char \
						value);
void					live(unsigned char *arene, t_champ *champ, t_vm *env);
void					ld(t_vm *env, unsigned char *arene, t_champ *champ);
void					st(t_vm *env, unsigned char *arene, t_champ *champ);
void					add(t_vm *env, unsigned char *arene, t_champ *champ);
void					sub(t_vm *env, unsigned char *arene, t_champ *champ);
void					and(unsigned char *arene, t_champ *champ);
void					or(unsigned char *arene, t_champ *champ);
void					xor(unsigned char *arene, t_champ *champ);
void					zjump(t_vm *env, unsigned char *arene, t_champ *champ);
void					ldi(unsigned char *arene, t_champ *champ);
void					sti(unsigned char *arene, t_champ *champ);
void					ft_fork(unsigned char *arene, t_champ *champ, \
						t_vm *env);
void					lld(t_vm *env, unsigned char *arene, t_champ *champ);
void					lldi(unsigned char *arene, t_champ *champ);
void					ft_lfork(unsigned char *arene, t_champ *champ, \
						t_vm *env);
void					aff(unsigned char *arene, t_champ *champ);

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
void		*ft_memdup(const void *restrict src, size_t n);
void		*ft_memset(void *b, int c, size_t len);
int			get_next_line(int const fd, char **line);
char		**ft_malloc_tabtab(char **tab, char *str);

#endif
