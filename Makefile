# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vico <vico@student.le-101.fr>              +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/15 17:31:08 by volivry      #+#   ##    ##    #+#        #
#    Updated: 2019/10/29 10:03:26 by vico        ###    #+. /#+    ###.fr      #
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
SYMLINK = libft_malloc.so

SRC =  ft_malloc.c show_alloc_mem.c malloc_tiny.c malloc_small.c mini_libft.c\
		free.c free_tiny.c free_small.c ft_realloc.c realloc_tiny.c \
		realloc_small.c display.c utils_small.c utils_large.c utils_tiny.c
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJECTS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | objs
	@$(CC) $(CCFLAGS) -I. -o $@ -c $<

$(NAME): $(OBJECTS)
	@$(CC) $(CCFLAGS) $(OBJECTS) -I ./includes -shared -o $(NAME)
	@(echo "$(NAME) done\033[0m";)
	@ln -sf $(NAME) $(SYMLINK)

objs:
	@mkdir -p $(OBJDIR)

clean:
	@echo "CLEANING OBJECTS"
	@rm -f $(OBJECTS)
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "CLEANING ALL"
	@rm -f $(NAME) $(SYMLINK)

re: fclean all
