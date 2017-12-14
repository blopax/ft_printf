/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:09:23 by pclement          #+#    #+#             */
/*   Updated: 2017/12/13 19:28:48 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

#define FT_PRINTF_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/includes/libft.h"

typedef struct	s_flag
{
	char			*tmp;
	char			*flag_str;
	int				j;
	int				k;
	int				switch_flag;
}					t_flag;

typedef struct	s_info
{
	char			*flags;
	char			*size;
	char			*acc;
	char			*mdf;
	char			type;
}					t_info;

typedef struct	s_lst
{
	char			*init_str;
	char			*final_str;
	char			*flags;
	char			*size;
	char			*acc;
	char			*mdf;
	char			type;
	char			*v_type;
	void			*value_ptr;
	intmax_t		value_signed;
	uintmax_t		value_unsigned;
	struct s_lst	*next;
}					t_lst;

typedef struct	s_split
{
	t_lst	*first;
	t_info	info_struct;
	int		i;
	int		spec_size;
	int		start;
	int		spec_flag;
}				t_split;

struct			s_va_type
{
	char*	v_type;
	void	(*ft_va_ptr)(va_list vl);
};
/*
struct s_va_type	va_type_tab[] =
{
	{"int", &va_int},
	{"short int", &va_sh_int},
	{"signed char", &va_char},
	{"long", &va_long},
	{"long long", &va_longlong},
	{"intmax_t", &va_intmax},
	{"size_t", &va_size_t},
	{"unsigned short int", &va_u_sh_int},
	{"unsigned char", &va_u_char},
	{"unsigned long", &va_u_long},
	{"unsigned long long", &va_u_longlong},
	{"unsigned intmax_t", &va_u_intmax},
	{ 0 , 0}
};
*/
//fonction separee pour modifier, D en ld, U en lu O en lo C en lc et S en ls




//ft_format_split et fonctions dependantes : transforme format en une liste exploitable
int		ft_printf(const char * restrict format, ...);
t_lst	*ft_format_split(char *format);
t_lst	ft_struct_init();
t_lst	*ft_struct_fill(char *str);
t_lst	*ft_lst_pushback();
int		ft_conv(char *format, int start, int flag, t_info *info_struct);
void	ft_empty_struct(t_info *info_struct_ptr);
void	ft_empty_lst(t_lst *first);
t_lst	*ft_lst_init(void);
t_info	ft_info_init(void);
int		ft_add_spec_lst(t_lst *first, t_info *info_struct_ptr);
void	ft_add_str_lst(char *format, int i, int start, t_lst *first);

// Fonctions utiles pour afficher les listes
void	ft_lst_show(t_lst *first, int n);
void	ft_info_show(t_info info_struct);

// Fonctions utiles pour va_arg
char	*ft_v_type(char type, char *mdf);
void	ft_v_type_clean(t_lst *first);
void	*va_arg_void(va_list ap, char *v_type);
intmax_t	va_arg_intmax(va_list ap, char *v_type);
uintmax_t	va_arg_uintmax(va_list ap, char *v_type);
#endif
