#include <stdio.h>
#include "ft_printf.h"
#include <locale.h>
#include <wchar.h>

int		main()
{
	setlocale(LC_ALL, "");
	int		i;

//	printf("%-44C\n", (wchar_t)(321));
//	i = printf("42%34S42",L"こんにちは、私はprintf単体テストです");
//	ft_putnbr(i);
	ft_putstr("\n");

	i = printf("%");
	ft_putnbr(i);

	return (0);
}
