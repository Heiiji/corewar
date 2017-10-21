FLAG = -Wall -Wextra -Werror

NAME_VMA = 	corewar

SRCS_VMA  = SRCS_VMA/main.c				\

OBJ_VMA = $(SRCS_VMA:.c=.o)

NAME_ASM = 	asm

SRCS_ASM  = SRCS_ASM/main.c				\
			SRCS_ASM/error.c			\
			SRCS_ASM/open_file.c		\
			SRCS_ASM/print_file.c		\
			SRCS_ASM/check_file_s.c		\
			SRCS_GEN/put.c				\
			SRCS_GEN/strcmp.c			\
			SRCS_GEN/strlen.c			\
			SRCS_GEN/strdup.c			\
			SRCS_GEN/strchr.c			\
			SRCS_GEN/strsub.c			\
			SRCS_GEN/strdel.c			\
			SRCS_GEN/memdel.c			\
			SRCS_GEN/strjoin.c			\
			SRCS_GEN/memmove.c			\
			SRCS_GEN/get_next_line.c	\
			SRCS_GEN/malloc_tabtab.c 	\

OBJ_ASM = $(SRCS_ASM:.c=.o)

all: $(NAME_ASM) $(NAME_VMA)

$(NAME_ASM): $(OBJ_ASM)
	@gcc $(FLAG) -g3 -fsanitize=address -o $(NAME_ASM) $(OBJ_ASM)
	@ echo "🚧  \033[33mWORK IN PROGRESS\033[0m 🚧"
	@ echo "Compilation \033[36mASM\033[0m: [\033[32mcompleted\033[0m]"

$(NAME_VMA): $(OBJ_VMA)
	@gcc $(FLAG) -g3 -fsanitize=address -o $(NAME_VMA) $(OBJ_VMA)
	@ echo "🚧  \033[33mWORK IN PROGRESS\033[0m 🚧"
	@ echo "Compilation \033[36mVAM\033[0m: [\033[32mcompleted\033[0m]"

%.o: %.c
	@gcc $(FLAG_ASM) -c $< -o $@
	@gcc $(FLAG_VMA) -c $< -o $@

clean:
	@rm -f $(OBJ_ASM)
	@rm -f $(OBJ_VMA)

fclean: clean
	@rm -f $(NAME_ASM)
	@rm -f $(NAME_VMA)

re : fclean all

.PHONY: all, clean, fclean, re