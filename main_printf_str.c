#include <stdio.h>
#include <stdlib.h>
#include "libft/includes/libft.h"
#include "ft_printf.h"

int		main(int argc, char **argv)
{
	int		i;
	char	*str;
	wchar_t	*Str;

	i = 1;
	while (i < argc)
	{
		printf("%s", argv[i]);
		i++;
	}

	str = "Salut ca boome ?";
	printf("%#+ 's\n", str);

	str = "Salut";
	printf("%0s\n", str);
	
	str = "Salut";
	printf("%-s\n", str);
	
	str = "Salut";
	printf("%10s\n", str);
	
	str = "Salut";
	printf("%-010s\n", str);

	str = "Salut";
	printf("%010s\n", str);

	str = "Salut";
	printf("%-10s\n", str);

	str = "Salut";
	printf("%3s\n", str);

	str = "Salut";
	printf("%3s\n", str);

	str = "Salut";
	printf("%.3s\n", str);

	printf("\n\nconversion S\n\n");

/*	Str = "Salut ca boome ?";
	printf("%S\n", Str);
	
	Str = "Salut ca boome ?";
	printf("%#+ 'S\n", Str);

	Str = "Salut";
	printf("%0S\n", Str);
	
	Str = "Salut";
	printf("%-S\n", Str);
	
	Str = "Salut";
	printf("%10S\n", Str);
	
	Str = "Salut";
	printf("%-010S\n", Str);

	Str = "Salut";
	printf("%010S\n", Str);

	Str = "Salut";
	printf("%-10S\n", Str);

	Str = "Salut";
	printf("%3S\n", Str);

	Str = "Salut";
	printf("%3S\n", Str);

	Str = "Salut";
	printf("%.3S\n", Str);*/









//	printf("adresse avec itoa_base : \t%s\n", ft_itoa_base(test, 16));
	return (0);
}

