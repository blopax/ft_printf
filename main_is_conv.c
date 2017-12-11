#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int		main(int argc, char **argv)
{
	int		i;
	char	*format;
//	t_lst	*first;
	int		n;
	t_info	info_struct;

	i = 1;
	while (i < argc)
	{
		printf("%s", argv[i]);
		i++;
	}

	info_struct = ft_info_init();
	format = "0%   164.14hhd";
	n = ft_is_conv(format, 1, 0, &info_struct);
	ft_putnbr(n);
	ft_putstr("\n");
	ft_info_show(info_struct);

	sleep(100);

	return (0);
}

