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

int		printf(const char * restrict format, ...)
{
		va_list		ap;
		t_lst		*first;
		t_lst		*index;

		va_start(ap, format);

		first = ft_format_split((char *)format);
		while (first)
		{
			if (first->v_type != 0)
				first->value = va_arg_type(ap, first->v_type);
			first = first->next;
		}
		va_end(ap);

}
