/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:49:49 by jdefayes          #+#    #+#             */
/*   Updated: 2022/11/15 16:52:51 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

// int main()
// {
// 	char str[] = "plop.";
// 	printf("%s", ft_strmapi(str, &to_lower));
// 	return(0);
// }

// static char	f(unsigned int i, char c)
// {
// 	char	str;

// 	i = 0;
// 	str = c + 2 + i;
// 	return (str);
// }

char	*ft_strmapi(char const	*s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*result;

	i = 0;
	if (s == NULL)
		return (0);
	len = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*#include <stdio.h>

char* ft_strmapi(char const* s, char (*f)(unsigned int, char));
size_t ft_strlen(const char *s);

size_t ft_strlen(const char *s)
{
	int i;

	i = 0;
	while(s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char f(unsigned int i, char c)
{
	char str;
	str = c + 1;
	return (str);
}

int main()
{
	char str1[] = "abc";
	char* str2;
	str2 = ft_strmapi(str1, *f);
	printf("%s\n", str2);
}

char* ft_strmapi(char const* s, char (*f)(unsigned int, char))
{
	size_t len;
	size_t i;
	char* str;

	i = 0;
	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}*/