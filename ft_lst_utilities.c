
#include "ft_printf.h"

//add list cree le maillon, le pushback a la liste

t_info	ft_info_init(void)
{
	t_info	new_info;

	new_info.flags = NULL;
	new_info.size = NULL;
	new_info.acc = NULL;
	new_info.mdf = NULL;
	new_info.type = 0;
	return (new_info);
}

t_lst	*ft_lst_init(void)
{
	t_lst	*new_lst;

	if (!(new_lst = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	new_lst->init_str = NULL;
	new_lst->final_str = NULL;
	new_lst->flags = NULL;
	new_lst->size = NULL;
	new_lst->acc = 0;
	new_lst->mdf = NULL;
	new_lst->type = 0;
	new_lst->next = NULL;
	new_lst->v_type = 0;
	new_lst->value_ptr = 0;
	new_lst->value_signed = 0;
	new_lst->value_unsigned = 0;
	return (new_lst);
}

void	ft_empty_lst(t_lst *first)
{
	t_lst	*index;

	while (first)
	{
		free(first->init_str);
		free(first->final_str);
		free(first->flags);
		free(first->size);
		free(first->acc);
		free(first->mdf);
		free(first->value_ptr);
		index = first->next;
		free(first);
		first = index;
	}
}

void	ft_empty_struct(t_info *info_struct_ptr)
{
		if (info_struct_ptr->flags)
			free(info_struct_ptr->flags);
		if (info_struct_ptr->size)
			free(info_struct_ptr->size);
		if (info_struct_ptr->acc)
			free(info_struct_ptr->acc);
		if (info_struct_ptr->mdf)
			free(info_struct_ptr->mdf);
		info_struct_ptr->type = 0;
}

void	ft_reinit_struct(t_info *info_struct_ptr)
{
		if (info_struct_ptr->flags)
		{
			free(info_struct_ptr->flags);
			info_struct_ptr->flags = NULL;
		}
		if (info_struct_ptr->size)
		{
			free(info_struct_ptr->size);
			info_struct_ptr->size = NULL;
		}
		if (info_struct_ptr->acc)
		{
			free(info_struct_ptr->acc);
			info_struct_ptr->acc = NULL;
		}
		if (info_struct_ptr->mdf)
		{
			free(info_struct_ptr->mdf);
			info_struct_ptr->mdf = NULL;
		}
		info_struct_ptr->type = 0;
}

void	ft_info_show(t_info info_struct)
{
	ft_putstr("INFO STRUCT = \t");
	ft_putstr("\n");
	ft_putstr("flags = \t|");
	ft_putstr(info_struct.flags);
	ft_putstr("|\n");
	ft_putstr("size = \t\t|");
	ft_putstr(info_struct.size);
	ft_putstr("|\n");
	ft_putstr("acc = \t\t|");
	ft_putstr(info_struct.acc);
	ft_putstr("|\n");
	ft_putstr("mdf = \t\t|");
	ft_putstr(info_struct.mdf);
	ft_putstr("|\n");
	ft_putstr("type = \t\t|");
	write(1, &(info_struct.type), 1);
	ft_putstr("|\n\n");
}

//ATTENTION ENLEVER PRINTF et include stdio
#include <stdio.h>

void	ft_print_lst(t_lst *index, int n)
{
	ft_putstr("MAILLON = \t");
	ft_putnbr(n);
	ft_putstr("\n");
	ft_putstr("init_str = \t|");
	ft_putstr(index->init_str);
	ft_putstr("|\n");
	ft_putstr("final_str = \t|");
	ft_putstr(index->final_str);
	ft_putstr("|\n");
	ft_putstr("flags = \t|");
	ft_putstr(index->flags);
	ft_putstr("|\n");
	ft_putstr("size = \t\t|");
	ft_putstr(index->size);
	ft_putstr("|\n");
	ft_putstr("acc = \t\t|");
	ft_putstr(index->acc);
	ft_putstr("|\n");
	ft_putstr("mdf = \t\t|");
	ft_putstr(index->mdf);
	ft_putstr("|\n");
	ft_putstr("type = \t\t|");
	write(1, &(index->type), 1);
	ft_putstr("|\n");
	ft_putstr("v_type =\t|");
	ft_putstr(index->v_type);
	ft_putstr("|\n");
	ft_putstr("val_signed =\t|");
	ft_putnbr_intmax(index->value_signed);
	ft_putstr("|\n");
	ft_putstr("val_unsigned =\t|");
	ft_putnbr(index->value_unsigned);
	ft_putstr("|\n");
	ft_putstr("value_ptr = \t|");
	ft_putnbr((long long)index->value_ptr);
	ft_putstr("|\n\n");
}

void	ft_lst_show(t_lst *first)
{
	t_lst	*index;
	int		i;

	i = 0;
	index = first;
	while (index)
	{
		ft_print_lst(index, i);
		index = index->next;
		i++;
	}
}


int		ft_add_spec_lst(t_lst *first, t_info *info_struct_ptr)
{
	t_lst	*new_lst;
	t_lst	*index;
	int		len;

	len = 0;
	index = first;
	while (index->next)
		index = index -> next;
	
	new_lst = ft_lst_init();
	len = len + ft_strlen(new_lst->flags = ft_strdup(info_struct_ptr->flags));
	len = len + ft_strlen(new_lst->size = ft_strdup(info_struct_ptr->size));
	len = len + ft_strlen(new_lst->acc = ft_strdup(info_struct_ptr->acc));
	len = len + ft_strlen(new_lst->mdf = ft_strdup(info_struct_ptr->mdf));
	new_lst->type = info_struct_ptr->type;
	ft_reinit_struct(info_struct_ptr);
	len++;
	index->next = new_lst;
	return (len);
}

void	ft_add_str_lst(char *format, int i, int start, t_lst *first)
{
	t_lst	*new_lst;
	t_lst	*index;
	char	*str;
	int		k;

	str = ft_strnew(i - start + 1);
	k = 0;
	while (k < i - start)
	{
		str[k] = format[start + k];
		k++;
	}
	index = first;
	while (index->next)
		index = index->next;
	new_lst = ft_lst_init();
	new_lst->init_str = ft_strdup(str);
	index->next = new_lst;
	free(str);
}
