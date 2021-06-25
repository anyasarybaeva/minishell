# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbones <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/25 23:06:09 by lbones            #+#    #+#              #
#    Updated: 2020/11/26 01:18:40 by lbones           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c\
        ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c\
        ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c\
        ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
        ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c\
        ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_split.c\
        ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRC_OBJECTS = $(patsubst %.c,%.o,$(SRC))
HEADERS = libft.h
FLAGS = -Wall -Wextra -Werror
all: $(NAME)
$(NAME): $(SRC_OBJECTS)
	ar rc $(NAME) $(SRC_OBJECTS)
%.o: %.c $(HEADERS)
	gcc $(FLAGS) -c $< -o $@
clean:
	rm -rf $(SRC_OBJECTS)
fclean: clean
	rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re
