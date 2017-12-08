

#include "../libft/includes/libft.h"


int		ft_atoi_base(char *str, char *base);
char	*ft_itoa_base(int value, char *base);
char	*ft_convert_base(char *str, char *init_base, char *final_base);


int		main(void)
{
	(ft_atoi_base("1", "0123456789"));
	ft_putstr("\n");

	return (0);
}
