/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:49:15 by pclement          #+#    #+#             */
/*   Updated: 2017/12/21 19:22:27 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_lst	*ft_delete_first(t_lst *first)
{
	t_lst	*tmp;

	tmp = first;
	if (first->next)
		first = first->next;
	free(tmp);
	return (first);
}

void	ft_read_bytes(t_lst *first)
{
	int		size_nb;

	size_nb = 0;
	if (first->size)
		size_nb = ft_atoi(first->size);
	if (first->read_bytes == 0)
		first->read_bytes = (int)ft_strlen(first->init_str);
	else
	{
		if (size_nb > first->read_bytes) 
			first->read_bytes = size_nb;
	}
}

int		ft_display(t_lst *first)
{
	int		total_read_bytes;

	total_read_bytes = 0;
	while (first)
	{
		ft_read_bytes(first);
		total_read_bytes = total_read_bytes + first->read_bytes;
		write(1, first->init_str, first->read_bytes);
		first = first->next;
	}
	return (total_read_bytes);
}
