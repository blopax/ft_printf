/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:09:28 by pclement          #+#    #+#             */
/*   Updated: 2017/12/07 16:57:22 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


//add list cree le maillon, le pushback a la liste
int		ft_is_in_array(char *format, int start, char **tab_check)
{
	return(0);
}

int		ft_is_conv(char *format, int start, int flag)
{
	char	*flag_str[7] = {'-', '+', ' ', '#', NULL};
	char	size_str[7] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', NULL};
	char	*accuracy_str[7] = {'.', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', NULL};
	char	*modifier_str[7] = {"hh", "h", "l", "ll", "j", "z", NULL};
	char	*type_str[7] = {'s', 'S', 'p', 'd', 'D', 'i', 'o', 'O', 'u', 'U', 'x', 'X', 'c', NULL};
// question pour tous ne ferqit on pas 2D: 1 pour le caractere, l'autre pour les specifications (nb deux fois que peut apparaitre) et plus tard autres char

	if (format[start] != '%' && flag == 0)
		return (0);
	if (flag == 0)
		start++;
	if (ft_is_in_array(format, start, type_str) == 1 && flag <= 1)
		return (1);
	if (ft_is_in_array(format, start, modifier_str) == 1 && flag <= 2)
		return (ft_is_conv(format, start + ft_is_in_array(format, start, modifier_str), 1));
	if (ft_is_in_array(format, start, accuracy_str) == 1 && flag <= 3)
		return (ft_is_conv(format, start + ft_is_in_array(format, start, accuracy_str), 2));
	if (ft_is_in_array(format, start, accuracy_str) == 1 && flag <= 4)
		return (ft_is_conv(format, start + ft_is_in_array(format, start, accuracy_str), 3));
	if (ft_is_in_array(format, start, accuracy_str) == 1 && flag <= 5)
		return (ft_is_conv(format, start + ft_is_in_array(format, start, accuracy_str), 4));


			}

t_list	*ft_lst_init(void)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->init_str = ft_strnew(0);
	new->final_str = ft_strnew(0);
	new->flags = ft_strnew(0);
	new->size = ft_strnew(0);
	new->accuracy = ft_strnew(0);
	new->modifier = ft_strnew(0);
	new->type = ft_strnew(0);
	new->next = NULL;
	return (new);
}


t_list	*ft_format_split(char *format)
{
	char**	tab;
	t_list	*first;
	int		i;
	int		spec_size;
	int		start;
	int		flag;

	flag = 0;
	start  = 0;
	first = ft_lst_init();
	while (format[i] != 0)
	{
		if (ft_is_conv(format, i, 0) == 1)
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

	// le cas pour derniere chaine


		

			start = ft_new_index(format, i);

			
		}


	return (first);
}

