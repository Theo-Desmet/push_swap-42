# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/28 07:33:29 by tdesmet           #+#    #+#              #
#    Updated: 2022/02/11 14:07:24 by tdesmet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_strlen.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_strlcat.c\
	ft_memmove.c\
	ft_strlcpy.c\
	ft_toupper.c\
	ft_strjoin.c\
	ft_memcmp.c\
	ft_tolower.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strncmp.c\
	ft_memchr.c\
	ft_strnstr.c\
	ft_atoi.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_putnbr.c\
	ft_putchar.c\
	ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.c\
	ft_lstlast.c\
	ft_lstadd_back.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_putstr.c\

CFLAGS = -Wall -Werror -Wextra -g

CC = gcc

RM = rm -f

LIB = ar rc ${NAME}

OBJ = ${SRC:.c=.o}

%.o: %.c libft.h
	@${CC} -o $@ -c $<  $(CFLAGS)

all: ${NAME}

${NAME}: begin ${OBJ}
	@$(LIB) $(OBJ)
	@echo "\033[106;32mcompilation de libft terminer\033[0m"

clean:
	@${RM} ${OBJ}
	@echo "\033[101;30msuppression des fichier *.o de la libft\033[0m"

fclean: clean
	@${RM} ${NAME}
	@echo "\033[101;30msuppression de la librairie libft\033[0m"

re: fclean all

begin:
	@echo "\033[106;35mdebut de la compilation de libft\033[0m"

.PHONY: all clean fclean re
