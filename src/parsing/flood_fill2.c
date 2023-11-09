/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:51:21 by jdefayes          #+#    #+#             */
/*   Updated: 2023/11/10 00:30:56 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_up(t_mat *mat, int pos_y, int pos_x);
int	check_directions(t_mat *mat, int pos_y, int pos_x);
int	check_left(t_mat *mat, int pos_y, int pos_x);
int	check_right(t_mat *mat, int pos_y, int pos_x);
int	check_down(t_mat *mat, int pos_y, int pos_x);

int	check_directions(t_mat *mat, int pos_y, int pos_x)
{
	if (check_left(mat, pos_y, pos_x) == 1)
	{
		error_msg(9);
	}
	if (check_right(mat, pos_y, pos_x) == 1)
	{
		error_msg(9);
	}
	if (check_up(mat, pos_y, pos_x) == 1)
	{
		error_msg(9);
	}
	if (check_down(mat, pos_y, pos_x) == 1)
	{
		error_msg(9);
	}
	return (0);
}

int	check_left(t_mat *mat, int pos_y, int pos_x)
{
	while (pos_x >= 0)
	{
		if (mat->map_space[pos_y][pos_x] == '1')
		{
			return (0);
		}
		if (mat->map_space[pos_y][pos_x] == ' ')
			return (1);
		pos_x--;
	}
	return (1);
}

int	check_right(t_mat *mat, int pos_y, int pos_x)
{
	while (pos_x < mat->wid)
	{
		if (mat->map_space[pos_y][pos_x] == '1')
		{
			return (0);
		}
		if (mat->map_space[pos_y][pos_x] == ' ')
		{
			return (1);
		}
		pos_x++;
	}
	return (1);
}

int	check_up(t_mat *mat, int pos_y, int pos_x)
{
	while (pos_y >= 0)
	{
		if (mat->map_space[pos_y][pos_x] == '1')
		{
			return (0);
		}
		if (mat->map_space[pos_y][pos_x] == ' ')
			return (1);
		pos_y--;
	}
	return (1);
}

int	check_down(t_mat *mat, int pos_y, int pos_x)
{
	while (pos_y < mat->hei)
	{
		if (mat->map_space[pos_y][pos_x] == '1')
		{
			return (0);
		}
		if (mat->map_space[pos_y][pos_x] == ' ')
			return (1);
		pos_y++;
	}
	return (1);
}
