#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	int		i;
	char	*format;
//	t_lst	*first;
	int		n;
//	t_info	info_struct;

	i = 1;
	while (i < argc)
	{
		printf("%s", argv[i]);
		i++;
	}


	format = "Salut la compagnie";


	return (0);
}

