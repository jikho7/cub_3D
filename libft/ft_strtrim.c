/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:53:20 by jdefayes          #+#    #+#             */
/*   Updated: 2022/11/15 16:53:56 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int			ft_start(const char *s1, const char *set);
static int			ft_end(const char *s1, const char *set);
//char *copy_result(const char *str, char *dest, int size, int index);

/*int main()
{
  char str[] = ",,./,./,dskgj,,sgijdgio,.,/,,";
  char sign[] = {',', '.', '/'};
  printf("%s", ft_strtrim(str, sign));
  return(0);
}*/

/*int ft_begin (const char *str, const char *set)
{
	int i;
	char *cset;
	char *cstr;

	i = 0;
	cset = (char*)set;
	cstr = (char*)str;
	while(cstr[i])
	{
	while(cstr[i])
	{
		j = 0;
		while(cset[j])
		{
			while(cstr[i] == cset[j])
				i++;
			j++;
		}
	}
	i++;
	}
	return(i);
}
// ..,,//..,,hgfh,,..//
int ft_endd (const char *str, const char *set)
{
	int i;
	char *cset;
	char *cstr;
	int size; 

	i = 0;
	cset = (char*)set;
	cstr = (char*)str;
	size = strlen(str);
	while(cstr[size - 1] != 0 && cstr[size - 1] == cset)
		size--;
	return((size));
}*/
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

char	*ft_strtrim(char const *s1, char const *set)
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
	result = (char *)malloc(sizeof(char) * (end - start + 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1 + start, end - start + 1);
	return (result);
}

/*char		*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*result;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return ((char*)s1);
	start = ft_begin(s1, set);
	end = ft_endd(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	result = (char *)malloc(sizeof(char) * (end - start + 1));
	if (result == NULL)
		return (NULL);
	result = copy_result(s1, result, end - 1, start);
	//ft_strlcpy(result, s1 + start, end - start + 1);
	return (result);
}

char *copy_result(const char *str, char *dest, int size, int index)
{
    char *cstr;
    int j;

    j = 0;
    cstr = (char*)str; 
    while(cstr[index] && size > 1)
    {
        dest[j] = cstr[index];
        size--;
        j++;
        index++;
    }
    dest[j] = 0;
    return(dest);
}*/
