/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:48:24 by jdefayes          #+#    #+#             */
/*   Updated: 2022/11/01 21:27:39 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

/*int main (int ac, char** av)
{
	(void) ac;
	printf("%d", ft_isalnum(av[1]));
	printf("%d", isalnum(av[1]));
	return 0;
}*/

int	ft_isalnum(int c)
{
	if (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		|| (c >= '0' && c <= '9' ))
	{
		return (1);
	}
	else
		return (0);
}
