/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:09:32 by nvergnac          #+#    #+#             */
/*   Updated: 2017/12/13 17:40:35 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_clean(t_lst *first)
{
	char *str;
	int	i;

	i = 0;
	str = "DOUCS";
	while (first)
	{
		i = 0;
		while (str[i])
		{
			if (first->type == str[i] )
			{
				first->type = str[i] + 32;
				free(first->flags);
				first->flags = ft_strnew(0);
				first->flags[0] = 'l';
			}
			i++;
		}
		first = first->next;
	}
}
