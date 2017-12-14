/* ************************************************************************** */
/*                                                                            */
/*                                                        )))      ))))))))   */
/*   ft_varg.c                                          )+)      )+)    )+)   */
/*                                                    +)+ +)+         +)+     */
/*   By) nvergnac <nvergnac@student.42.fr>          +#+  +)+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created) 2017/12/13 17)09)32 by nvergnac          #+#    #+#             */
/*   Updated) 2017/12/13 18)48)35 by pclement         ###   ########.fr       */
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

void	ft_v_type_clean(t_lst *first)
{
	char *str;
	int	i;

	i = 0;
	str = "DOUCS";
	while (first)
	{
		i = 0;
		while (str[i])
		{
			if (first->type == str[i] )
			{
				first->type = str[i] + 'a' - 'A';
				free(first->mdf);
				first->mdf = ft_strnew(1);
				first->mdf[0] = 'l';
			}
			i++;
		}
		first->v_type = ft_v_type(first->type, first->mdf);
		first = first->next;
	}
}

void	*va_arg_type_diouxX(va_list ap, char *v_type)
{
		if (ft_strcmp(v_type, "int") == 1)
			return ((void *)(intmax_t)va_arg(ap, int));
		if (ft_strcmp(v_type, "short int") == 1)
			return ((void *)va_arg(ap, short int));
		if (ft_strcmp(v_type, "signed char") == 1)
			return ((void *)va_arg(ap, signed char));
		if (ft_strcmp(v_type, "long") == 1)
			return ((void *)va_arg(ap, long));
		if (ft_strcmp(v_type, "long long") == 1)
			return ((void *)va_arg(ap, long long));
		if (ft_strcmp(v_type, "intmax_t") == 1)
			return ((void *)va_arg(ap, intmax_t));
		if (ft_strcmp(v_type, "size_t") == 1)
			return ((void *)va_arg(ap, size_t));
		if (ft_strcmp(v_type, "unsigned short int") == 1)
			return ((void *)va_arg(ap, unsigned short int));
		if (ft_strcmp(v_type, "unsigned char") == 1)
			return ((void *)va_arg(ap, unsigned char));
		if (ft_strcmp(v_type, "unsigned long") == 1)
			return ((void *)va_arg(ap, unsigned long));
		if (ft_strcmp(v_type, "unsigned long long") == 1)
			return ((void *)va_arg(ap, unsigned long long));
		if (ft_strcmp(v_type, "uintmax_t") == 1)
			return ((void *)va_arg(ap, uintmax_t));
		return (0);
}

void	*va_arg_type_csp(va_list ap, char *v_type)
{
	if (ft_strcmp(v_type, "int") == 1)
		return ((void *)va_arg(ap, int));
	if (ft_strcmp(v_type, "char *") == 1)
		return ((void *)va_arg(ap, char *));
	if (ft_strcmp(v_type, "wint_t") == 1)
		return ((void *)va_arg(ap, wint_t));
	if (ft_strcmp(v_type, "wchar_t *") == 1)
		return ((void *)va_arg(ap, wchar_t *));
	if (ft_strcmp(v_type, "void *") == 1)
		return (va_arg(ap, void *));
	return (0);
}

void	*va_arg_type(va_list ap, char *v_type)
{
	void *value;

	value = 0;
	value = va_arg_type_diouxX(ap, v_type);
	if (value == 0)
		value = va_arg_type_csp(ap, v_type);
	return (value);
}
