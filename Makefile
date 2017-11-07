FLAG = -Wall -Wextra -Werror

NAME_VMA = 	corewar

SRCS_GEN =	SRCS_GEN/put.c				\
			SRCS_GEN/strcmp.c			\
			SRCS_GEN/strlen.c			\
			SRCS_GEN/strdup.c			\
			SRCS_GEN/strchr.c			\
			SRCS_GEN/strsub.c			\
			SRCS_GEN/strdel.c			\
			SRCS_GEN/memdel.c			\
			SRCS_GEN/strjoin.c			\
			SRCS_GEN/memmove.c			\
			SRCS_GEN/ft_memcpy.c		\
			SRCS_GEN/ft_memset.c		\
			SRCS_GEN/get_next_line.c	\
			SRCS_GEN/malloc_tabtab.c 	\
			SRCS_GEN/ft_atoi.c			\
			SRCS_GEN/ft_itoa.c			\

SRCS_VMA  = SRCS_VMA/main.c				\
			SRCS_VMA/champ_tool.c 		\
			SRCS_VMA/make.c 			\
			SRCS_VMA/exec.c 			\
			SRCS_VMA/fonc.c 			\
			SRCS_VMA/fonc2.c 			\
			$(SRCS_GEN)


OBJ_VMA = $(SRCS_VMA:.c=.o)

NAME_ASM = 	asm

SRCS_ASM  = SRCS_ASM/main.c				\
			SRCS_ASM/error.c			\
			SRCS_ASM/open_file.c		\
			SRCS_ASM/print_file.c		\
			SRCS_ASM/check_file_s.c		\
			$(SRCS_GEN)

OBJ_ASM = $(SRCS_ASM:.c=.o)

all: $(NAME_ASM) $(NAME_VMA)

WORK:
	@ echo "🚧  \033[33mWORK IN PROGRESS\033[0m 🚧"

$(NAME_ASM): WORK $(OBJ_ASM)
	@clang $(FLAG) -o $(NAME_ASM) $(OBJ_ASM)
	@ echo "Compilation \033[36mASM\033[0m: [\033[32mcompleted\033[0m]"

$(NAME_VMA): WORK $(OBJ_VMA)
	@clang $(FLAG) -o $(NAME_VMA) $(OBJ_VMA)
	@ echo "Compilation \033[36mVMA\033[0m: [\033[32mcompleted\033[0m]"

%.o: %.c
	@clang $(FLAG_ASM) -c $< -o $@
	@clang $(FLAG_VMA) -c $< -o $@

clean:
	@rm -f $(OBJ_ASM)
	@rm -f $(OBJ_VMA)

fclean: clean
	@rm -f $(NAME_ASM)
	@rm -f $(NAME_VMA)

re : fclean all

.PHONY: all, clean, fclean, re, WORK
