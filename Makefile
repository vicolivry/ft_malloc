# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/15 17:31:08 by volivry      #+#   ##    ##    #+#        #
#    Updated: 2018/06/07 14:08:37 by volivry     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc
CCFLAGS = -Wall -Wextra -Werror
NAME = ft_select
SRCDIR = srcs
OBJDIR = objs
INCDIR = includes libft

SRC =  main.c lst_utils.c lst_utils2.c utils.c term.c get_info.c display.c \
	   print_arg.c key_func.c arrows.c signals.c

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJECTS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INCS = $(addprefix -I , $(INCDIR))

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CCFLAGS) -I. -o $@ -c $<

$(NAME): build $(OBJECTS)
	@make -C libft
	@$(CC) -L libft -lft -o $(NAME) -ltermcap $(OBJECTS)
	@(echo "\033[2K\033[2F")
	@(echo "\n\033[32m MiniShell compiled\033[0m";)

build:
	@mkdir -p $(OBJDIR)

clean:
	@echo "CLEANING OBJECTS"
	@make clean -C ./libft/
	@rm -f $(OBJECTS)

fclean: clean
	@echo "CLEANING ALL"
	@make fclean -C ./libft/
	@rm -f $(NAME)

re: fclean all
