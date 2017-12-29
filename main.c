#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <limits.h>
#include <wchar.h>
#include <locale.h>


int		main(int argc, char **argv)
{
	int		i;
//	int		a;
//	int		count;
	char	*format;
//	int		n;
//	char	*str;

	setlocale(LC_ALL, "en_US.UTF-8");

	i = 1;
	while (i < argc)
	{
		printf("%s", argv[i]);
		i++;
	}
	//format = "%#-5o%#05o%#-4o%#04o";
//	format = "%+7d%#7o%+7o%#7d";
	format = "%lc";

//	ft_putstr("\nformat\t");
//	ft_putstr("\n");
	ft_putstr("real_printf\n");
//	printf("%p", NULL);
	i = ft_printf(format, 0x123);
	printf("\n");


	i = 65536 / 262144 + 128 + 64 + 32 + 16;
	ft_putnbr(i);
ft_putstr("\n");
	i = (65536 - (65536 / 262144) * 262144) / 4096 + 128;
	ft_putnbr(i);
ft_putstr("\n");
	i = (65536 - (65536 / 4096) * 4096) / 64 + 128;
	ft_putnbr(i);
ft_putstr("\n");
	i = 65536 % 64 + 128;
ft_putnbr(i);
ft_putstr("\n");


//ft_putnbr(i);

//	i = printf(format, 57344);
//ft_putnbr(i);

//	ft_putstr("\nft_printf\n");
//	ft_printf(format, 0x07F7 );

//	ft_putstr("\n\n");
/*	unsigned char c;
    c = 8364 / 4096 + 192 + 32;
    write(1, &c, 1);
	c = (8364 - ((8364 / 4096)*4096)) / 64 + 128;
    write(1, &c, 1);
    c = 8364 % 64 + 128;
    write(1, &c, 1);
*/
/*    c = 8364;
	write(1, &c, 1);
    c = 0x41;
	write(1, &c, 1);
	*/
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
