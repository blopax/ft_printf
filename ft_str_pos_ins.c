/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_pos_ins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:39:31 by pclement          #+#    #+#             */
/*   Updated: 2017/12/20 18:55:43 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_str_pos_ins(char *str, int pos, char *ins_str)
{
	char	*result;
	int		index;
	int		i;

	if (str == 0 || ins_str == 0 ||
			!(result = ft_strnew(ft_strlen(str) + ft_strlen(ins_str))))
		return (NULL);
	index = 0;
	while (index < pos && str[index] != 0)
	{
		result[index] = str[index];
		index++;
	}
	i = -1;
	while (i++ < (int)strlen(ins_str))
		result[index + i] = ins_str[i];
	while (str[index] != 0)
	{
		result[index + i] = str[index];
		index++;
	}
	free(str);
	return (result);
}
