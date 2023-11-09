#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int		delete_word(char **str, int size);
static int		count_words(const char *str, char sign);
static void		write_word(char *dest, const char *from, char sign);
static int		write_split(char **tab_split, const char *str, char sign, t_list **gc);
char			**ft_split_GC(const char *str, char c, t_list **gc);

/*int main ()
{
	char str[] = "coucou, les, gens,,.";
	char sign = ' ';
	int index;
	char **result;

	result = ft_split(str, sign);
	index = 0;
	while (result[index])
	{
		printf("%s\n", result[index]);
		index++;
	}
	return 0;
}
*/

static int	delete_word(char **str, int size)
{
	while (size--)
		free(str[size]);
	return (0);
}

static int	count_words(const char *str, char sign)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == sign)
			i++;
		while (str[i] != sign && str[i] != 0)
			i++;
		if (str[i - 1] != sign)
			count++;
	}
	return (count);
}

static void	write_word(char *dest, const char *word_begin, char sign)
{
	int	i;

	i = 0;
	while (word_begin[i] != sign && word_begin[i] != '\0')
	{
		dest[i] = word_begin[i];
		i++;
	}
	dest[i] = '\0';
}

static int	write_split(char **tab_split, const char *str, char sign, t_list **gc)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == sign || str[i] == '\0')
			i++;
		else
		{
			j = 0;
			while (str[i + j] != sign && str[i + j] != '\0')
				j++;
			tab_split [word] = (char *)my_malloc((j + 1),sizeof(char), gc); //(char *)malloc(sizeof(char) * (j + 1));
			if (tab_split[word] == NULL)
				return (delete_word(tab_split, word - 1));
			write_word(tab_split[word], &str[i], sign);
			i = i + j;
			word++;
		}
	}
	return (0);
}

char	**ft_split_GC(const char *str, char c, t_list **gc)
{
	char	**tab_result;
	int		words;

	words = count_words(str, c);
	tab_result = (char **)my_malloc((words + 1), sizeof(char *), gc);//(char **)malloc(sizeof(char *) * (words + 1));
	if (tab_result == NULL)
		return (NULL);
	tab_result[words] = 0;
	write_split(tab_result, str, c, gc);
	return (tab_result);
}
