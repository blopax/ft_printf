#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int		main(int argc, char **argv)
{
	int		i;
//	int		count;
	char	*format;
//	t_lst	*first;
//	t_lst	*index;
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
//	format = "af%   164.14hhSalors %d%hschaine_finale";

//ATTENTION
//	format = "af%   164.14hhCalors %d%hschaine_finale";
	format = "%0.10d";

	
	ft_putstr(ft_accuracy_treatment("012345",".0",'s'));
	printf("\n%.0s\n", "012345");
//	while (first)
//	{
//		ft_lst_show(first, 0);
//		first = first->next;
//	}
// ft_putstr(ft_v_type('s', "hh"));

/*
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
*/
	return (0);
}

