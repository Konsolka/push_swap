NAME_CHECKER	= checker
NAME_PUSH_SWAP	= push_swap

# compiler

CC		= gcc
CFLAGS	= -Wall -Wextra -g

SRC_CHECKER		= main.c lst_work.c commands.c

OBJ_CHECKER		= $(addprefix $(OBJDIR_CHECKER),$(SRC_CHECKER:.c=.o))

# directories
OBJDIR			= ./obj/
SRCDIR_CHECKER	= ./srcs/checker/
INCDIR	= ./includes/
OBJDIR_CHECKER	= ./obj/checker/

# ft library
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft/includes
FT_LNK	= -L ./libft -l ft

EXEC = main

all: obj $(FT_LIB) $(NAME_CHECKER)

obj:
	mkdir -p $(OBJDIR_CHECKER)

$(OBJDIR_CHECKER)%.o:$(SRCDIR_CHECKER)%.c
	$(CC) -g $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	make -C $(FT)

$(NAME_CHECKER): $(OBJ_CHECKER)
	$(CC) $(OBJ_CHECKER) $(FT_LNK) -o $(NAME_CHECKER)

clean:
	rm -rf $(OBJDIR) $(NAME_CHECKER)

fclean: clean
	rm -rf $(NAME_CHECKER)
	make -C $(FT) fclean

re: fclean all