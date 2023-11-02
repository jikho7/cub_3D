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

float	proj_dist(t_complex a, t_complex b)
{
	return ((a.x * b.x + a.y * b.y) / sqrtf(b.x * b.x + b.y * b.y));
}

float	unfisheye(t_player *you, t_complex rDir, float sideDist)
{
	t_complex	dist;
	float		normray;

	normray = sqrt(rDir.x * rDir.x + rDir.y * rDir.y);
	dist.x = rDir.x * sideDist / normray;
	dist.y = -rDir.y * sideDist / normray;
	return (fabsf(proj_dist(dist, you->dir)));
}

void	init_ray(t_ray *ray, int step, t_player *you, t_data *win)
{
	float	norm;

	norm = sqrt(ray->rDir.x * ray->rDir.x + ray->rDir.y * ray->rDir.y);
	if (step == 0)
	{
		ray->distance = unfisheye(you, ray->rDir, ray->sideDist.x);
		ray->line_loc = (remainder(you->pos.y + ray->rDir.y
					* ray->sideDist.x / norm, win->sqr) + 1) / win->sqr;
	}
	else
	{
		ray->distance = unfisheye(you, ray->rDir, ray->sideDist.y);
		ray->line_loc = (remainder(you->pos.x + ray->rDir.x
					* ray->sideDist.y / norm, win->sqr) + 1) / win->sqr;
	}
}

int	dda_start(t_complex *adelta, t_ray *ray, t_complex *map)
{
	adelta->x = 0;
	adelta->y = 0;
	if (ray->sideDist.x < ray->sideDist.y)
	{
		map->x += sgn(ray->rDir.x);
		adelta->x = ray->sqDel.x;
		return (0);
	}
	else
	{
		map->y += sgn(ray->rDir.y);
		adelta->y = ray->sqDel.y;
		return (1);
	}
}

int	x_or_y(t_ray *ray, t_complex *adelta, t_complex *map)
{
	if (ray->sideDist.x + adelta->x < ray->sideDist.y + adelta->y)
	{
		ray->sideDist.x += adelta->x;
		map->x += sgn(ray->rDir.x);
		adelta->x = ray->sqDel.x;
		return (0);
	}
	else
	{
		ray->sideDist.y += adelta->y;
		map->y += sgn(ray->rDir.y);
		adelta->y = ray->sqDel.y;
		return (1);
	}
}
