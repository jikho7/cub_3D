/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:50:07 by jdefayes          #+#    #+#             */
/*   Updated: 2022/11/15 16:54:31 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

/*
The SUBSTR( ) function returns characters from the string value starting at
the character position specified by start. The number of characters returned
is specified by length.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (0);
	ft_memmove(result, s + start, len);
	result[len] = '\0';
	return (result);
}
