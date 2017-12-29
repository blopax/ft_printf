#include <stdio.h>
#include <stdlib.h>
#include "libft/includes/libft.h"
#include "ft_printf.h"

int		main(int argc, char **argv)
{
	int		i;
	int		nb;

	i = 1;
	while (i < argc)
	{
		printf("|%s", argv[i]);
		i++;
	}

	nb = -12;
	printf("|%05.12d|\n", nb);
	nb = -12;
	printf("|%05.1d|\n", nb);
	nb = -12;
	printf("|%0.3d|\n", nb);


	printf("|%d|\n", nb);
	printf("|%u|\n", nb);
	printf("|%hu|\n", nb);


/*
	C = 100;
	printf("|%#+ 'C|\n", C);
	C = 100;
	printf("|%C|\n", C);
	C = 100;
	printf("|%-0C|\n", C);
	C = 100;
	printf("|%-010C|\n", C);
	C = 100;
	printf("|%+2C|\n", C);
	C = 100;
	printf("|%.3C|\n", C);
	C = 100;
	printf("|%.5C|\n", C);
	C = 100;
	printf("|%0C|\n", C);
*/

	return (0);
}

