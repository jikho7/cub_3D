/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_GC.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 00:48:27 by jdefayes          #+#    #+#             */
/*   Updated: 2023/11/10 00:49:39 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew_gc(void *data, t_list **gc_lst)
{
	t_list	*list;

	list = my_malloc(0, sizeof(t_list), gc_lst);
	if (!list)
		return (NULL);
	list->content = data;
	list->next = NULL;
	return (list);
}
