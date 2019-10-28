# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vico <vico@student.le-101.fr>              +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/15 17:31:08 by volivry      #+#   ##    ##    #+#        #
#    Updated: 2019/10/28 14:07:11 by vico        ###    #+. /#+    ###.fr      #
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

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CCFLAGS) -I. -o $@ -c $<

$(NAME): $(OBJECTS)
	@echo "Generating $(NAME)"
	$(CC) $(CCFLAGS) $(OBJECTS) -I ./includes -shared -o $(NAME)
	@(echo "Malloc libft done\033[0m";)
	@ln -sf $(NAME) $(SYMLINK)

build:
	@mkdir -p $(OBJDIR)

clean:
	@echo "CLEANING OBJECTS"
	@rm -f $(OBJECTS)

fclean: clean
	@echo "CLEANING ALL"
	@rm -f $(NAME) $(SYMLINK)

re: fclean all
