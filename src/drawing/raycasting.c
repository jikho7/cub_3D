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

void	set_ray(int i, t_ray *ray, t_data *win, t_player *you)
{
	float	delta;
	float	camX;

	camX = 2 * (double)i / win->width - 1;
	ray->rayDir.x = you->dir.x + you->plane.x * camX;
	ray->rayDir.y = -(you->dir.y - you->plane.y * camX);
	if (ray->rayDir.x >= 0.0001 || ray->rayDir.x <= -0.0001 )
	{
		ray->sqDelta.x = sqrt(win->square*win->square * (1 + (ray->rayDir.y * ray->rayDir.y) / (ray->rayDir.x * ray->rayDir.x)));
		if (ray->rayDir.x > 0)
			delta = ceilf(you->pos.x / win->square) * win->square - you->pos.x;
		else
			delta = you->pos.x - floorf(you->pos.x / win->square) * win->square;
		ray->sideDist.x = delta * sqrt((1 + (ray->rayDir.y * ray->rayDir.y) / (ray->rayDir.x * ray->rayDir.x)));
	}
	else
	{
		ray->sideDist.x = 10000000;
		ray->sqDelta.x = 100000000;
	}
	if (ray->rayDir.y >= 0.0001 || ray->rayDir.y <= -0.0001)
	{
		ray->sqDelta.y = sqrt(win->square*win->square * (1 + (ray->rayDir.x * ray->rayDir.x) / (ray->rayDir.y * ray->rayDir.y)));
		if (ray->rayDir.y > 0)
			delta = ceilf(you->pos.y / win->square) * win->square - you->pos.y;
		else
			delta = you->pos.y - floorf(you->pos.y / win->square) * win->square;
		ray->sideDist.y = delta * sqrt((1 + (ray->rayDir.x * ray->rayDir.x) / (ray->rayDir.y * ray->rayDir.y)));
	}
	else
	{
		ray->sideDist.y = 10000000;
		ray->sqDelta.y = 100000000;
	}
}

int	DDA(t_player *you, t_data *win, t_ray *ray)
{
	t_complex	Adelta;
	int			mapX;
	int			mapY;
	int			step;

	mapX = you->pos.x / win->square;
	mapY = you->pos.y / win->square;
	Adelta.x = 0;
	Adelta.y = 0;
	if (ray->sideDist.x < ray->sideDist.y)
	{
		mapX += sgn(ray->rayDir.x);
		step = 0;
		Adelta.x = ray->sqDelta.x;
	}
	else
	{
		mapY += sgn(ray->rayDir.y);
		step = 1;
		Adelta.y = ray->sqDelta.y;
	}
	while (1)
	{
		if (wall(mapX * win->square + win->square / 2, mapY * win->square + win->square / 2, win))
			break;
		if (ray->sideDist.x + Adelta.x < ray->sideDist.y + Adelta.y)
		{
			ray->sideDist.x += Adelta.x;
			step = 0;
			mapX += sgn(ray->rayDir.x);
			Adelta.x = ray->sqDelta.x;
		}
		else
		{
			ray->sideDist.y += Adelta.y;
			step = 1;
			mapY += sgn(ray->rayDir.y);
			Adelta.y = ray->sqDelta.y;
		}
	}
	return (step);
}

float	proj_dist(t_complex a, t_complex b)
{
	return ((a.x  *b.x + a.y * b.y) / sqrtf(b.x * b.x + b.y * b.y));
}

float	unfisheye(t_player *you, t_complex rayDir, float sideDist)
{
	t_complex	dist;
	float		normRay;

	normRay = sqrt(rayDir.x * rayDir.x + rayDir.y * rayDir.y);
	dist.x = rayDir.x * sideDist / normRay;
	dist.y = - rayDir.y * sideDist / normRay;
	return (fabsf(proj_dist(dist, you->dir)));
}

void init_ray(t_ray *ray, int step, t_player *you, t_data *win)
{
	float	norm;

	norm = sqrt(ray->rayDir.x * ray->rayDir.x + ray->rayDir.y * ray->rayDir.y);
	if (step == 0)
	{
		ray->distance = unfisheye(you, ray->rayDir, ray->sideDist.x);
		ray->line_loc = (remainder(you->pos.y + ray->rayDir.y *
			ray->sideDist.x / norm, win->square) + 1)/win->square;
	}
	else
	{
		ray->distance = unfisheye(you, ray->rayDir, ray->sideDist.y);
		ray->line_loc = (remainder(you->pos.x + ray->rayDir.x *
			ray->sideDist.y / norm, win->square) + 1)/win->square;
	}
}

void raycasting(t_player *you, t_data *win)
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
		step = DDA(you, win, ray);
		init_ray(ray, step, you, win);
		draw_wall(ray, i, step, win);
		i++;
	}
}
