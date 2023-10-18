/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:50:14 by jdefayes          #+#    #+#             */
/*   Updated: 2022/11/01 19:59:41 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "libft.h"

/*int main(int ac, char** av)
{
	int letter;
	letter = ' ';
	printf("%c\n",ft_toupper(letter));
	printf("%c",toupper(letter));
	return 0;
}*/

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}
