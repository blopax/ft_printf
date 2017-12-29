/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accuracy_treatment.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:15:24 by pclement          #+#    #+#             */
/*   Updated: 2017/12/29 17:29:11 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_accuracy_str_treatment(char *str, char *acc, char type)
{
	int		i;
	int		acc_nb;
	char	*added_str;

	added_str = 0;
	acc_nb = ft_atoi(acc + 1);
	if ((type == 's' && (int)ft_strlen(str) > acc_nb))
		str[acc_nb] = 0;
	if (!(type == 'c' || type == 'C' || type == 's'))
	{
		(str[0] == '-') ? acc_nb++ : acc_nb;
		if ((int)ft_strlen(str) < acc_nb)
		{
			added_str = ft_strnew(acc_nb - (int)ft_strlen(str));
			i = 0;
			while (i < acc_nb - (int)ft_strlen(str))
				added_str[i++] = '0';
			if (str[0] == '-')
				str = ft_str_pos_ins(str, 1, added_str);
			else
				str = ft_str_pos_ins(str, 0, added_str);
		}
		if (acc_nb == 0 && ft_atoi(str) == 0)
			str[acc_nb] = 0;
	}
	free(added_str);
	return (str);
}

int		ft_check_acc_zero(t_lst *first)
{
	int		ret;

	ret = 1;
	if (ft_atoi(first->acc + 1) != 0)
		ret = 0;
	if (first->type == 's' || first->type == 'p' || first->type == 'c')
		ret = 0;
	if (first->value_signed != 0 || first->value_unsigned != 0)
		ret = 0;

	return (ret);
}

void	ft_accuracy_treatment(t_lst *first)
{
	while (first)
	{
		if (first->acc != 0)
		{	
			if (ft_check_acc_zero(first) == 1)
				first->init_str = ft_strdup("");
			else
				first->init_str = ft_accuracy_str_treatment(first->init_str,
					first->acc, first->type);
		}
		first = first->next;
	}
}
