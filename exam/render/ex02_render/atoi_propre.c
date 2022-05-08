#include <stdio.h>
#include <stdlib.h>

#define ZERO_ASCII_SHIFT	48

int	ft_atoi(const char *str)
{
	size_t	i;
	int		nb;
	
	nb = 0;
	i = 0;
	while ((*str > 8 && *str < 13) || *str == ' ')
		++str;
	if (str[0] == '+' || str[0] == '-')
		++i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - ZERO_ASCII_SHIFT);
		++i;
	}
	return str[0] == '-' ? -nb : nb;
}

int main(int ac, char **av)
{
	if (ac > 1)
		printf("%d\n", ft_atoi(av[1]));
	return EXIT_SUCCESS;
}
