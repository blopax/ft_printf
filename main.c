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
	int		n;
	t_info	info_struct;
	char	*str;

	i = 1;
	while (i < argc)
	{
		printf("%s", argv[i]);
		i++;
	}
	first = ft_lst_init();
	info_struct = ft_info_init();

	format = "% 8.4dalors %dautremaillon%schaine_finale";
	ft_printf(format, 3, 4, "hello");

	ft_printf(format, i);
//	printf("\n%.0s\n", "012345");
//	while (first)
//	{
//		ft_lst_show(first, 0);
//		first = first->next;
//	}
// ft_putstr(ft_v_type('s', "hh"));

	ft_empty_lst(first);
//	sleep(100);

	return (0);
}

