/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:48:27 by jdefayes          #+#    #+#             */
/*   Updated: 2022/11/01 21:27:42 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

/*int main (int ac, char** av)
{
	(void) ac;
	printf("%d", ft_isalpha(av[1]));
	printf("%d", isalpha(av[1]));
	return 0;
}*/

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	else
		return (0);
}
