/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:49:38 by jdefayes          #+#    #+#             */
/*   Updated: 2022/11/16 16:27:09 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"

/*int main(int ac, char** av)
{
	char src[] = "lorem ipsum dolor sit amet";
    char dest[10] = "a";
    printf("%lu", ft_strlcat(dest, src, 1));
    write(1, dest, 15);
	return (0);
}


size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	while (dst[i] != '\0' && i < n)
		i++;
	j = i;
	while (src[i - j] != '\0' && i < n - 1)
	{
		dst[i] = src[i - j];
		i++;
	}
	if ( j < n)
		dst[i] = '\0';
	return (j + ft_strlen(src));
}*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	result;

	i = 0;
	j = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	else if (dstsize < ft_strlen(dst))
		result = ft_strlen(src) + dstsize;
	else
		result = ft_strlen(src) + ft_strlen(dst);
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0' && i < (dstsize - 1))
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (result);
}
