
#include "ft_printf.h"

//add list cree le maillon, le pushback a la liste

t_info	ft_info_init(void)
{
	t_info	new_info;

	new_info.flags = ft_strnew(0);
	new_info.size = ft_strnew(0);
	new_info.acc = ft_strnew(0);
	new_info.mdf = ft_strnew(0);
	new_info.type = 0;
	return (new_info);
}

t_lst	*ft_lst_init(void)
{
	t_lst	*new_lst;

	if (!(new_lst = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	new_lst->init_str = ft_strnew(0);
	new_lst->final_str = ft_strnew(0);
	new_lst->flags = ft_strnew(0);
	new_lst->size = ft_strnew(0);
	new_lst->acc = ft_strnew(0);
	new_lst->mdf = ft_strnew(0);
	new_lst->type = 0;
	new_lst->next = NULL;
	return (new_lst);
}

void	ft_empty_struct(t_info *info_struct_ptr)
{
		if (info_struct_ptr->flags)
		{
			free(info_struct_ptr->flags);
			info_struct_ptr->flags = ft_strnew(0);
		}
		if (info_struct_ptr->size)
		{
			free(info_struct_ptr->size);
			info_struct_ptr->size = ft_strnew(0);
		}
		if (info_struct_ptr->acc)
		{
			free(info_struct_ptr->acc);
			info_struct_ptr->acc = ft_strnew(0);
		}
		if (info_struct_ptr->mdf)
		{
//			free(info_struct_ptr->mdf);
			info_struct_ptr->mdf = ft_strnew(0);
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


void	ft_print_lst(t_lst *index, int n)
{
	ft_putstr("MAILLON = \t");
	ft_putnbr(n - 1);
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
	ft_putstr("|\n\n");
}

void	ft_lst_show(t_lst *first, int n)
{
	t_lst	*index;
	int		i;

	i = 0;
	index = first;
	while (i < n)
	{
		index = index->next;
		i++;
	}

	ft_print_lst(index, n);
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
	ft_empty_struct(info_struct_ptr);
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
	new_lst->init_str = str;
	index->next = new_lst;
}
