/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accuracy_treatment.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:15:24 by pclement          #+#    #+#             */
/*   Updated: 2017/12/18 20:50:45 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_accuracy_str_treatment(char *str, char *acc, char type)
{
	int		i;
	int		acc_nb;
	char	*added_str;

	acc_nb = ft_atoi(++acc);
	if (type == 's')
		(ft_strlen(str) > acc_nb) ? (str[acc_nb] = 0) : (str[0] = str[0]);
	else if (!(type == 'c' || type == 'C' || type == 's'))
	{
		(str[0] == '-') ? acc_nb++ : acc_nb;
		if (ft_strlen(str) < acc_nb)
		{
			added_str = ft_strnew(acc_nb - ft_strlen(str));
			i = 0;
			while (i < acc_nb - ft_strlen(str))
				added_str[i++] = '0';
			if (str[0] == '-')
				str = ft_str_pos_ins(str, 1, added_str);
			else
				str = ft_str_pos_ins(str, 0, added_str);
		}
	}
	return (str);
}

void	ft_accuracy_treatment(t_lst *first)
{
	char	*tmp;

	while (first)
	{
		ft_putstr(first->acc);
		if (first->acc)
		{
			first->init_str = ft_accuracy_str_treatment(first->init_str, first->acc, first->type);
		}
		first = first->next;
	}
}
