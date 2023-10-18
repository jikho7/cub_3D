/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:49:13 by jdefayes          #+#    #+#             */
/*   Updated: 2022/11/08 10:57:32 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

/*int main(int ac, char** av)
{
	int nb = -2147483648;
	ft_putnbr_fd(nb, 1);
	return(0);
}*/

void	ft_putnbr_fd(int n, int fd)
{
	int	number_to_print;
	int	temp;

	temp = 0;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n == 0)
			write(fd, "0", 1);
		if (n < 0)
		{
			n = (n * -1);
			write(fd, "-", 1);
		}
		if (n >= 1)
		{
			number_to_print = n % 10;
			n = n / 10;
			if (!(n < 1))
				ft_putnbr_fd(n, fd);
			temp = number_to_print + 48;
			write(fd, &temp, 1);
		}	
	}
}
