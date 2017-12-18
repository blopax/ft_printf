/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_clean_flag_mofo.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:21:44 by nvergnac          #+#    #+#             */
/*   Updated: 2017/12/18 20:10:46 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_add_char(t_lst *first, char c)
{
	char *tmp;
	int i;

	i = 1;
	if (!(tmp = ft_strnew(ft_strlen(first->init_str + 1))))
		exit (0);
	tmp[0] = c;
	while (first->init_str[i - 1])
		tmp[i] = first->init_str[i - 1];
	free(first->init_str);
	if (!(first->init_str = ft_strdup(tmp)))
		exit (0);
	free(tmp);
}

void	ft_fill_char(t_lst *first, char c)
{
	char *tmp;
	char *str;
	int i;
	int k;

	i = 0;
	k = 0;
	if (!(tmp = ft_strnew(ft_atoi(first->size))) && !(str = ft_strdup(first->init_str)))
		exit (0);
	while (i < (ft_atoi(first->size) - ft_strlen(str)))
		tmp[i++] = c;
	while (i < ft_atoi(first->size))
		tmp[i++] = str[k++];
	free(first->init_str);
	if (!(first->init_str = ft_strdup(tmp)))
		exit (0);
	free(tmp);
	free(str);
}

void	ft_left_justif(t_lst *first)
{
	char *str;
	int i;

	i = 0;
	if (!(str = ft_strnew(ft_atoi(first->size))))
		exit (0);
	while (first->init_str[i])
	{
		str[i] = first->init_str[i];
		i++;
	}
	while (i < ft_atoi(first->size))
		str[i++] = ' ';
	free(first->init_str);
	if (!(first->init_str = ft_strdup(str)))
		exit (0);
	free(str);
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
	ref = "#0-+ '";
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

void	ft_clean_flag_suc(t_lst *first)
{
	int i;

	i = 0;
	while (first->flags[i])
	{
		if (first->flags[i] == '0' && first->acc == 0 && (ft_atoi(first->size) > ft_strlen(first->init_str)))
			ft_fill_char(first, '0');
		if (ft_atoi(first->size) > ft_strlen(first->init_str))
			ft_fill_char(first, ' ');
		if (first->flags[i] == '-' && (ft_atoi(first->size) > ft_strlen(first->init_str)))
			ft_left_justif(first);
	}
}

void	ft_clean_flag_d(t_lst *first)
{
	int i;

	i = 0;
	while (first->flags[i])
	{
		if (first->flags[i] == '+')
			ft_add_char(first, '+');
		if (first->flags[i] == '0' && first->acc == 0 && (ft_atoi(first->size) > ft_strlen(first->init_str)))
			ft_fill_char(first, '0');
		if (ft_atoi(first->size) > ft_strlen(first->init_str))
			ft_fill_char(first, ' ');
		if (first->flags[i] == '-' && (ft_atoi(first->size) > ft_strlen(first->init_str)))
			ft_left_justif(first);
	}
}

void	ft_clean_flag_o(t_lst *first)
{
	int i;

	i = 0;
	while (first->flags[i])
	{
		if (first->flags[i] == '#')
			ft_add_char(first, '0');
		if (first->flags[i] == '0' && first->acc == 0 && (ft_atoi(first->size) > ft_strlen(first->init_str)))
			ft_fill_char(first, '0');
		if (ft_atoi(first->size) > ft_strlen(first->init_str))
			ft_fill_char(first, ' ');
		if (first->flags[i] == '-' && (ft_atoi(first->size) > ft_strlen(first->init_str)))
			ft_left_justif(first);
	}
}

void	ft_clean_flag_x(t_lst *first)
{
	int i;

	i = 0;
	while (first->flags[i])
	{
		if (first->flags[i] == '0' && first->acc == 0 && (ft_atoi(first->size) > ft_strlen(first->init_str)))
			ft_fill_char(first, '0');
		if (first->flags[i] == '#')
		{
			if (first->mdf[0] == 'X')
				ft_add_char(first, 'X');
			else	
				ft_add_char(first, 'x');
			ft_add_char(first, '0');
		}
		if (ft_atoi(first->size) > ft_strlen(first->init_str))
			ft_fill_char(first, ' ');
		if (first->flags[i] == '-' && (ft_atoi(first->size) > ft_strlen(first->init_str)))
			ft_left_justif(first);
	}
}

void	ft_get_clean_flag(t_lst *first)
{
	ft_clean_flag(first);
	if (first->mdf[0] == 's' || first->mdf[0] == 'u' || first->mdf[0] == 'c')
		ft_clean_flag_suc(first);
	if (first->mdf[0] == 'd')
		ft_clean_flag_d(first);
	if (first->mdf[0] == 'o')
		ft_clean_flag_o(first);
	if (first->mdf[0] == 'x' || first->mdf[0] == 'X')
		ft_clean_flag_x(first);
}
/*
char	*ft_clean_flag(char *first)
{
	const char *ref;
	char *flag;
	int i;

	flag = ft_strnew(6);
	ref = "#0-+ '";
	while (*ref != 0)
	{
		printf("%c\n",*ref);
		i = 0;
		while (first[i] != 0)
		{
			if (first[i] == *ref)
			{
				flag = ft_fill_flag(*ref, flag);
				break ;
			}
			i++;
		}
		ref++;
	}
	return (flag);
}

int main(void)
{
	printf("flag :\t|%s|\n", ft_clean_flag("###00000   #   '## ++ - +++ 000 '#   +-"));
	printf("flag :\t|%s|\n", ft_clean_flag(" + 00000   #   '## ++  +++ 000 '#   +"));
	printf("flag :\t|%s|\n", ft_clean_flag(" 00000   #   '## - 000 '#-"));
	printf("flag :\t|%s|\n", ft_clean_flag("  00000   #   '## 000 '#   "));
	printf("flag :\t|%s|\n", ft_clean_flag(" 00000   # +  '##  000 '#"));
	return (0);
}
*/
