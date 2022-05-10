#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool	is_prime_number(int nb)
{
	int i;
	int half;

	if (nb <= 1)
		return (false);
	i = 2;
	half = nb / 2;
	while (i < half)
	{
		if (nb % i == 0)
			return (false);
		++i;
	}
	return (true);
}

size_t	strlen(const char *str)
{
	size_t len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}

char *str_rev(char *str)
{
	size_t pos;
	size_t length;
	size_t half_length;
	char character;

	if (str != NULL)
	{
		pos = 0;
		length = strlen(str);
		half_length = length / 2;
		while (pos < half_length)
		{
			character = str[pos];
			str[pos] = str[length - pos - 1];
			str[length - pos - 1] = character;
			++pos;
		}
	}
	return (str);
}

int main(void)
{
	char in[] = "Ho";
	char *str2 = in;

	printf("%s\n", str_rev(in));
	return (EXIT_SUCCESS);
}

/*

address value	sym

100     'H'    in[0] 
101     'o'    in[1]
102     '\0'   in[2]

108     100    str2

200     100    str

*/
