/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:48:55 by jdefayes          #+#    #+#             */
/*   Updated: 2022/11/15 16:47:10 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

/*
Copies n characters from str2 to str1, but for overlapping memory blocks,
memmove() is a safer approach than memcpy().
*/

/*int main()
{
	char str[] = "0";
	char dst[100];
	ft_memmove(dst, str, 7);
	return(0);
}*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*csrc;
	char	*cdst;

	i = 0;
	if (dst == 0 && src == 0)
		return (NULL);
	csrc = (char *)src;
	cdst = (char *)dst;
	if (cdst > csrc)
	{
		while (len > i)
		{
			cdst[len - 1] = csrc[len - 1];
			len--;
		}
	}
	while (i < len)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return (cdst);
}
