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

const char	*type_tab[9][7] =
{
	{0,		"di",			"ouxX",					"c",		"s",			"p",		"END"},
	{0,		"int",			"int",					"int",		"char *",		"void *",	"END"},
	{"h",	"short int",	"unsigned short int",	0,			0,				0,			"END"},
	{"hh",	"signed char",	"unsigned char",		0,			0,				0,			"END"},
	{"l",	"long",			"unsigned long",		"wint_t",	"wchar_t *",	0,			"END"},
	{"ll",	"long long",	"unsigned long long",	0,			0,				0,			"END"},
	{"j",	"intmax_t",		"uintmax_t",			0,			0,				0,			"END"},
	{"z",	"size_t",		"size_t",				0,			0,				0,			"END"},
	{"END",	"END",			"END",					"END",		"END",			"END",		"END"}
};

char	*ft_v_type(char type, char *mdf)
{
	int		i;
	int		j;
	char	*v_type;

	j = 1;
	while (ft_strcmp(type_tab[0][j], "END") != 0)
	{
		if (ft_strchr(type_tab[0][j], (int)type))
		{

			i = 1;
			while (type_tab[i][j] == 0 || ft_strcmp(type_tab[i][j], "END") != 0)
			{
				if (mdf == 0)
					v_type = (char *)type_tab[1][j];
				else if (type_tab[i][0] != 0)
				{
					if(ft_strcmp(type_tab[i][0], mdf) == 0 && type_tab[i][j] == 0)
						v_type = (char *)type_tab[1][j];
					else if(ft_strcmp(type_tab[i][0], mdf) == 0)
						v_type = (char *)type_tab[i][j];
				}
				i++;
			}
		}
		j++;
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
		if (first->type)
			first->v_type = ft_v_type(first->type, first->mdf);
		first = first->next;
	}
}

intmax_t	va_arg_intmax(va_list ap, char *v_type)
{
		if (ft_strcmp(v_type, "int") == 0)
			return (va_arg(ap, int));
		if (ft_strcmp(v_type, "short int") == 0)
			return ((short int)va_arg(ap, int));
		if (ft_strcmp(v_type, "signed char") == 0)
			return ((signed char)va_arg(ap, int));
		if (ft_strcmp(v_type, "long") == 0)
			return (va_arg(ap, long));
		if (ft_strcmp(v_type, "long long") == 0)
			return (va_arg(ap, long long));
		if (ft_strcmp(v_type, "intmax_t") == 0)
			return (va_arg(ap, intmax_t));
		if (ft_strcmp(v_type, "wint_t") == 0)
			return (va_arg(ap, intmax_t));
		return (0);
}

uintmax_t	va_arg_uintmax(va_list ap, char *v_type)
{
		if (ft_strcmp(v_type, "size_t") == 0)
			return (va_arg(ap, uintmax_t));
		if (ft_strcmp(v_type, "unsigned short int") == 0)
			return (va_arg(ap, uintmax_t));
		if (ft_strcmp(v_type, "unsigned char") == 0)
			return (va_arg(ap, uintmax_t));
		if (ft_strcmp(v_type, "unsigned long") == 0)
			return (va_arg(ap, uintmax_t));
		if (ft_strcmp(v_type, "unsigned long long") == 0)
			return (va_arg(ap, uintmax_t));
		if (ft_strcmp(v_type, "uintmax_t") == 0)
			return (va_arg(ap, uintmax_t));
		return (0);
}


void	*va_arg_void(va_list ap, char *v_type)
{
	if (ft_strcmp(v_type, "char *") == 0)
		return (va_arg(ap, char *));
	if (ft_strcmp(v_type, "wchar_t *") == 0)
		return (va_arg(ap, wchar_t *));
	if (ft_strcmp(v_type, "void *") == 0)
		return (va_arg(ap, void *));
	return (0);
}


