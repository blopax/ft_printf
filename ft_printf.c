/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:32:15 by pclement          #+#    #+#             */
/*   Updated: 2017/12/29 20:43:38 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_ret(t_lst *first)
{
	while (first)
	{
		if (first->ret == -1)
			return (-1);
		first = first->next;
	}
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_lst		*first;
	t_lst		*index;
	int			read_bytes;

	if (format == NULL || ft_strcmp(format, "") == 0)
		return (0);
	va_start(ap, format);
	first = ft_format_split((char *)format);
	first= ft_delete_first(first);
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
//	ft_lst_show(first);
	if (ft_check_ret(first) == -1)
		return (-1);
	ft_accuracy_treatment(first);
	ft_get_clean_flag(first);
	read_bytes = ft_display(first);
	va_end(ap);
	ft_empty_lst(first);
	return (read_bytes);
}
