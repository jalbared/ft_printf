#------------------------------------------------------------------------------#
# VARIABLES                                                                    #
#------------------------------------------------------------------------------#

NAME = libftprintf.a

SRC = ft_printf.c ft_putprintf.c
OBJ = $(SRC:.c=.o)
DEP = $(OBJ:.o=.d)

CFLAGS = -Wall -Wextra -Werror -MMD -I.
HEADER = ft_printf.h
MAKEFILE = Makefile
COMPILE = cc
LINK = ar -crs
RM = rm -f

LIB = libft/libft.a
LIB_DIR = $(dir $(LIB))

GREEN = \033[0;32m
COLOUR_END = \033[0m

#------------------------------------------------------------------------------#
# PROCEDURES                                                                   #
#------------------------------------------------------------------------------#

all: libcheck $(NAME)

$(NAME): $(OBJ) $(LIB)
	cp $(LIB) $(NAME)
	$(LINK) $(NAME) $(OBJ)
	@echo "$(GREEN)Library $@ created.$(COLOUR_END)"

$(LIB):
	make -C $(LIB_DIR)

%.o : %.c
	$(COMPILE) ${CFLAGS} -c $< -o $@

clean:
	make -C $(LIB_DIR) clean
	$(RM) $(OBJ) $(DEP)

fclean: clean
	$(RM) $(NAME) $(LIB)

re: fclean all

libcheck:
	make -C $(LIB_DIR)

-include ${DEP}

.PHONY: all clean fclean re
