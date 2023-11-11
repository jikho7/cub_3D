/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_GC.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 00:57:04 by jdefayes          #+#    #+#             */
/*   Updated: 2023/11/10 01:02:31 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int		ft_start(const char *s1, const char *set);
static int		ft_end(const char *s1, const char *set);

static int	ft_start(const char *s1, const char *set)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(s1);
	while (i < size)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	ft_end(const char *s1, const char *set)
{
	size_t	size;

	size = ft_strlen(s1);
	while (size > 1)
	{
		if (ft_strchr(set, s1[size - 1]) == 0)
			break ;
		size--;
	}
	return (size);
}

char	*ft_strtrim_gc(char const *s1, char const *set, t_list **gc)
{
	int		start;
	int		end;
	char	*result;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return ((char *)s1);
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	result = (char *)my_malloc((end - start + 1), sizeof (char), gc);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1 + start, end - start + 1);
	return (result);
}
