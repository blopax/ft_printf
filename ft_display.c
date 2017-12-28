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

int		ft_read_bytes(t_lst *first)
{
	int		read_bytes;
	int		size_nb;

	size_nb = 0;
	if (first->size)
		size_nb = ft_atoi(first->size);
	if (first->type == 'c' || first->type == 'C')
	{
		read_bytes = 1;
		if (size_nb > 1) 
			read_bytes = size_nb;
	}
	else
		read_bytes = ft_strlen(first->init_str);
	return (read_bytes);
}

int		ft_display(t_lst *first)
{
	int		read_bytes;
	int		total_read_bytes;

	total_read_bytes = 0;
	while (first)
	{
		read_bytes = ft_read_bytes(first);
		total_read_bytes = total_read_bytes + read_bytes;
		write(1, first->init_str, read_bytes);
		first = first->next;
	}
	return (total_read_bytes);
}
