/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:49:53 by jdefayes          #+#    #+#             */
/*   Updated: 2022/11/09 14:51:53 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

// \200 necessite un unsigned char, d'ou le cast dans le return.

/*int main()
{	char test1[] ="\200";
	char test2[] ="\0";

	char test3[] ="zzzdd e z drt78456v7y bzdgdsgzzz";
	char test4[] ="sjkfh";

	char test5[] ="sfjv tew khs hfbdg";
	char test6[] ="zzzzfsfsdgd";

	char test7[] ="";
	char test8[] ="hjfgxu";

	char test9[] = " . sdhsd s dyw ";
	char test10[] = "";
	unsigned int n;

	n = 7;
	printf("%d\n", ft_strncmp(test1, test2, n));
	printf("%d\n", strncmp(test1, test2, n));
	printf("%d\n", ft_strncmp(test3, test4, n));
	printf("%d\n", strncmp(test3, test4, n));

	printf("%d\n", ft_strncmp(test5, test6, n));
	printf("%d\n", strncmp(test5, test6, n));

	printf("%d\n", ft_strncmp(test7, test8, n));
	printf("%d\n", strncmp(test7, test8, n));

	printf("%d\n", ft_strncmp(test9, test10, n));
	printf("%d\n", strncmp(test9, test10, n));
	return (0);
}*/