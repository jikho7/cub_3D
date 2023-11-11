/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:50:42 by jdefayes          #+#    #+#             */
/*   Updated: 2023/11/09 19:28:39 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	is_coordinate_valid(t_parse *tmp);

void	check_excess_info(t_parse **info)
{
	t_parse	*tmp;

	tmp = *info;
	while (tmp->next != NULL)
	{
		if (is_coordinate_valid(tmp) == 1)
			tmp = tmp->next;
		else
			error_msg(5);
	}
}

static int	is_coordinate_valid(t_parse *tmp)
{
	if (ft_strncmp(tmp->content, "EA ./", 5) == 0
		|| ft_strncmp(tmp->content, "EA", 2) == 0)
		return (1);
	else if (ft_strncmp(tmp->content, "NO ./", 5) == 0
		|| ft_strncmp(tmp->content, "NO", 2) == 0)
		return (1);
	else if (ft_strncmp(tmp->content, "SO ./", 5) == 0
		|| ft_strncmp(tmp->content, "SO", 2) == 0)
		return (1);
	else if (ft_strncmp(tmp->content, "WE ./", 5) == 0
		|| ft_strncmp(tmp->content, "WE", 2) == 0)
		return (1);
	else if (ft_strncmp(tmp->content, "F ./", 2) == 0
		|| ft_strncmp(tmp->content, "F", 1) == 0)
		return (1);
	else if (ft_strncmp(tmp->content, "C ", 2) == 0)
		return (1);
	else if (tmp->content[0] == '\n' || tmp->content[1] == '\0')
		return (1);
	else if (ft_strncmp(tmp->content, "1", 1) == 0
		|| ft_strncmp(tmp->content, "0", 1) == 0)
		return (1);
	return (0);
}

void	check_if_info_after_map(t_parse **info, t_check *check)
{
	t_parse	*tmp;

	tmp = *info;
	while (tmp->next != NULL)
	{
		while (tmp->content[0] != '1' && tmp->content[0] != '0')
		{
			if (check->is_map == 1)
				error_msg(6);
			tmp = tmp->next;
		}
		while (tmp->next != NULL && (tmp->content[0] == '1'
				|| tmp->content[0] == '0' || tmp->content[0] == '\n'))
		{
			check->is_map = 1;
			tmp = tmp->next;
		}
	}
}

void	check_tex_extension(t_parse **info, t_check *check)
{
	t_parse		*tmp;
	int			size;
	const char	*cpy;

	(void)check;
	tmp = *info;
	while (tmp->next != NULL)
	{
		size = ft_strlen(tmp->content);
		cpy = (tmp->content + (size - 5));
		if ((ft_strncmp(tmp->content, "EA", 2) == 0
				|| ft_strncmp(tmp->content, "NO", 2) == 0
				|| ft_strncmp(tmp->content, "SO", 2) == 0
				|| ft_strncmp(tmp->content, "WE", 2) == 0))
		{
			if (ft_strncmp(cpy, ".xpm", 4) != 0
				&& (ft_strncmp(cpy, ".png", 4) != 0))
				error_msg(3);
		}
		tmp = tmp->next;
	}
}

void	check_map_extension(char *map_name)
{
	int			size;
	const char	*cpy;

	size = ft_strlen(map_name);
	cpy = (map_name + (size - 4));
	if (ft_strncmp(cpy, ".cub", 4) != 0)
		error_msg(2);
	if (map_name[size - 5] == '/' || map_name[size - 5] == '.')
		error_msg(2);
}
