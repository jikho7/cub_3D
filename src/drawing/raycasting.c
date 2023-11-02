/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:02:32 by mde-sepi          #+#    #+#             */
/*   Updated: 2023/10/31 19:33:58 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	infity(float *sidedist, float *sqdel)
{
	*sidedist = (float)10000000;
	*sqdel = (float)100000000;
}

void	init_dir(t_data *win, int i, t_ray *ray, t_player *you)
{
	float	camx;

	camx = 2 * (double)i / win->width - 1;
	ray->rDir.x = you->dir.x + you->plane.x * camx;
	ray->rDir.y = -(you->dir.y - you->plane.y * camx);
}

void	set_ray(int i, t_ray *ray, t_data *win, t_player *you)
{
	float	delta;

	init_dir(win, i, ray, you);
	if (ray->rDir.x >= 0.0001 || ray->rDir.x <= -0.0001)
	{
		ray->sqDel.x = sqrt(sq(win->sqr) * (1 + sq(ray->rDir.y / ray->rDir.x)));
		if (ray->rDir.x > 0)
			delta = ceilf(you->pos.x / win->sqr) * win->sqr - you->pos.x;
		else
			delta = you->pos.x - floorf(you->pos.x / win->sqr) * win->sqr;
		ray->sideDist.x = delta * sqrt(1 + sq(ray->rDir.y) / sq(ray->rDir.x));
	}
	else
		infity(&(ray->sideDist.x), &(ray->sqDel.x));
	if (ray->rDir.y >= 0.0001 || ray->rDir.y <= -0.0001)
	{
		ray->sqDel.y = sqrt(sq(win->sqr) * (1 + sq(ray->rDir.x / ray->rDir.y)));
		if (ray->rDir.y > 0)
			delta = ceilf(you->pos.y / win->sqr) * win->sqr - you->pos.y;
		else
			delta = you->pos.y - floorf(you->pos.y / win->sqr) * win->sqr;
		ray->sideDist.y = delta * sqrt(1 + sq(ray->rDir.x) / sq(ray->rDir.y));
	}
	else
		infity(&(ray->sideDist.y), &(ray->sqDel.y));
}

int	dda(t_player *you, t_data *win, t_ray *ray)
{
	t_complex	adelta;
	t_complex	map;
	int			step;

	map.x = (int)(you->pos.x / win->sqr);
	map.y = (int)(you->pos.y / win->sqr);
	step = dda_start(&adelta, ray, &map);
	while (1)
	{
		if (wall(map.x * win->sqr + win->sqr / 2, map.y * win->sqr
				+ win->sqr / 2, win))
			break ;
		step = x_or_y(ray, &adelta, &map);
	}
	return (step);
}

void	raycasting(t_player *you, t_data *win)
{
	int			step;
	int			i;
	t_ray		*ray;

	ray = win->ray;
	if (you->pos.x == (int)you->pos.x)
		you->pos.x += 0.0001;
	if (you->pos.y == (int)you->pos.y)
		you->pos.y += 0.0001;
	i = 0;
	while (i <= win->width)
	{
		set_ray(i, ray, win, you);
		step = dda(you, win, ray);
		init_ray(ray, step, you, win);
		draw_wall(ray, i, step, win);
		i++;
	}
}
