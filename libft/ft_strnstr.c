/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:49:57 by jdefayes          #+#    #+#             */
/*   Updated: 2022/11/21 12:46:30 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

/*int main(int ac, char** av)
{
	char string[] = "lorem ipsum dolor sit amet";
	char word[] = "dolor";
	int how_many;

	how_many = 15;
	printf("%s\n", ft_strnstr(string, word, how_many));
	printf("%s", strnstr(string, word, how_many));
	return 0;
}*/

/*char	*ft_strnstr(const char *hay, const char *nee, size_t len)
{
	size_t	i;
	size_t		j;
	//char	*nee;
	char	*hay2;
	size_t		size_needle;

	//nee = (char *)nee;
	hay2 = (char *)hay;
	size_needle = ft_strlen(nee);
	i = 0;
	if (nee[i] == '\0')
		return (hay2);
	if (len < size_needle)
		return (NULL);
	while (hay2[i])
	{
		j = 0;
		while (hay2[i] == nee[j] && i < len)
		{
			if (j == size_needle - 1)
				return (&hay2[i - j]);
			i++;
			j++;
		}
		i++;
	}
	return (NULL);
}*/
char	*ft_strnstr(const char *hay, const char *nee, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hay2;
	size_t	size_needle;

	hay2 = (char *)hay;
	size_needle = ft_strlen(nee);
	i = 0;
	if (nee[i] == '\0')
		return (hay2);
	while (hay2[i] && i < len)
	{
		j = 0;
		while ((hay2[i + j] == nee[j]) && (i + j < len))
		{
			if (j == size_needle - 1)
				return (&hay2[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
