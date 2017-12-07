/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:09:23 by pclement          #+#    #+#             */
/*   Updated: 2017/12/07 13:41:56 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

#define FT_PRINTF_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_list
{
	char			*init_str;
	char			*final_str;
	char			*flags;
	char			*size;
	char			*accuracy;
	char			*modifier;
	char			*type;
	struct s_list	*next;
}					t_list;;

t_list	*ft_format_split(char *format);
t_list	ft_struct_init();
t_list	*ft_struct_fill(char *str);
t_list	*ft_lst_pushback();

#endif
