/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:49:28 by jdefayes          #+#    #+#             */
/*   Updated: 2022/11/15 16:52:00 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
/*size_t	ft_strlen(const char *s);*/

char	*ft_strdup(const char *str1)
{
	int		i;
	char	*copy;
	char	*s1;

	s1 = (char *)str1;
	i = -1;
	copy = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (copy == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		copy[i] = s1[i];
	copy[i] = '\0';
	return (copy);
}

/*int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	char sent[] = "lorem ipsum dolor sit amet";
	printf("%s\n", ft_strdup(sent));
	printf("%s", strdup(sent)); 
	return (0);
}
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}*/