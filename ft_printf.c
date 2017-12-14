/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:32:15 by pclement          #+#    #+#             */
/*   Updated: 2017/12/13 19:33:59 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char * restrict format, ...)
{
		va_list		ap;
		t_lst		*first;

		va_start(ap, format);

		first = ft_format_split((char *)format);
		while (first)
		{
			if (first->v_type != 0)
			{
				first->value_ptr = va_arg_void(ap, first->v_type);
				first->value_signed = va_arg_intmax(ap, first->v_type);
				first->value_unsigned = va_arg_uintmax(ap, first->v_type);
			}
			if (first->next != 0)
				ft_lst_show(first, 1);
			first = first->next;
		}
		va_end(ap);
	return (0);
}
