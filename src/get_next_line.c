/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:42:12 by jdefayes          #+#    #+#             */
/*   Updated: 2023/10/18 14:05:35 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"
#include "mlx.h"

char		*get_next_line(int fd);
static char	*extraction(char *save);
static char	*conserve(char *str_to_clean);
static char	*read_n_save(int fd, char *save);

int gnl_cub(int fd)
{
	//int fd;
	char *line;
	char *matrice[200];
	int i = 0;
	printf("gnl\n");
	//open(fd, O_RDONLY);//fd = open("eg.txt", O_RDONLY);
	// if(fd == -1)
	// 	return (1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		//ft_strcpy(matrice[i],line);//printf("%s", line);
		i++;
		free (line);
	}
	i = 0;
	while (matrice[i])
	{
		printf("printf\n");
		printf("[%d]: %s\n", i, matrice[i]);
		i++;
	}
	return (0);
}

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
	while (!gnl_strchr(save) && bytes != 0) // si 0 , pas de n
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free (buf);
			free(save);		//
			save = NULL;	//
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
