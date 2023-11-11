/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:51:44 by jdefayes          #+#    #+#             */
/*   Updated: 2023/11/11 13:01:57 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	reduce_spaces_to_one(t_parse **lst, t_check *check)
{
	t_parse	*tmp;
	int		i;
	int		j;
	char	*res;
	int		size;

	tmp = *lst;
	while (tmp->next != NULL)
	{
		size = size_len(tmp->content);
		res = my_malloc(size + 1, sizeof(char), &check->gc);
		verif_malloc(res);
		i = 0;
		j = 0;
		while (tmp->content[i])
		{
			if (tmp->content[i] == ' ')
				i++;
			else if (tmp->content[i])
				res[j++] = tmp->content[i++];
		}
		tmp->content = NULL;
		tmp->content = res;
		tmp = tmp->next;
	}
}

void	remove_empty_block(t_parse **info)
{
	t_parse	*tmp;

	tmp = *info;
	if (tmp->next == NULL)
		error_msg(10);
	if (tmp)
	{
		while (tmp->content[0] == '\n')
		{
			free(tmp->content);
			tmp = tmp->next;
		}
	}
	*info = tmp;
}

void	check_spaces_nsew(t_parse **info)
{
	int		i;
	t_parse	*tmp;

	tmp = *info;
	while (tmp->next != NULL)
	{
		if (ft_strncmp(tmp->content, "EA", 2) == 0
			|| ft_strncmp(tmp->content, "NO", 2) == 0
			|| ft_strncmp(tmp->content, "SO", 2) == 0
			|| ft_strncmp(tmp->content, "WE", 2) == 0)
		{
			i = 0;
			while (tmp->content[i] != '.')
				i++;
			while (tmp->content[i])
			{
				if (tmp->content[i] == ' ')
				{
					error_msg(1);
				}
				i++;
			}
		}
		tmp = tmp->next;
	}
}

int	size_len(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		while (str[i] && str[i] != ' ')
		{
			i++;
			j++;
		}
	}
	return (j);
}

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s2)
		return (NULL);
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s2);
}
