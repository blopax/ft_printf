#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <limits.h>

int		main(int argc, char **argv)
{
	int		i;
//	int		a;
//	int		count;
	char	*format;
//	int		n;
//	char	*str;

	i = 1;
	while (i < argc)
	{
		printf("%s", argv[i]);
		i++;
	}
	//format = "%#-5o%#05o%#-4o%#04o";
//	format = "%+7d%#7o%+7o%#7d";
	format = "%.0c\n";

	ft_putstr("\nformat\t");
	ft_putstr(format);
	ft_putstr("\n");
	ft_putstr("real_printf\n");
	printf(format, 0);
	ft_putstr("\nft_printf\n");
	ft_printf(format, 0);

//	format = "%ho";
//	ft_printf(format, 10);
//	ft_putstr("\n\n");
//	printf("\n%.0s\n", "012345");
//	while (first)
//	{
//		ft_lst_show(first, 0);
//		first = first->next;
//	}
// ft_putstr(ft_v_type('s', "hh"););

//	ft_empty_lst(first);
//	sleep(100);

	return (0);
}
