# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pclement <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/20 14:56:41 by pclement          #+#    #+#              #
#    Updated: 2017/12/27 16:37:25 by nvergnac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME) clean

$(NAME):
	$(CC) $(CFLAGS) main.c libft/libftprintf.a -o $@

clean:
	echo "prout"
	
fclean: clean
	rm -f $(NAME)

re: fclean all
