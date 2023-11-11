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

float	unfisheye(t_player *you, t_complex rdir, float sidedist)
{
	t_complex	dist;
	float		normray;

	normray = sqrt(rdir.x * rdir.x + rdir.y * rdir.y);
	dist.x = rdir.x * sidedist / normray;
	dist.y = -rdir.y * sidedist / normray;
	return (fabsf(proj_dist(dist, you->dir)));
}

void	init_ray(t_ray *ray, int step, t_player *you, t_data *win)
{
	float	norm;

	norm = sqrt(ray->rdir.x * ray->rdir.x + ray->rdir.y * ray->rdir.y);
	if (step == 0)
	{
		ray->distance = unfisheye(you, ray->rdir, ray->sidedist.x);
		ray->line_loc = (remainder(you->pos.y + ray->rdir.y
					* ray->sidedist.x / norm, win->sqr) + 1) / win->sqr;
	}
	else
	{
		ray->distance = unfisheye(you, ray->rdir, ray->sidedist.y);
		ray->line_loc = (remainder(you->pos.x + ray->rdir.x
					* ray->sidedist.y / norm, win->sqr) + 1) / win->sqr;
	}
	if (ray->line_loc < 0)
		ray->line_loc += 1;
}

int	dda_start(t_complex *adelta, t_ray *ray, t_complex *map)
{
	adelta->x = 0;
	adelta->y = 0;
	if (ray->sidedist.x < ray->sidedist.y)
	{
		map->x += sgn(ray->rdir.x);
		adelta->x = ray->sqdel.x;
		return (0);
	}
	else
	{
		map->y += sgn(ray->rdir.y);
		adelta->y = ray->sqdel.y;
		return (1);
	}
}

int	x_or_y(t_ray *ray, t_complex *adelta, t_complex *map)
{
	if (ray->sidedist.x + adelta->x < ray->sidedist.y + adelta->y)
	{
		ray->sidedist.x += adelta->x;
		map->x += sgn(ray->rdir.x);
		adelta->x = ray->sqdel.x;
		return (0);
	}
	else
	{
		ray->sidedist.y += adelta->y;
		map->y += sgn(ray->rdir.y);
		adelta->y = ray->sqdel.y;
		return (1);
	}
}
