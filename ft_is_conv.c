/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:24:58 by pclement          #+#    #+#             */
/*   Updated: 2017/12/08 19:36:01 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_type_array(char *format, int start, t_info *info_struct)
{
	int		j;
	char	*type_str;

	type_str = "sSpdDioOuUxXc";
	j = 0;
	while (type_str[j] != 0)
	{
		if (format [start] == type_str[j])
		{
			info_struct->type = type_str[j];
			return (1);
		}
		j++;
	}
	return (0);
}

// pour les modifier pb car met un caractere dans une string sans conclure
int		ft_check_special_modifier(char *format,int start, char modifier_str, t_info *info_struct)
{
	if (format[start] == modifier_str && (modifier_str == 'h' || modifier_str == 'l'))
	{
		if (format[start + 1] == modifier_str)
		{
			if (modifier_str == 'h')
				info_struct->modifier = "hh";
			else
				info_struct->modifier = "ll";
			return (2);
		}
		else
		{
			info_struct->modifier[0] = modifier_str;
			return (1);
		}
	}
	return (0);
}

int		ft_is_modif_array(char *format, int start, t_info *info_struct)
{
	int		j;
	char	*modifier_str;

	modifier_str = "hljz";
	j = 0;
	while (modifier_str[j] != 0)
	{
		if (format[start] == modifier_str[j] && modifier_str[j] != 'h' && modifier_str[j] != 'l')
		{
			info_struct->modifier[0] = modifier_str[j];
			return (1);
		}
		if (ft_check_special_modifier(format, start, modifier_str[j], info_struct) > 0)
			return (ft_check_special_modifier(format, start, modifier_str[j], info_struct));
		j++;
	}
	return (0);
}

int		ft_is_accuracy_array(char *format, int start, t_info *info_struct)
{
	int		k;
	char	*tmp;
	char	*buf;

	*tmp = '.';
	if (!(buf = (char *)malloc(sizeof(char) * 2)))
		exit(0);
	if (format[start] != '.')
		return (0);
	k = 1;
	while (format[start + k] >= '0' && format[start + k] <= '0' + 9)
	{	
		buf[0] = format[start + k];
		if (!(tmp = ft_strjoin(tmp, buf)))
			exit (0);
		k++;
	}
	if (!(info_struct->accuracy = ft_strjoin(info_struct->accuracy, tmp)))
		exit (0);
	return (k);
}

int		ft_is_size_array(char *format, int start, t_info *info_struct)
{
	int		k;
	char	*tmp;
	char	*buf;

	k = 0;
	tmp = ft_strnew(0);
	while (format[start + k] >= '0' && format[start + k] <= '0' + 9)
	{	
		buf[0] = format[start + k];
		if (!(tmp = ft_strjoin(tmp, buf)))
			exit (0);
		k++;
	}
	if (!(info_struct->size = ft_strjoin(info_struct->size, tmp)))
		exit (0);
	return (k);
}

int		ft_is_flag_array(char *format, int start, t_info *info_struct)
{
	int		k;
	int		j;
	char	*tmp;
	char	*buf;
	char	*flag_str;
	int		switch_flag;

	flag_str = "# +-";
	k = 0;
	if (!(tmp = ft_strnew(0)))
		exit(0);
	if (!(buf = ft_strnew(1)))
		exit(0);
	switch_flag = 0;
	while (format[start + k] != 0 && switch_flag == 0)
	{
		j = 0;
		while (flag_str[j] != 0)
		{
			switch_flag = 1;
			if (flag_str[j] == format[start + k])
			{
				buf[0] = format[start + k];
				if (!(tmp = ft_strjoin(tmp, buf)))
					exit (0);
				switch_flag = 0;
				break;
			}
		j++;
		}
		k++;
	}

	return (k);
}

int		ft_is_conv(char *format, int start, int flag, t_info info_struct)
{
	if (format[start] != '%' && flag == 0)
		return (0);
	if (flag == 0)
		start++;
	if (ft_is_type_array(format, start, &info_struct) >= 1 && flag <= 5)
		return (1);
	if (ft_is_modif_array(format, start, &info_struct) >= 1 && flag <= 4)
		return (ft_is_conv(format, start + ft_is_modif_array(format, start, &info_struct), 5, info_struct));
	if (ft_is_accuracy_array(format, start, &info_struct) >= 1 && flag <= 3)
		return (ft_is_conv(format, start + ft_is_accuracy_array(format, start, &info_struct), 4, info_struct));
	if (ft_is_size_array(format, start, &info_struct) >= 1 && flag <= 2)
		return (ft_is_conv(format, start + ft_is_size_array(format, start, &info_struct), 3, info_struct));
	if (ft_is_flag_array(format, start, &info_struct) >= 1 && flag <= 1)
		return (ft_is_conv(format, start + ft_is_flag_array(format, start, &info_struct), 2, info_struct));
	ft_empty_struct(&info_struct);
	return (0);
}
