#include <stdio.h>
#include <stdlib.h>
#include "libft/includes/libft.h"
#include "ft_printf.h"

int		main(int argc, char **argv)
{
	int		i;
	int		c;
//	wint_t	C;

	i = 1;
	while (i < argc)
	{
		printf("|%s", argv[i]);
		i++;
	}

	c = 100;
	printf("|%#+ 'c|\n", c);
	c = 100;
	printf("|%c|\n", c);
	c = 100;
	printf("|%-0c|\n", c);
	c = 100;
	printf("|%-010c|\n", c);
	c = 100;
	printf("|%+2c|\n", c);
	c = 100;
	printf("|%.3c|\n", c);
	c = 100;
	printf("|%.5c|\n", c);
	c = 100;
	printf("|%0c|\n", c);

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

