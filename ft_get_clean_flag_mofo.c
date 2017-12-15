/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_clean_flag_mofo.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:21:44 by nvergnac          #+#    #+#             */
/*   Updated: 2017/12/15 20:21:59 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
/*
void	ft_clean_flag_spc(t_lst *first)
{
	int i;

	i = 0;
	while (first->flags[i])
	{
		if (first->flags[i] == '0' && first->acc == 0)

	}
}
*/
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
/*
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

void	ft_clean_flag_spc(t_lst *first)
{

}

void	*ft_get_clean_flag(t_lst *first)
{
	ft_clean_flag(first);
	if (first->mdf[0] == 's' || first->mdf[0] == 'p' || first->mdf[0] == 'c')
		ft_clean_flag_spc(first);
	if (first->mdf[0] == 'd')
		ft_clean_flag_d(first);
	if (first->mdf[0] == 'u')
		ft_clean_flag_u(first);
	if (first->mdf[0] == 'o')
		ft_clean_flag_o(first);
	if (first->mdf[0] == 'x')
		ft_clean_flag_x(first);
}
*/
