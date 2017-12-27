/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 19:02:45 by pclement          #+#    #+#             */
/*   Updated: 2017/12/27 19:42:41 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	ft_check_null(t_lst *first)
{
	while (first)
	{
		if (first->init_str == NULL && first->v_type[0] == 's')
			init_str = ft_strdup("(null)");
//q voir si dqns convtraitement on peut pas le mettre direct et si ft_acc traite dans ft_acc pour les nombres avec 0
//et pour  lire ds display changer le ft_strlen car si \0 ne le prend pas en compte 

