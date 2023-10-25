/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:48:20 by jdefayes          #+#    #+#             */
/*   Updated: 2023/10/24 19:36:36 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"

/*
int main()
{
	void *r = ft_calloc(10, 0);
   	//printf("%s", calloc(30, 1));
	return (0);
}*/
void	*ft_calloc(size_t size, size_t type)
{
	void	*ptr;

	ptr = malloc(size * type);
	if (!ptr)
		return (ptr);
	ft_bzero(ptr, type * size);
	return (ptr);
}
// void	*ft_calloc(size_t count, size_t size)
// {
// 	void			*result;

// 	result = malloc((size) * (count));
// 	if (result == NULL)
// 		return (NULL);
// 	if (size * count > 0)
// 		ft_bzero(result, (count * size));
// 	return (result);
// }
