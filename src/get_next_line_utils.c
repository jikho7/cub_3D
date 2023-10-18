# include <cub3d.h>

char	*gnl_strchr(char *s);
size_t	gnl_strlen(char *s);
char	*gnl_strjoin(char *s1, char *s2);

size_t	gnl_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)								// si s1 pas initialise
	{
		s1 = malloc(sizeof(char) * 1);		// init
		s1[0] = '\0';						//
	}
	result = malloc((sizeof(char)) * (gnl_strlen(s1)) + (gnl_strlen(s2) + 1));
	if (result == NULL)
		return (NULL);
	while (s1[i])
		result[j++] = s1[i++];
	i = 0;
	while (s2[i])
		result[j++] = s2[i++];
	result[j] = '\0';
	free(s1);			// on free l ancien free pour laisser la place a save = gnl_strjoin(save, buf);
	return (result);
}

char	*gnl_strchr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (&s[i]);
	return (0);
}
