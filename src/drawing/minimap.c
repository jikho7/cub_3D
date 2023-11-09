/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:02:32 by mde-sepi          #+#    #+#             */
/*   Updated: 2023/11/10 00:18:59 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	circle(int i, int j, t_player *you)
{
	float	x;
	float	y;

	x = i - you->pos.x;
	y = j - you->pos.y;
	if ((x * x + y * y) <= 25)
		return (1);
	return (0);
}

int	wall(int i, int j, t_data *win)
{
	if (win->map->map[j / win->sqr][i / win->sqr] == '1')
		return (1);
	return (0);
}

int	cancle(float posX, float posY, t_data *win)
{
	if (win->map->map[(int)posY / win->sqr][(int)posX / win->sqr] == '1')
		return (1);
	return (0);
}

void	minimap(t_data *win, t_player *you, int i, t_complex shift)
{
	int	j;

	j = 0;
	while (j < min(win->width, win->map->hei * win->sqr))
	{
		if (circle(i + (int)shift.x, j + shift.y, you))
			my_mlx_pixel_put(win, i, j, trgb(1, 0, 255, 0));
		else if (wall(i + (int)shift.x, j + shift.y, win))
			my_mlx_pixel_put(win, i, j, trgb(1, 0, 0, 255));
		else
			my_mlx_pixel_put(win, i, j, trgb(1, 0, 0, 0));
		if ((i + (int)shift.x) % win->sqr == 0
			|| (j + (int)shift.y) % win->sqr == 0)
			my_mlx_pixel_put(win, i, j, trgb(1, 100, 100, 100));
		j++;
	}
	while (j < win->height)
	{
		my_mlx_pixel_put(win, i, j, 0);
		j++;
	}
}

void	character(t_data *win, t_player *you)
{
	int			i;
	int			j;
	t_complex	shift;

	i = -1;
	shift.x = max(0, you->pos.x - win->width / 2);
	shift.y = min(max(0, win->map->hei * win->sqr - win->height),
			max(0, you->pos.y - win->height / 2));
	if (win->minimap == 1)
	{
		while (i++ < min(win->width, win->map->wid * win->sqr))
			minimap(win, you, i, shift);
		while (i < win->width)
		{
			j = -1;
			while (j++ < win->height)
				my_mlx_pixel_put(win, i, j, 0);
			i++;
		}
	}
	else
		raycasting(you, win);
}
