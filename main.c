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
	format = "\n";
//ft_printf("%#.3O\n", 0);
//printf("%-50.2zi\n", 0);
	printf("%C\n", 0);
	ft_printf("%C\n", 0);

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
