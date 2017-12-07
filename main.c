#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	int		i;
	char	*str;
	int		nb;
	int		size;

	i = 1;
	while (i < argc)
	{
		printf("%s", argv[i]);
		i++;
	}

	printf("LIST OF CONVERSIONS WITHOUT FLAGS, ACCURACY AND FIELD MIN SIZE \n\n");
	i = 0;
	size = 26;
	if (!(str = (char *)malloc(sizeof(char) *(size + 1))))
		return (-1);
	while (i < size)
	{
		str[i] = 'A' + i;
		i++;
	}
	str[i] = 0;
	
	printf("%d\n", printf("%d", 30));
	printf("Gestion %----+++    ### *012.034530sssans conversion avec double\\ pour echapper:\t\tSalut ca va\n");
	printf("Gestion sans conversion avec double%%:\t\t37,5%%\n");
	printf("gestion de s ac parametre str:\t\t%s\n", str);
	printf("gestion de s avec chaine statique:\t\t%s\n", "chaine statique");
//	printf("gestion de S avec parametre str:\t\t%S\n", str);
	printf("gestion de p avec adresse str:\t\t%p\n\n", &str);
	
	nb = 30;
	printf("gestion de d avec nb:%0+2d\n", nb*10);
	printf("gestion de d avec -nb:\t\t%-+d\n", -nb);
	printf("gestion de D avec -1 en dur:\t%D\n", -1);
	printf("gestion de D avec nb en dur:\t%D\n", nb);
	printf("gestion de i avec nb:\t\t%i\n", nb);
	printf("gestion de i avec -nb:\t\t%i\n", -nb);
	printf("gestion de o avec nb:\t\t%o\n", nb);
	printf("gestion de o avec -nb:\t\t%o\n", -nb);
	printf("gestion de O avec nb:\t\t%O\n", nb);
	printf("gestion de O avec -nb:\t\t%O\n", -nb);
	printf("gestion de u avec nb:\t\t%u\n", nb);
	printf("gestion de u avec -nb:\t\t%u\n", -nb);
	printf("gestion de U avec nb:\t\t%U\n", nb);
	printf("gestion de U avec -nb:\t\t%U\n", -nb);
	printf("gestion de x avec nb:\t\t%x\n", nb);
	printf("gestion de x avec -nb:\t\t%x\n", -nb);
	printf("gestion de X avec nb:\t\t%X\n", nb);
	printf("gestion de X avec -nb:\t\t%X\n", -nb);
	printf("gestion de c avec 48:\t\t%c\n", 48);
	printf("gestion de c avec -200:\t\t%c\n", -200);
	printf("gestion de C avec 48:\t\t%C\n", 48);
	printf("gestion de C avec -200:\t\t%C\n", 200);

//	printf("gestion de s avec nb:\t\t%s\n", nb);

	return (0);
}

