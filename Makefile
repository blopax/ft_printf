# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_libftprintf.a                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pclement <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/20 16:13:50 by pclement          #+#    #+#              #
#    Updated: 2018/01/03 16:11:45 by pclement         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror -c
SRC = ft_accuracy_treatment.c ft_str_pos_ins.c ft_conv_if.c\
	  ft_conv_if_utilities.c ft_format_split_utilities.c\
	  ft_debug_show.c ft_safe_free.c\
	  ft_format_split.c ft_lst_utilities.c\
	  ft_printf.c ft_varg_1.c ft_varg_2.c ft_printf_itoa_base.c ft_conv_treatment_1.c ft_conv_treatment_2.c\
	  ft_get_clean_flag_0.c ft_get_clean_flag_1.c ft_get_clean_flag_2.c ft_get_clean_flag_3.c ft_display.c\

OBJ = $(SRC:.c=.o)

L_SRC = ft_strcat.c ft_strchr.c ft_strcpy.c ft_strncpy.c ft_strdup.c ft_strlen.c\
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
	  ft_count_if.c ft_wstrlen.c ft_wstrnew.c\

all: $(NAME)

$(NAME): $(SRC) $(OBJ) libft/$(L_SRC)
	make -C libft/
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(%.o):
	gcc $(FLAGS) -I libft/includes/ -L libft/ -lft  %.c

clean:
	make -C libft/ clean
	rm -f $(OBJ) 

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY : clean all re run fclean

