# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pclement <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/20 14:56:41 by pclement          #+#    #+#              #
#    Updated: 2017/12/20 18:45:06 by pclement         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
NAME1 = printf_tests
NAME2 = ft_accuracy_treatment

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_PATH = .
SRC_NAME = ft_accuracy_treatment.c ft_str_pos_ins.c ft_conv_if.c\
		   ft_conv_if_utilities.c ft_format_split_utilities.c\
		   ft_debug_show.c\
		   ft_format_split.c ft_lst_utilities.c\
		   ft_printf.c ft_varg.c ft_printf_itoa_base.c ft_conv_treatment.c\

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = .
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CPPFLAGS = -I.
#*. peut etre remplace par include ou le nom du dossier ou se trouvent les #include *

all: $(NAME) $(NAME1) $(NAME2) clean

$(NAME): $(OBJ)
	$(CC) $^ main.c libft/libft.a -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir (OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME1): $(OBJ)
	$(CC) $^ main_printf.c libft/libft.a -o $@

$(NAME2): $(OBJ)
	$(CC) $^ main_ft_acc_treatment.c libft/libft.a -o $@



# 1e ligne cree une regle par fichier .o et chaque fichier va tester le .c correspondant
# 2e ligne cree dossier correspondant pour lettre les .o le 2> /dev/null est la pour eviter les messages du type le dossier existe deja et  true pour que makefile continue meme si dossier existe deja 

#	si on veut rajouter une commande librairie ms pas ac obj mais dossier lib
#	ar rc libft.a $(dossier lib)
#	ranlib libft.a



clean:
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	
fclean: clean
	rm -f $(NAME) $(NAME1) $(NAME2) $(NAME3)

re: fclean all
