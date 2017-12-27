/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_clean_flag_mofo.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:21:44 by nvergnac          #+#    #+#             */
/*   Updated: 2017/12/27 17:50:26 by nvergnac         ###   ########.fr       */
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

char	*ft_create_fill_str(t_lst *first, char c)
{
	int		size_to_fill;
	char	*fill_str;
	int		i;

	i = 0;
	size_to_fill = ft_atoi(first->size) - ft_strlen(first->init_str);
	if (!(fill_str = ft_strnew(size_to_fill)))
		exit (0);
	while (fill_str[i] != 0)
	{
		fill_str[i] = c;
		i++;
	}
	return (fill_str);
}

void	ft_left_justif(t_lst *first, int real_size)
{
	char *str;
	int i;

	i = 0;
	if (!(str = ft_strnew(ft_atoi(first->size) + real_size)))
		exit (0);
	while (first->init_str[i])
	{
		str[i] = first->init_str[i];
		i++;
	}
	while (i < ft_atoi(first->size) + real_size)
		str[i++] = ' ';
	free(first->init_str);
	if (!(first->init_str = ft_strdup(str)))
		exit (0);
	free(str);
}

void	ft_clean_flag_suc(t_lst *first, int real_size)
{
	int i;

	i = 0;
	while (first->flags[i])
	{
		if (first->flags[i] == '0' && first->acc == 0 && (ft_atoi(first->size) > (int)ft_strlen(first->init_str)))
			ft_fill_char(first, '0', 0, 0);
		if (first->flags[i] == '-' && (ft_atoi(first->size) + real_size > (int)ft_strlen(first->init_str)))
			ft_left_justif(first, real_size);
		i++;
	}
}

int		ft_remove_neg_sign(t_lst *first)
{
	char	*tmp;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!(tmp = ft_strnew((int)ft_strlen(first->init_str) - 1)))
		exit (0);
	while (first->init_str[i])
	{
		if (first->init_str[i] == '-')
			i++;
		else
		{
			tmp[k] = first->init_str[i];
			//write(1,&tmp[k],1);
			i++;
			k++;
		}
	}
	free(first->init_str);
	if (!(first->init_str = ft_strdup(tmp)))
		exit (0);
	free(tmp);
	return (1);
}

void	ft_clean_flag_d(t_lst *first, int real_size)
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
			ft_left_justif(first, real_size);
		i++;
	}
}

void	ft_clean_flag_o(t_lst *first, int real_size)
{
	int i;

	i = 0;
	while (first->flags[i])
	{
		if (first->flags[i] == '0' && first->acc == 0 && (ft_atoi(first->size) > (int)ft_strlen(first->init_str)))
			ft_fill_char(first, '0', 0, 0);
		if (first->flags[i] == '#')
			ft_add_char(first, '0');
		if (first->flags[i] == '-' && (ft_atoi(first->size) + real_size > (int)ft_strlen(first->init_str)))
			ft_left_justif(first, real_size);
		i++;
	}
}

void	ft_clean_flag_x(t_lst *first, int real_size)
{
	int i;

	i = 0;
	while (first->flags[i])
	{
		if (first->flags[i] == '0' && first->acc == 0 && (ft_atoi(first->size) > (int)ft_strlen(first->init_str)))
			ft_fill_char(first, '0', 0, 0);
		if (first->flags[i] == '#')
		{
			if (first->type == 'X')
				ft_add_char(first, 'X');
			else	
				ft_add_char(first, 'x');
			ft_add_char(first, '0');
		}
		if (first->flags[i] == '-' && (ft_atoi(first->size) + real_size > (int)ft_strlen(first->init_str)))
			ft_left_justif(first, real_size);
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
	int real_size;

	while (first)
	{
		real_size = 0;
		//write(1,"ALLO\n",5);
		if (first->flags)
		{
			//write(1,"INIT\n",5);
			//ft_putstr(first->init_str);
			//write(1,"\n",1);
			//write(1,"TEST\n",5);
			ft_clean_flag(first);
//			real_size = ft_adjust_size(first);
			//write(1,"TEST\n",5);
			//write(1,"FLAG\n",5);
			//ft_putstr(first->flags);
			//write(1,"\n",1);
			//write(1,"SIZE\n",5);
			//ft_putstr(first->size);
			//write(1,"\n",1);
			if (first->type == 's' || first->type == 'u' || first->type == 'c')
				ft_clean_flag_suc(first, real_size);
			if (first->type == 'd')
			{
				//write(1,"1234\n",5);
				ft_clean_flag_d(first,real_size);
				//write(1,"1234\n",5);
			}
			if (first->type == 'o')
			{
				//write(1,"1234\n",5);
				ft_clean_flag_o(first, real_size);
				//write(1,"1234\n",5);
			}
			if (first->type == 'x' || first->type == 'X')
				ft_clean_flag_x(first, real_size);
		}
		//write(1,"AAAA\n",5);
		//ft_putstr(first->init_str);
		//write(1,"\n",1);
		//ft_putnbr(real_size + ft_atoi(first->size));
		//write(1,"\n",1);
		//ft_putnbr((int)ft_strlen(first->init_str));
		//write(1,"\n",1);
		//write(1,"AAAA\n",5);
		if (ft_atoi(first->size) > (int)ft_strlen(first->init_str))
		{
			first->init_str = ft_str_pos_ins(first->init_str, 0, ft_create_fill_str(first, ' '));
		}
		first = first->next;
	}
}
