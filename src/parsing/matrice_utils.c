/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:51:39 by jdefayes          #+#    #+#             */
/*   Updated: 2023/11/09 18:06:45 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	get_width(t_parse **map, t_mat *mat)
{
	t_parse	*tmp;
	int		i;

	tmp = *map;
	while (tmp->next != NULL)
	{
		i = 0;
		while (tmp->content[i])
		{
			i++;
		}
		if (mat->wid < i)
		{
			mat->wid = i;
		}
		tmp = tmp->next;
	}
}

void	get_width2(t_mat *mat)
{
	int	i;
	int	j;
	int	max;

	j = 0;
	i = 0;
	max = 0;
	while (mat->map[j][i])
	{
		i = 0;
		while (mat->map[j][i])
		{
			i++;
		}
		if (i > max)
			max = i;
		j++;
	}
	mat->wid = max - 1;
}

void	get_height(t_parse **map, t_mat *mat)
{
	t_parse	*tmp;
	int		i;

	tmp = *map;
	while (tmp->next != NULL)
	{
		strtrim_mat(*tmp, mat->check);
		i = 0;
		if (tmp->next != NULL && tmp->content[i] != '\t'
			&& tmp->content[i] != '1' && tmp->content[i] != '0')
		{
			i = 0;
			tmp = tmp->next;
		}
		else if (tmp->next != NULL && (tmp->content[i] == '1'
				|| tmp->content[i] == '0'))
		{
			mat->hei++;
			tmp = tmp->next;
		}
		else if (tmp->next != NULL && tmp->content[i] == '\n')
		tmp = tmp->next;
	}
	if (mat->hei == 0)
		error_msg(11);
}

void	strtrim_mat(t_parse info, t_check *check)
{
	t_parse	cpy;
	char	sign[1];

	sign[0] = ' ';
	cpy = info;
	cpy.content = ft_strtrim_gc(cpy.content, sign, &check->gc);
}

void	check_if_space_in_map(t_parse *lst, t_mat *mat)
{
	t_parse	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	while (mat->hei > i)
	{
		if (tmp->content[0] == '\n')
		{
			error_msg(14);
		}
		tmp = tmp->next;
		i++;
	}
}
