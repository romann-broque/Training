/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_words.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:19:52 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/09 16:31:32 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}

char	*get_reverse_word(const char *word,)
{
	char	*reverse_word;

	reverse_word = (char *)malloc((sizeof));
}

char	*reverse_words(const char *text)
{
	char	*reverse_text;

	if (text == NULL)
		return (NULL);
	reverse_text = (char *)malloc((ft_strlen(text) + 1) *sizeof(char));
	if (reverse_text != NULL)
	{
		
	}
	return (reverse_txt);
}

int	main(int ac, char **av)
{
	printf("%s --> %s\n", av[1], reverse_words(av[1]));
	return (EXIT_SUCCESS);
}
