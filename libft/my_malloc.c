/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 01:00:20 by jdefayes          #+#    #+#             */
/*   Updated: 2023/11/10 01:00:25 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "libft.h"

void	*my_malloc(size_t size, size_t type, t_list **gc)
{
	void	*ptr;
	t_list	*new;

	ptr = ft_calloc(size, type);
	if (!ptr)
		return (NULL);
	new = ft_calloc(1, sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = ptr;
	ft_lstadd_back(gc, new);
	return (ptr);
}
