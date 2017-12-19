/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:32:15 by pclement          #+#    #+#             */
/*   Updated: 2017/12/19 16:56:19 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			n;
	t_lst		*first;
	t_lst		*index;

	n = 1;
	va_start(ap, format);
	first = ft_format_split((char *)format);
	ft_v_type_clean(first);

	index = first;
	while (index)
	{
		if (index->v_type != 0)
		{
			index->value_signed = va_arg_intmax(ap, index->v_type);
			index->value_ptr = va_arg_void(ap, index->v_type);
			index->value_unsigned = va_arg_uintmax(ap, index->v_type);
		}
		index = index->next;
	}
	ft_conv_treatment(first);
	ft_accuracy_treatment(first);
	ft_lst_show(first);
	va_end(ap);
	ft_empty_lst(first);
	return (0);
}
