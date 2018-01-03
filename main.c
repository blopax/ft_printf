#include <stdio.h>
#include "ft_printf.h"
#include <locale.h>
#include <wchar.h>

int		main()
{
//	setlocale(LC_ALL, "");
	int		i;
	wchar_t	s[7];

	s[0] = 'a';
	s[1] = 'b';
	s[2] = 'c';
	s[3] = 'd';
	s[4] = 256;
	s[5] = 'e';
	s[6] = 0;

//	i = printf("yo%2C%-12lc%C%C", 'u',254, 256, 'a');
//	ft_putnbr(i);
//	i = ft_printf("yo%2C et %-12lc et %C titi %C tyty", 'u', 256, 254, 'a');
//	ft_putnbr(i);
//	ft_putstr("\n");

	ft_putstr("\n");
//	ft_putnbr(i);
	ft_putstr("\n");
	i = printf("%s", "Beer in mind");
	ft_putstr("\n");
	ft_putnbr(i);

	return (0);
}
