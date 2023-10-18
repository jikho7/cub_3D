/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:48:47 by jdefayes          #+#    #+#             */
/*   Updated: 2022/11/15 16:39:35 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

/*
This function compares the first n characters of the memory block pointed
by str1 and str2.
*/

/*int	main(int ac, char** av)
{
	char	str1[] = "t\200";
	char	str2[] = "t\0";
	int		how_many;
	
	how_many = 2;
	printf("%d\n", ft_memcmp(str1, str2, how_many));
	printf("%d", memcmp(str1, str2, how_many));
	return 0;
}*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}
