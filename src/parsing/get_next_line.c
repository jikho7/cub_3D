/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:51:26 by jdefayes          #+#    #+#             */
/*   Updated: 2023/11/11 16:46:53 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char		*get_next_line(int fd);
static char	*extraction(char *save);
static char	*conserve(char *str_to_clean);
static char	*read_n_save(int fd, char *save);

char	*get_next_line(int fd)
{
	static char	*save;
	char		*new_line;

	save = read_n_save(fd, save);
	if (!save)
		return (NULL);
	new_line = extraction(save);
	save = conserve(save);
	return (new_line);
}

static char	*read_n_save(int fd, char *save)
{
	char	*buf;
	int		bytes;

	bytes = 1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	while (!gnl_strchr(save) && bytes != 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free (buf);
			free(save);
			save = NULL;
			return (NULL);
		}
	buf[bytes] = '\0';
	save = gnl_strjoin(save, buf);
	}
	free (buf);
	return (save);
}

static char	*extraction(char *save)
{
	int		i;
	char	*result;

	i = 0;
	if (!save[i])
		return (NULL);
	result = malloc((gnl_strlen(save) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (save[i] && save[i] != '\n')
	{
		result[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		result[i++] = '\n';
	result[i] = '\0';
	return (result);
}

static char	*conserve(char *str_to_clean)
{
	int		i;
	int		j;
	char	*to_conserve;

	i = 0;
	j = 0;
	while (str_to_clean[i] && str_to_clean[i] != '\n')
		i++;
	if (str_to_clean[i] == '\0')
	{
		free(str_to_clean);
		return (NULL);
	}
	i++;
	to_conserve = malloc(((gnl_strlen(str_to_clean)) - i + 1) * sizeof(char));
	if (to_conserve == NULL)
		return (NULL);
	while (str_to_clean[i])
		to_conserve[j++] = str_to_clean[i++];
	to_conserve[j] = '\0';
	free(str_to_clean);
	return (to_conserve);
}
