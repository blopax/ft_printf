/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_treatment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:15:58 by pclement          #+#    #+#             */
/*   Updated: 2018/01/02 19:25:19 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_val_filled(char *v_type)
{
	char	*str;

	str = 0;
	if ((ft_strcmp(v_type, "int") == 0) || (ft_strcmp(v_type, "short int") == 0)
			|| (ft_strcmp(v_type, "signed char") == 0)
			|| (ft_strcmp(v_type, "long") == 0)
			|| (ft_strcmp(v_type, "long long") == 0)
			|| (ft_strcmp(v_type, "intmax_t") == 0)
			|| (ft_strcmp(v_type, "ssize_t") == 0)
			|| (ft_strcmp(v_type, "wint_t") == 0))
		str = ft_strdup("value_signed");
	if ((ft_strcmp(v_type, "size_t") == 0)
			|| (ft_strcmp(v_type, "unsigned short int") == 0)
			|| (ft_strcmp(v_type, "unsigned char") == 0)
			|| (ft_strcmp(v_type, "unsigned long") == 0)
			|| (ft_strcmp(v_type, "unsigned long long") == 0)
			|| (ft_strcmp(v_type, "uintmax_t") == 0))
		str = ft_strdup("value_unsigned");
	if ((ft_strcmp(v_type, "char *") == 0)
			|| (ft_strcmp(v_type, "wchar_t *") == 0)
			|| (ft_strcmp(v_type, "void *") == 0))
		str = ft_strdup("value_ptr");
	return (str);
}

char	*ft_big_wchar_conv(t_lst *first, intmax_t val)
{
	char		*str;

	if ((val >= 55296 && val <= 57343) || val >= 1114112)
	{
		first->ret = -1;
		str = NULL;
	}
	else if (val < 65536)
	{
		first->read_bytes = first->read_bytes + 3;
		str = ft_strnew(3);
		str[0] = val / 4096 + 128 + 64 + 32;
		str[1] = (val - (val / 4096) * 4096) / 64 + 128;
		str[2] = val % 64 + 128;
	}
	else
	{
		first->read_bytes = first->read_bytes + 4;
		str = ft_strnew(4);
		str[0] = val / 262144 + 128 + 64 + 32 + 16;
		str[1] = (val - (val / 262144) * 262144) / 4096 + 128;
		str[2] = (val - (val / 4096) * 4096) / 64 + 128;
		str[3] = val % 64 + 128;
	}
	return (str);
}

char	*ft_wchar_conv(t_lst *first)
{
	char		*str;
	intmax_t	val;

	setlocale(LC_ALL, "en_US.UTF-8");
	val = first->value_signed;
	if (val < 128)
	{
		first->read_bytes = first->read_bytes + 1;
		str = ft_strnew(1);
		str[0] = val;
	}
	else if (val < 2048)
	{
		first->read_bytes = first->read_bytes + 2;
		str = ft_strnew(2);
		str[0] = val / 64 + 128 + 64;
		str[1] = val % 64 + 128;
	}
	else
		str = ft_big_wchar_conv(first, val);
	return (str);
}

char	*ft_char_conv(t_lst *first)
{
	char	*str;

	if (first->mdf)
	{
		if (ft_strcmp(first->mdf, "l") == 0)
			return (ft_wchar_conv(first));
	}
	str = ft_strnew(1);
	str[0] = (unsigned char)(first->value_signed);
	first->read_bytes = 1;
	return (str);
}

char	*ft_signed_conv_treatment(t_lst *first)
{
	uintmax_t	value;

	if (ft_strcmp(first->v_type, "int") == 0)
		value = (uintmax_t)((unsigned int)first->value_signed);
	else
		value = (uintmax_t)first->value_signed;
	if (first->type == 'd')
		return (ft_itoa_base_intmax(first->value_signed, "0123456789"));
	if (first->type == 'o')
		return (ft_itoa_base_uintmax(value, "01234567"));
	if (first->type == 'u')
		return (ft_itoa_base_uintmax(value, "0123456789"));
	if (first->type == 'x')
		return (ft_itoa_base_uintmax(value, "0123456789abcdef"));
	if (first->type == 'X')
		return (ft_itoa_base_uintmax(value, "0123456789ABCDEF"));
	if (first->type == 'c')
		return (ft_char_conv(first));
	return (NULL);
}

char	*ft_unsigned_conv_treatment(t_lst *first)
{
	char	*str;

	str = NULL;
	if (first->type == 'o')
		str = ft_itoa_base_uintmax(first->value_unsigned, "01234567");
	if (first->type == 'u')
		str = ft_itoa_base_uintmax(first->value_unsigned, "0123456789");
	if (first->type == 'x')
		str = ft_itoa_base_uintmax(first->value_unsigned, "0123456789abcdef");
	if (first->type == 'X')
		str = ft_itoa_base_uintmax(first->value_unsigned, "0123456789ABCDEF");
	return (str);
}

char	*ft_wstr_conv_treatment(t_lst *first, int acc_nb)
{
	char	*added_str;
	int		i;
	char	*str;
	int		pos;

	i = 0;
	pos = 0;
	str = ft_strnew(0);
	while (((wchar_t *)first->value_ptr)[i] != 0)
	{
		first->value_signed = ((wchar_t *)first->value_ptr)[i];
		added_str = ft_wchar_conv(first);
		if (acc_nb > 0 && first->read_bytes > acc_nb)
		{
			first->read_bytes = first->read_bytes - ft_strlen(added_str);
			added_str = ft_safe_free(added_str);
			break ;
		}
		str = ft_str_pos_ins(str, pos, added_str);
		added_str = ft_safe_free(added_str);
		pos = first->read_bytes;
		i++;
	}
	return (str);
}

char	*ft_wstr_conv(t_lst *first)
{
	char	*str;
	int		acc_nb;

	acc_nb = 0;
	if (first->acc)
		acc_nb = ft_atoi(first->acc + 1);
	if (!first->value_ptr)
		return (ft_strdup("(null)"));
	str = ft_wstr_conv_treatment(first, acc_nb);
	return (str);
}

char	*ft_str_conv_treatment(t_lst *first)
{
	char	*str;

	if (first->mdf)
	{
		if (ft_strcmp(first->mdf, "l") == 0)
			return (ft_wstr_conv(first));
	}
	if (!(str = ft_strdup((char *)first->value_ptr)))
		str = ft_strdup("(null)");
	return (str);
}

void	ft_conv_treatment(t_lst *first)
{
	char	*str;

	while (first)
	{
		if (first->v_type)
		{
			if ((str = ft_val_filled(first->v_type)))
			{
				if (ft_strcmp(str, "value_signed") == 0)
					first->init_str = ft_signed_conv_treatment(first);
				if (ft_strcmp(str, "value_unsigned") == 0)
					first->init_str = ft_unsigned_conv_treatment(first);
				if (ft_strcmp(str, "value_ptr") == 0)
					first->init_str = ft_str_conv_treatment(first);
			}
			str = ft_safe_free(str);
		}
		first = first->next;
	}
}
