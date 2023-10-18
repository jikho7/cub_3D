/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:34:43 by jdefayes          #+#    #+#             */
/*   Updated: 2022/11/21 12:46:57 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

/*int main(int ac, char** av)
{
	char string[]= "contente."; // 10 avec 0
	int letter = 'z'; // reponse different avec '\0'
	printf("%s\n", ft_strrchr(string, letter));
	printf("%s", strrchr(string, letter));
	return 0;
}*/

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		size;
	char	cc;

	cc = (char)c;
	str = (char *)s;
	size = ft_strlen(str);
	while (size > 0 && str[size] != cc)
	size--;
	if (str[size] == cc)
		return (&str[size]);
	else
		return (0);
}
