/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:09:23 by pclement          #+#    #+#             */
/*   Updated: 2017/12/08 19:23:48 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

#define FT_PRINTF_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/includes/libft.h"

typedef struct	s_info
{
	char			*flags;
	char			*size;
	char			*accuracy;
	char			*modifier;
	char			type;
}					t_info;

typedef struct	s_lst
{
	char			*init_str;
	char			*final_str;
	char			*flags;
	char			*size;
	char			*accuracy;
	char			*modifier;
	char			type;
	struct s_list	*next;
}					t_lst;

t_lst	*ft_format_split(char *format);
t_lst	ft_struct_init();
t_lst	*ft_struct_fill(char *str);
t_lst	*ft_lst_pushback();

#endif
