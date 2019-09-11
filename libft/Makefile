#***************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: volivry <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 09:59:28 by volivry           #+#    #+#              #
#    Updated: 2018/05/22 12:19:56 by volivry     ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #
.PHONY: all clean fclean re

CC = gcc $(FLAGS)
FLAGS = -Wall -Wextra
NAME = libft.a
SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
	  ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c\
	  ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c\
	  ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c\
	  ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
	  ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c\
	  ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c\
	  ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c\
	  ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c\
	  ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c\
	  ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c\
	  ft_isupper.c ft_islower.c ft_iswhite.c ft_strrev.c ft_wordcount.c\
	  ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c\
	  ft_putwchar_fd.c ft_putwchar.c ft_itoa_base.c ft_power.c \
	  ft_atoi_base.c ft_nb_len.c ft_uitoa_base.c ft_atoui_base.c \
	  ft_atol_base.c wchar_len.c wstrlen.c ft_printf.c sized.c type_c.c \
	  type_di.c type_oub.c type_p.c type_ws.c type_s.c type_x.c ft_modify.c \
	  lenfinder.c ft_parse.c ft_format.c get_next_line.c str_append.c \
	  lst_dup.c tab_to_lst.c lst_to_tab.c to_upper_str.c free_lst.c \
	  ft_strsub_fr.c word_length.c get_line.c

OBJECTS = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) -I. -o $@ -c $<

$(NAME): $(OBJECTS)
	@echo "Generating libft.a"
	@ar rcs $(NAME) $(OBJECTS)

clean:
	@echo "Cleaning libft.a"
	@rm -f $(OBJECTS)

fclean: clean
	@echo "Super cleaning libft.a"
	@rm -f $(NAME)

re: fclean all
