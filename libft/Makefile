# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_libftprintf.a                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pclement <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/20 16:13:50 by pclement          #+#    #+#              #
#    Updated: 2017/12/21 17:13:03 by nvergnac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf
FLAGS = -Wall -Wextra -Werror -c
SRC = ft_strcat.c ft_strchr.c ft_strcpy.c ft_strncpy.c ft_strdup.c ft_strlen.c\
	  ft_strncat.c ft_strlcat.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
	  ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c\
	  ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memset.c\
	  ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c\
	  ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c\
	  ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c\
	  ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c\
	  ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c\
	  ft_putnbr_intmax.c\
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c\
	  ft_lstadd.c ft_lstdelone.c ft_lstdel.c ft_lstiter.c ft_lstmap.c \
	  ft_count_if.c\
	  ../ft_accuracy_treatment.c ../ft_str_pos_ins.c ../ft_conv_if.c\
	  ../ft_conv_if_utilities.c ../ft_format_split_utilities.c\
	  ../ft_debug_show.c\
	  ../ft_format_split.c ../ft_lst_utilities.c\
	  ../ft_printf.c ../ft_varg.c ../ft_printf_itoa_base.c ../ft_conv_treatment.c\
	  ../ft_get_clean_flag_mofo.c ../ft_display.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC) $(OBJ)
	ar rc $(NAME).a $(OBJ)
	ranlib $(NAME).a

$(%.o):
	gcc $(FLAGS) %.c

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
