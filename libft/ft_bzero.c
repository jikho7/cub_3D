/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:48:16 by jdefayes          #+#    #+#             */
/*   Updated: 2022/11/16 18:08:09 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*int	main(int ac, char**av)
{
	(void) ac;
	(void) av;
	char str[] = "hello les gens,";
	ft_bzero(str, 5));
	return (0);
}*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*cs;

	cs = (char *)s;
	i = 0;
	while (i < n)
		cs[i++] = '\0';
}*/