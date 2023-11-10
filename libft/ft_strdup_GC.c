/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_GC.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 00:48:46 by jdefayes          #+#    #+#             */
/*   Updated: 2023/11/10 00:54:45 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
/*size_t	ft_strlen(const char *s);*/

char	*ft_strdup_gc(const char *str1, t_list **gc)
{
	int		i;
	char	*copy;
	char	*s1;

	s1 = (char *)str1;
	i = -1;
	copy = my_malloc((ft_strlen(s1) + 1), sizeof(char), gc);
	if (copy == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		copy[i] = s1[i];
	copy[i] = '\0';
	return (copy);
}
