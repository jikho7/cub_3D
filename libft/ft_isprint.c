/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:48:37 by jdefayes          #+#    #+#             */
/*   Updated: 2022/11/08 19:39:53 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

/*int main (int ac, char** av)
{
	(void) ac;
	printf("%d", ft_isprint(av[1]));
	printf("%o", ft_isprint(av[1]));
	printf("%d", isprint(av[1]));
	printf("%o", isprint(av[1]));
	return 0;
}*/

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
