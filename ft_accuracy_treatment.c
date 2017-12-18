/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accuracy_treatment.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:15:24 by pclement          #+#    #+#             */
/*   Updated: 2017/12/15 19:36:44 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_accuracy_treatment(char *str, char *acc, char type)
{
	int		i;
	int		acc_size;
	int		acc_nb;
	char	*result;
	char	*added_str;

	acc_nb = ft_atoi(++acc);
	ft_putnbr(acc_nb);
	ft_putstr("\nA\n");
	if (type == 's')
	{
		if (ft_strlen(str) > acc_nb)
		{	
	ft_putstr("\nB\n");
			if (!(result = ft_strnew(acc_nb)))
				return (NULL);
			i = 0;
			while (i < acc_nb)
			{
	ft_putstr("\nC\n");
				result[i] = str[i];
				i++;
			}
	ft_putstr("\nD\n");
//			free(str);
			return (result);
		}
	}
	else if (!(type == 'c' || type == 'C' || type == 's'))
	{
	ft_putstr("\nE\n");
		(str[0] == '-') ? acc_nb++ : acc_nb;
		if (ft_strlen(str) < acc_nb)
		{
	ft_putstr("\nF\n");
	ft_putnbr(acc_nb -ft_strlen(str));
			added_str = ft_strnew(acc_nb - ft_strlen(str));
			i = 0;
			while (i < acc_nb - ft_strlen(str))
				added_str[i++] = '0';
		ft_putstr(added_str);
			if (str[0] == '-')
				result = ft_str_pos_ins(str, 1, added_str);
			else
				result = ft_str_pos_ins(str, 0, added_str);
	ft_putstr("\nH\n");
			return (result);
		}
	}
	ft_putstr("\nI\n");
	return (str);
}
