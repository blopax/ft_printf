/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:13:14 by nvergnac          #+#    #+#             */
/*   Updated: 2017/12/11 17:14:49 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type(char *format, int st, t_info *inf)
{
	int		j;
	char	*type_str;

	type_str = "sSpdDioOuUxXc";
	j = 0;
	while (type_str[j] != 0)
	{
		if (format[st] == type_str[j])
		{
			inf->type = type_str[j];
			return (1);
		}
		j++;
	}
	return (0);
}

int		ft_chk_spec_mdf(char *format, int st, char mdf_str, t_info *info)
{
	if (format[st] == mdf_str && (mdf_str == 'h' || mdf_str == 'l'))
	{
		if (format[st + 1] == mdf_str)
		{
			if (mdf_str == 'h')
				info->mdf = "hh";
			else
				info->mdf = "ll";
			return (2);
		}
		else
		{
			info->mdf = ft_strnew(1);
			info->mdf[0] = mdf_str;
			return (1);
		}
	}
	return (0);
}

int		ft_mdf(char *format, int st, t_info *inf)
{
	int		j;
	char	*mdf_str;

	mdf_str = "hljz";
	j = 0;
	while (mdf_str[j] != 0)
	{
		if (format[st] == mdf_str[j] && mdf_str[j] != 'h'
				&& mdf_str[j] != 'l')
		{
			inf->mdf = ft_strnew(1);
			inf->mdf[0] = mdf_str[j];
			return (1);
		}
		if (ft_chk_spec_mdf(format, st, mdf_str[j], inf) > 0)
			return (ft_chk_spec_mdf(format, st, mdf_str[j], inf));
		j++;
	}
	return (0);
}

char	*ft_append_acc_char(char format, int k, char *tmp)
{
	char	*buf;

	buf = ft_strdup(tmp);
	free(tmp);
	if (!(tmp = ft_strnew(ft_strlen(buf) + 1)))
		exit(0);
	ft_strcpy(tmp, buf);
	free(buf);
	tmp[k] = format;
	return (tmp);
}

int		ft_acc(char *format, int st, t_info *inf)
{
	int		k;
	char	*tmp;

	if (format[st] != '.')
		return (0);
	if (!(tmp = ft_strnew(1)))
		exit(0);
	tmp[0] = '.';
	k = 1;
	while (format[st + k] >= '0' && format[st + k] <= '9')
	{
		if (!(tmp = ft_append_acc_char(format[st + k], k, tmp)))
			exit(0);
		k++;
	}
	if (!(inf->acc = ft_strdup(tmp)))
		exit(0);
	free(tmp);
	return (k);
}

char	*ft_append_size_char(char format, int k, char *tmp)
{
	char	*buf;

	buf = ft_strdup(tmp);
	free(tmp);
	if (!(tmp = ft_strnew(ft_strlen(buf) + 1)))
		exit(0);
	ft_strcpy(tmp, buf);
	free(buf);
	tmp[k] = format;
	return (tmp);
}

int		ft_size(char *format, int st, t_info *inf)
{
	int		k;
	char	*tmp;

	k = 0;
	if (!(tmp = ft_strnew(1)))
		exit(0);
	while (format[st + k] >= '0' && format[st + k] <= '9')
	{
		if (!(tmp = ft_append_size_char(format[st + k], k, tmp)))
			exit(0);
		k++;
	}
	if (!(inf->size = ft_strdup(tmp)))
		exit(0);
	free(tmp);
	return (k);
}

char	*ft_apd_flg_chr(char format, t_flag flag)
{
	char	*buf;

	if (flag.k == 0)
	{
		if (!(flag.tmp = ft_strnew(1)))
			exit(0);
	}
	buf = ft_strdup(flag.tmp);
	free(flag.tmp);
	if (!(flag.tmp = ft_strnew(ft_strlen(buf) + 1)))
		exit(0);
	ft_strcpy(flag.tmp, buf);
	free(buf);
	flag.tmp[flag.k] = format;
	return (flag.tmp);
}

int		ft_flag(char *format, int st, t_info *inf)
{
	t_flag		flag;

	flag.flag_str = "# +-";
	flag.k = 0;
	flag.switch_flag = 0;
	while (format[st + flag.k] != 0 && flag.switch_flag == 0)
	{
		flag.j = 0;
		while (flag.flag_str[flag.j] != 0)
		{
			flag.switch_flag = 1;
			if (flag.flag_str[flag.j++] == format[st + flag.k])
			{
				if (!(flag.tmp = ft_apd_flg_chr(format[st + flag.k], flag)))
					exit(0);
				flag.switch_flag = 0;
				break ;
			}
		}
		flag.k++;
	}
	if (!(inf->flags = ft_strdup(flag.tmp)))
		exit(0);
	free(flag.tmp);
	return (flag.k - 1);
}

int		ft_conv(char *format, int st, int flag, t_info *inf_ptr)
{
	if (format[st] != '%' && flag == 0)
		return (0);
	if (flag == 0)
		st++;
	if (ft_type(format, st, inf_ptr) >= 1 && flag <= 5)
		return (1);
	if (ft_mdf(format, st, inf_ptr) >= 1 && flag <= 4)
		return (ft_conv(format, st + ft_mdf(format, st, inf_ptr), 5, inf_ptr));
	if (ft_acc(format, st, inf_ptr) >= 1 && flag <= 3)
		return (ft_conv(format, st + ft_acc(format, st, inf_ptr), 4, inf_ptr));
	if (ft_size(format, st, inf_ptr) >= 1 && flag <= 2)
		return (ft_conv(format, st + ft_size(format, st, inf_ptr), 3, inf_ptr));
	if (ft_flag(format, st, inf_ptr) >= 1 && flag <= 1)
		return (ft_conv(format, st + ft_flag(format, st, inf_ptr), 2, inf_ptr));
	return (0);
}
