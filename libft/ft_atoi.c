/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:48:09 by jdefayes          #+#    #+#             */
/*   Updated: 2022/11/15 16:03:05 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

/*int	main()
{
	char test1[] = "+-54";
	char test2[] = "-+48";
	char test3[] = "--47";
	char test4[] = "++47";
	char test5[] = "-2147483648";
	char test6[] = "-0";

	 printf("%d\n", ft_atoi(test1));
	 printf("%d\n", atoi(test1));
		printf("%d\n", ft_atoi(test2));
			printf("%d\n", atoi(test2));
		printf("%d\n", ft_atoi(test3));
		printf("%d\n", atoi(test3));
		printf("%d\n", ft_atoi(test4));
		printf("%d\n", atoi(test4));
		printf("%d\n", ft_atoi(test5));
		printf("%d\n", atoi(test5));
		printf("%d\n", ft_atoi(test6));
		printf("%d\n", atoi(test6));
	return (0);
}*/

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	minus;

	result = 0;
	sign = 0;
	minus = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+' || *str == 32)
	{
		if (*str == '-')
			minus++;
		sign++;
		str++;
	}
	if (sign > 1 || minus > 1)
		return (0);
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + *(str++) - '0';
	if (result == -2147483648)
		return (-2147483648);
	if (minus == 1)
		result = result * -1;
	return (result);
}

/*int ft_atoi(const char *str)
{
    unsigned int    result;
    int minus;

    result = 0;
    minus = 1;
    while (*str == 32 || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-' || *str == '+')
        if (*(str++) == '-')
            minus *= -1;
    while (*str >= '0' && *str <= '9')
        result = (result * 10) + *(str++) - '0';
    return ((int)result * minus);
}*/