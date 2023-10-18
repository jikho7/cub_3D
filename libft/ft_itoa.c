/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:48:41 by jdefayes          #+#    #+#             */
/*   Updated: 2022/11/15 16:07:28 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int	ft_size(int nb);
/*int main(int ac, char** av)
{
	printf ("%s", ft_itoa(-2147483648));
	return (0);
}*/

char	*ft_itoa(int n)
{
	char	*dest;
	int		size;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = (ft_size(n) + 1);
	dest = malloc(sizeof(char) * size);
	if (dest == NULL)
		return (NULL);
	if (n < 0)
	{
		n = (n * -1);
		dest[size - size] = '-';
	}
	dest[size-- - 1] = '\0';
	while (n >= 1)
	{
		dest[size-- - 1] = (n % 10) + '0';
		n = n / 10;
	}
	return (dest);
}

static int	ft_size(int nb)
{
	int	size;

	size = 1;
	if (nb == 0)
		return (2);
	if (nb < 0)
	{
		size++;
		nb = nb * -1;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}
