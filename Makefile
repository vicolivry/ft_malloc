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

ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

CC = gcc
CCFLAGS = -Wall -Wextra -Werror
NAME = libft_malloc_$(HOSTTYPE).so
SRCDIR = srcs
OBJDIR = objs
INCDIR = includes libft
# SYMLINK = libft_malloc.so

SRC =  main.c ft_malloc.c
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJECTS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INCS = $(addprefix -I , $(INCDIR))



all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CCFLAGS) -I. -o $@ -c $<

$(NAME): build $(OBJECTS)
	@make -C libft
	@$(CC) -L libft -lft -o $(NAME) $(OBJECTS)
	@(echo "\033[2K\033[2F")
	@(echo "\n\033[32m Malloc libft done\033[0m";)

	@(echo "Creating symlink $(SYMLINK) => $(NAME)")
	@ln -s libft_malloc.so/$(NAME)

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
