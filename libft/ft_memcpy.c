/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:48:50 by jdefayes          #+#    #+#             */
/*   Updated: 2022/11/15 16:39:46 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*csrc;
	char		*cdst;

	i = 0;
	if (dst == 0 && src == 0)
		return (NULL);
	csrc = (char *)src;
	cdst = (char *)dst;
	while (i < n)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return (cdst);
}
/*
The memcpy() function copies n bytes from memory area src to memory area
dst.  If dst and src overlap, behavior is undefined.  Applications in
which dst and src might overlap should use memmove(3) instead.
*/

/*int main(int ac, char** av)
{
	unsigned char source[]= "zy\0xw\0vu\0\0tsr";
	unsigned char destination [100];
	printf("%s\n", memcpy(destination, source, 11));
	printf("%s", ft_memcpy(destination, source, 11));
	return 0;
}*/
