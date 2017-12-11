/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:09:23 by pclement          #+#    #+#             */
/*   Updated: 2017/12/11 14:02:35 by pclement         ###   ########.fr       */
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
	struct s_lst	*next;
}					t_lst;

t_lst	*ft_format_split(char *format);
t_lst	ft_struct_init();
t_lst	*ft_struct_fill(char *str);
t_lst	*ft_lst_pushback();
int		ft_is_conv(char *format, int start, int flag, t_info *info_struct);
void	ft_lst_show(t_lst *first, int n);
void	ft_info_show(t_info info_struct);
void	ft_empty_struct(t_info *info_struct_ptr);
t_lst	*ft_lst_init(void);
t_info	ft_info_init(void);
int		ft_add_spec_lst(t_lst *first, t_info *info_struct_ptr);
void	ft_add_str_lst(char *format, int i, int start, t_lst *first);

#endif
