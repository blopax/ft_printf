/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:09:28 by pclement          #+#    #+#             */
/*   Updated: 2017/12/08 19:33:06 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//add list cree le maillon, le pushback a la liste

t_lst	*ft_lst_init(void)
{
	t_lst	*new;

	if (!(new = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	new->init_str = ft_strnew(0);
	new->final_str = ft_strnew(0);
	new->flags = ft_strnew(0);
	new->size = ft_strnew(0);
	new->accuracy = ft_strnew(0);
	new->modifier = ft_strnew(0);
	new->type = 0;
	new->next = NULL;
	return (new);
}


t_lst	*ft_format_split(char *format)
{
	t_lst	*first;
	t_info	info_struct;
	char**	tab;
	int		i;
	int		spec_size;
	int		start;
	int		flag;

	flag = 0;
	start  = 0;
	first = ft_lst_init();
	while (format[i] != 0)
	{
		if (ft_is_conv(format, i, 0, info_struct) == 1)
		{
			if (flag == 0)
				ft_add_str_lst(format, i, start, first);
			flag = 1;
			spec_size = ft_add_spec_lst(format, i, first);
			i = i + spec_size - 1;
		}
		else
		{
			if (flag == 1)
				start = i;
			flag = 0;
		}
		i++;
	}
	if (flag == 0)
		ft_add_str_lst(format, i, start, first);
	return (first);
}
