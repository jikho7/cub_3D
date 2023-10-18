/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:48:44 by jdefayes          #+#    #+#             */
/*   Updated: 2022/11/15 16:39:13 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

/*
This function searches for the first occurrence of a character ch in the
n bytes of characters in the block of memory pointed by str.
*/

/*int main(int ac, char** av)
{
	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	//printf("%s", (char *)ft_memchr(tab, -1, 7));
	//unsigned char string[]= "bonjourno";
	int letter; // int c, using the unsigned char conversion 
	int where;  // n − This is the number of bytes to be analyzed.
	where = 7;
	letter = -1;
	printf("%s\n", ft_memchr(tab, letter, where));
	printf("%s", memchr(tab, letter, where));
	return 0;
}*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cs;
	size_t			i;

	cs = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (cs[i] == (unsigned char)c)
			return (&cs[i]);
		i++;
	}
	return (0);
}
