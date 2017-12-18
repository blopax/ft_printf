#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int		main(int argc, char **argv)
{
	int		i;
//	int		count;
//	t_lst	*first;
//	t_lst	*index;
	int		n;
//	t_info	info_struct;
	char	*str;

	i = 1;
	while (i < argc)
	{
		printf("%s", argv[i]);
		i++;
	}



	n = 3;
	i = 0;
	str = ft_strnew(n);
	while (i++ < n)
		str[i - 1] = i - 1 + '0';
	ft_putstr(ft_accuracy_treatment("12",".5",'d'));
	printf("\n%.3s\n", "012");

	return (0);
}

