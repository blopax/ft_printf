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

	setlocale(LC_ALL, "");
//	printf("%9.6ls %S", s, (wchar_t *)'a');
	printf("\n");
	format = "3";
	i = ft_printf("42%p42", (void *)0x0);
//	ft_printf("%p\n", &format);
	ft_putnbr(i);


//	i = printf("%----4c\n", '\0');
//	printf("hello ca%----4c %1c va %10c%-c ??\n", '\0', '\n', (char)564, 0);
//ft_putnbr (i);
//	i = printf("%.5ls\n", s);
//ft_putnbr (i);

	i = 1;
	while (i < argc)
	{
		printf("%s", argv[i]);
		i++;
	}
	format = "\n";
//ft_printf("%#.3O\n", 0);
//printf("%-50.2zi\n", 0);
//	printf("%d\n", printf("%C\n", 0xbffe));
//	printf("%d\n", ft_printf("%C\n", 0xbffe));

//	printf("%d\n", printf("%lc\n", 254));
//	printf("%d\n", ft_printf("%lc\n", 254));

//	printf("%d\n", printf("%lc\n", 256));
//	printf("%d\n", ft_printf("%lc\n", 256));


//	i = printf("%lchello %C ca va", 65,  0xd800);
//	i = ft_printf("%lc", 256);
//	ft_putnbr(i);
//	printf("%d\n", ft_printf("%8C et coco %C titi %lc", 3250, 0x11ffff, 'a'));

//ft_printf(",%-34.2O\n", 0);

/*printf("%#.3O\n", (unsigned int)642891241091338830);
ft_printf("%#.3O\n", (unsigned int) 642891241091338830);
printf("%#.2O\n", (unsigned int)1);
ft_printf("%#.2O\n", (unsigned int)1);
printf("%#.O\n", (unsigned int)1);
ft_printf("%#.O\n", (unsigned int)1);
printf("%#.O\n", (unsigned int)0);
ft_printf("%#.O\n", (unsigned int)0);
printf("%#O\n", (unsigned int)0);
ft_printf("%#O\n", (unsigned int)0);
//ft_printf ("42%-60.30zi42\n", -1384289863);
//printf ("42%-60.30zi42\n", -1384289863);
//	printf("{%015p}\n", NULL);
//	printf("%.4S", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
//printf("%.0p, %.p", 0, 0);
//printf("%.5p", 0);
*/
/*printf("%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C \
%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C\
%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C",
' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
'.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
'<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
*/

	return (0);
}
