NAME_CHECKER	= checker
NAME_PS	= push_swap

# compiler

CC		= gcc
CFLAGS	= -Wall -Wextra -g

# colors

RED		:= "\033[31m"
WAVE	:= "\033[36m"
EOC		:= "\033[0m"
BLINK	:= "\033[5m"
GREEN	:= "\033[32m"

# srcs and obj

SRC_CHECKER		= main_checker.c lst_work.c commands.c
SRC_PUSH		= main_push_swap.c lst_work.c commands.c ps_helper.c

OBJ_CHECKER		= $(addprefix $(OBJDIR),$(SRC_CHECKER:.c=.o))
OBJ_PUSH		= $(addprefix $(OBJDIR),$(SRC_PUSH:.c=.o))


# directories
INCDIR			= ./includes/

SRC_DIR			= ./srcs/

OBJDIR			= ./obj/

# ft library
FT				= ./libft/
FT_LIB			= $(addprefix $(FT),libft.a)
FT_INC			= -I ./libft/includes
FT_LNK			= -L ./libft -l ft


all: obj $(FT_LIB) $(NAME_CHECKER) $(NAME_PS)

obj:
	@echo " - Creating dir $(OBJDIR)"
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRC_DIR)%.c
	@echo $(WAVE) " - Compiling $<  ->  $@" $(EOC)
	@$(CC) -g $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	@make -C $(FT)

$(NAME_CHECKER): $(OBJ_CHECKER)
	@echo $(GREEN) " - Compiling $@" $(EOC)
	@$(CC) $(OBJ_CHECKER) $(FT_LNK) -o $(NAME_CHECKER)

$(NAME_PS): $(OBJ_PUSH)
	@echo $(GREEN) " - Compiling $@" $(EOC)
	@$(CC) $(OBJ_PUSH) $(FT_LNK) -o $(NAME_PS)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME_CHECKER)
	rm -rf $(NAME_PS)
	make -C $(FT) fclean

re: fclean all