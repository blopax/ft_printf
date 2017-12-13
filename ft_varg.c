/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:56:53 by pclement          #+#    #+#             */
/*   Updated: 2017/12/13 17:56:06 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_v_type(char type, char *mdf)
{
	int		i;
	int		j;
	char	*v_type;

	j = 0;
	while (type_tab[0][j] != 0)
	{
		if (ft_strchr(type_tab[0][j], (int)type))
		{
			i = 0;
			while (type_tab[i] != 0)
			{
				if (ft_strcmp(type_tab[i][0], mdf) == 0)
					v_type = (char *)type_tab[i][j];
			}
		}
	}
	return (v_type);
}





