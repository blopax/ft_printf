/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_clean_flag_rework.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 18:20:27 by nvergnac          #+#    #+#             */
/*   Updated: 2017/12/29 15:36:35 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_add_char(t_lst *first, char c)
{
	char *tmp;
	int i;

	i = 0;
	//write(1,"ADD\n",4);
	//ft_putstr(first->init_str);
	//write(1,"\n",1);
	//ft_putnbr((int)ft_strlen(first->init_str));
	//write(1,"\n",1);
	if (!(tmp = ft_strnew((int)ft_strlen(first->init_str) + 1)))
		exit (0);
	tmp[0] = c;
	while (first->init_str[i])
	{
		tmp[i + 1] = first->init_str[i];
		i++;
	}
	free(first->init_str);
	if (!(first->init_str = ft_strdup(tmp)))
		exit (0);
	free(tmp);
	//write(1,"ADD\n",4);
	//ft_putstr(first->init_str);
	//write(1,"\n",1);
	return (1);
}

void	ft_fill_char(t_lst *first, char c, int neg)
{
	char *tmp;
	char *str;
	int i;
	int k;

	i = 0;
	k = 0;
	if (!(tmp = ft_strnew(ft_atoi(first->size))))
		exit (0);
	if (!(str = ft_strdup(first->init_str)))
		exit (0);
	//ft_putstr(str);
	//write(1,"\n",1);
	//ft_putnbr(ft_atoi(first->size));
	//write(1,"\n",1);
	//ft_putnbr((int)ft_strlen(str));
	//write(1,"\n",1);
	while (i < (ft_atoi(first->size) - (int)ft_strlen(str) - neg))
	{
		//write(1,"a\n",2);
		tmp[i++] = c;
	}
	//write(1,"2\n",2);
	while (i < ft_atoi(first->size))
		tmp[i++] = str[k++];
	free(first->init_str);
	//ft_putstr(tmp);
	//write(1,"\n",1);
	if (!(first->init_str = ft_strdup(tmp)))
		exit (0);
	free(tmp);
	free(str);
	//ft_putstr(first->init_str);
	//write(1,"\n",1);
}

char	*ft_create_fill_str(t_lst *first, char c)
{
	int		size_to_fill;
	char	*fill_str;
	int		i;

	i = 0;
	if (first->type != 'c')
		size_to_fill = ft_atoi(first->size) - (int)ft_strlen(first->init_str);
	else
		size_to_fill = ft_atoi(first->size) - first->read_bytes;
	if (!(fill_str = ft_strnew(size_to_fill)))
		exit (0);
	while (i < size_to_fill)
	{
		fill_str[i] = c;
		i++;
	}
	return (fill_str);
}

void	ft_left_justif(t_lst *first)
{
	char *str;
	int i;

	i = 0;
	if (!(str = ft_strnew(ft_atoi(first->size - first->read_bytes))))
		exit (0);
	while (first->init_str[i])
	{
		str[i] = first->init_str[i];
		i++;
	}
	while (i < ft_atoi(first->size) - first->read_bytes)
		str[i++] = ' ';
	free(first->init_str);
	if (!(first->init_str = ft_strdup(str)))
		exit (0);
	free(str);
}

/*int		ft_adjust_size(t_lst *first)
{
	int size;
	
	size = 0;
	if (first->size)
		size = ft_atoi(first->size);
	else
		return (0);
	free(first->size);
	first->size = ft_itoa(size - 1);
	return (0);
}*/

void	ft_clean_flag_c(t_lst *first)
{
	int i;
	int size;
	
	size = first->read_bytes;
	i = 0;
	while (first->flags[i])
	{
		if (first->flags[i] == '0' && !first->acc && (ft_atoi(first->size) > size))
			first->init_str = ft_str_pos_ins(first->init_str, 0, ft_create_fill_str(first, '0'));
		if (first->flags[i] == '-' && (ft_atoi(first->size) > size))
			ft_left_justif(first);
		i++;
	}
	if (ft_atoi(first->size) > size && !first->flags)
		first->init_str = ft_str_pos_ins(first->init_str, 0, ft_create_fill_str(first, ' '));
}

void	ft_clean_flag_su(t_lst *first)
{
	int i;

	i = 0;
	while (first->flags[i])
	{
		if (first->flags[i] == '0' && !first->acc && (ft_atoi(first->size) > (int)ft_strlen(first->init_str)))
			first->init_str = ft_str_pos_ins(first->init_str, 0, ft_create_fill_str(first, '0'));
		if (first->flags[i] == '-' && (ft_atoi(first->size) > (int)ft_strlen(first->init_str)))
			ft_left_justif(first);
		i++;
	}
}

void	ft_clean_flag_d(t_lst *first)
{
	int i;
	int neg;

	neg = 0;
	i = 0;
	if (first->init_str[0] ==  '-')
		neg = 1;
		while (first->flags[i])
	{
		if (first->flags[i] == ' ' && neg == 0)
			neg = neg + ft_add_char(first, ' ');
		if (first->flags[i] == '+' && neg == 0)
			neg = neg + ft_add_char(first, '+');
		if (first->flags[i] == '0' && !first->acc && (ft_atoi(first->size) > ((int)ft_strlen(first->init_str))))
	{
			first->init_str = ft_str_pos_ins(first->init_str, neg, ft_create_fill_str(first, '0'));
	}
		if (first->flags[i] == '-' && (ft_atoi(first->size) > (int)ft_strlen(first->init_str)))
			ft_left_justif(first);
		i++;
	}
}

void	ft_clean_flag_o(t_lst *first)
{
	int i;
	int neg;

	neg = 0;
	i = 0;
	while (first->flags[i])
	{
		if (first->flags[i] == '#')
			neg = neg + ft_add_char(first, '0');
		if (first->flags[i] == '0' && !first->acc && (ft_atoi(first->size) > (int)ft_strlen(first->init_str)))
			first->init_str = ft_str_pos_ins(first->init_str, neg, ft_create_fill_str(first, '0'));
		if (first->flags[i] == '-' && (ft_atoi(first->size)  > (int)ft_strlen(first->init_str)))
			ft_left_justif(first);
		i++;
	}
}

void	ft_clean_flag_x(t_lst *first)
{
	int i;
	int neg;

	neg = 0;
	i = 0;
	while (first->flags[i])
	{
		if (first->flags[i] == '#')
		{
			if (first->type == 'X')
				neg = neg + ft_add_char(first, 'X');
			else	
				neg = neg + ft_add_char(first, 'x');
			neg = neg + ft_add_char(first, '0');
		}
		if (first->flags[i] == '0' && !first->acc && (ft_atoi(first->size) > (int)ft_strlen(first->init_str)))
			first->init_str = ft_str_pos_ins(first->init_str, neg, ft_create_fill_str(first, '0'));
		if (first->flags[i] == '-' && (ft_atoi(first->size)  > (int)ft_strlen(first->init_str)))
			ft_left_justif(first);
		i++;
	}
}

char	*ft_fill_flag(char a, char *flag)
{
	int i;

	i = 0;
	while (flag[i] != 0)
		i++;
	if (a == ' ' && flag[i - 1] == '+')
		return (flag);
	if (a == '-' && flag [i - 1] == '0')
	{
		flag[i - 1] = '-';
		return (flag);
	}
	flag[i] = a;
	return (flag);
}

void	ft_clean_flag(t_lst *first)
{
	const char *ref;
	char *flag;
	int i;

	flag = ft_strnew(6);
	ref = "#+ 0-'";
	while (*ref != 0)
	{
		i = 0;
		while (first->flags[i])
		{
			if (first->flags[i] == *ref)
			{
				flag = ft_fill_flag(*ref, flag);
				break ;
			}
			i++;
		}
		ref++;
	}
	free(first->flags);
	first->flags = ft_strdup(flag);
	free(flag);
}

void	ft_get_clean_flag(t_lst *first)
{
	while (first)
	{
		if (first->flags)
		{
			ft_clean_flag(first);
			if (first->type == 's' || first->type == 'u' || first->type == 'c')
				ft_clean_flag_su(first);
			if (first->type == 'c')
				ft_clean_flag_c(first);
			if (first->type == 'd')
				ft_clean_flag_d(first);
			if (first->type == 'o')
				ft_clean_flag_o(first);
			if (first->type == 'x' || first->type == 'X')
				ft_clean_flag_x(first);
		}
		if (first->type != 'c' && ft_atoi(first->size) > (int)ft_strlen(first->init_str))
			first->init_str = ft_str_pos_ins(first->init_str, 0, ft_create_fill_str(first, ' '));
		first = first->next;
	}
}
