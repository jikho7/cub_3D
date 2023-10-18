/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:49:07 by jdefayes          #+#    #+#             */
/*   Updated: 2022/11/09 13:21:32 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
/*void	ft_putchar_fd(char c, int fd);
int main(int ac, char** av)
{
	char str[] = "salut les gens.";
	ft_putendl_fd(str, 1);
	return(0);
}*/

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
	write(fd, "\n", 1);
}

/*void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}*/
