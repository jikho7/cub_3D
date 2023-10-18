/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:49:24 by jdefayes          #+#    #+#             */
/*   Updated: 2022/11/15 16:51:45 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

/*
Cette fonction recherche la première occurrence du caractère passé en second
paramètre dans la chaîne de caractères spécifiée via le premier paramètre.
*/

/*int main(int ac, char** av)
{
	char string[]= "bonjour";
	int letter = '\0'; // reponse different avec '\0'
	printf("%s\n", ft_strchr(string, letter));
	printf("%s", strchr(string, letter));
	return 0;
}*/

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	cc;

	str = (char *)s;
	cc = (char)c;
	i = 0;
	while (str[i] != '\0' && str[i] != cc)
		i++;
	if (str[i] == cc)
		return (&str[i]);
	return (0);
}
