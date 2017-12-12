#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int		main(int argc, char **argv)
{
	int		i;
	int		count;
	char	*format;
	t_lst	*first;
	t_lst	*index;
//	int		n;
//	t_info	info_struct;

	i = 1;
	while (i < argc)
	{
		printf("%s", argv[i]);
		i++;
	}
//	first = ft_lst_init();
//	info_struct = ft_info_init();
	format = "af%   164.14hhdalors %d%hschaine_finale";
//	n = ft_is_conv(format, 1, 0, &info_struct);
//	ft_putnbr(n);
//	ft_putstr("\n");
//	ft_info_show(info_struct);
	first = ft_format_split(format);

	count = 0;
	index = first;
	while (index != 0)
	{
		index = index->next;
		count ++;
	}

	i = 1;
	while (i < count)
	{
		ft_lst_show(first, i);
		i++;
	}
	ft_empty_lst(first);
//	sleep(100);

	return (0);
}

