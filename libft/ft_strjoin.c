/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:49:34 by jdefayes          #+#    #+#             */
/*   Updated: 2022/11/09 14:51:30 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
/*int main(int ac, char** av)
{

	const char str1[] = "lorem ipum dolor sit a";
	const char str2[] = ",";
	printf("%s", ft_strjoin(str1, str2));
	return(0);
}*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cs1;
	char	*cs2;
	char	*result;
	int		i;
	int		j;

	cs1 = (char *)s1;
	cs2 = (char *)s2;
	i = 0;
	j = 0;
	result = malloc(sizeof(char) * ((ft_strlen(cs1)) + (ft_strlen(cs2)) + 1));
	if (result == NULL)
		return (NULL);
	while (cs1[i])
		result[j++] = cs1[i++];
	result[j] = ' ';
	i = 0;
	while (cs2[i])
		result[j++] = cs2[i++];
	result[j] = '\0';
	return (result);
}

/*size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
*/