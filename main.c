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

	ft_empty_lst(first);
//	sleep(100);

	return (0);
}

