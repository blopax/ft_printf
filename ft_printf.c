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

t_lst	*ft_format_split(char *format)
{
	t_lst	*first;
	t_info	info_struct;
	char**	tab;
	int		i;
	int		spec_size;
	int		start;
	int		spec_flag;

	spec_flag = 0;
	start  = 0;
	first = ft_lst_init();
	info_struct = ft_info_init();
	while (format[i] != 0)
	{
		if (ft_is_conv(format, i, 0, &info_struct) >= 1)
		{
			if (spec_flag == 0)
				ft_add_str_lst(format, i, start, first);
			spec_flag = 1;
			spec_size = ft_add_spec_lst(first, &info_struct);
			i = i + spec_size - 1;
			ft_empty_struct(&info_struct);
		}
		else
		{
			if (spec_flag == 1)
				start = i;
			spec_flag = 0;
		}
		i++;
	}
	if (spec_flag == 0)
		ft_add_str_lst(format, i, start, first);
	return (first);
}
