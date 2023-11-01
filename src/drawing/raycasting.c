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

void	set_ray(int i, t_complex *rayDir, t_complex *sqDelta, t_complex *sideDist, t_data *win, t_player *you)
{
	float	delta;
	float	camX;

	camX = 2 * (double)i / win->width - 1;
	rayDir->x = you->dir.x + you->plane.x * camX;
	rayDir->y = -(you->dir.y - you->plane.y * camX);
	if (rayDir->x >= 0.0001 || rayDir->x <= -0.0001 )
	{
		sqDelta->x = sqrt(win->square*win->square * (1 + (rayDir->y * rayDir->y) / (rayDir->x * rayDir->x)));
		if (rayDir->x > 0)
			delta = ceilf(you->pos.x / win->square) * win->square - you->pos.x;
		else
			delta = you->pos.x - floorf(you->pos.x / win->square) * win->square;
		sideDist->x = delta * sqrt((1 + (rayDir->y * rayDir->y) / (rayDir->x * rayDir->x)));
	}
	else
	{
		sideDist->x = 10000000;
		sqDelta->x = 100000000;
	}
	if (rayDir->y >= 0.0001 || rayDir->y <= -0.0001)
	{
		sqDelta->y = sqrt(win->square*win->square * (1 + (rayDir->x * rayDir->x) / (rayDir->y * rayDir->y)));
		if (rayDir->y > 0)
			delta = ceilf(you->pos.y / win->square) * win->square - you->pos.y;
		else
			delta = you->pos.y - floorf(you->pos.y / win->square) * win->square;
		sideDist->y = delta * sqrt((1 + (rayDir->x * rayDir->x) / (rayDir->y * rayDir->y)));
	}
	else
	{
		sideDist->y = 10000000;
		sqDelta->y = 100000000;
	}
}

int	DDA(t_player *you, t_data *win, t_complex rayDir, t_complex sqDelta, t_complex *sideDist)
{
	t_complex	Adelta;
	int			mapX;
	int			mapY;
	int			step;

	mapX = you->pos.x / win->square;
	mapY = you->pos.y / win->square;
	Adelta.x = 0;
	Adelta.y = 0;
	if (sideDist->x < sideDist->y)
	{
		mapX += sgn(rayDir.x);
		step = 0;
		Adelta.x = sqDelta.x;
	}
	else
	{
		mapY += sgn(rayDir.y);
		step = 1;
		Adelta.y = sqDelta.y;
	}
	while (1)
	{
		if (wall(mapX * win->square + win->square / 2, mapY * win->square + win->square / 2, win))
			break;
		if (sideDist->x + Adelta.x < sideDist->y + Adelta.y)
		{
			sideDist->x += Adelta.x;
			step = 0;
			mapX += sgn(rayDir.x);
			Adelta.x = sqDelta.x;
		}
		else
		{
			sideDist->y += Adelta.y;
			step = 1;
			mapY += sgn(rayDir.y);
			Adelta.y = sqDelta.y;
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

void raycasting(t_player *you, t_data *win)
{
	t_complex	rayDir;
	t_complex	sideDist;
	t_complex	sqDelta;
	int			step;
	float		normRay;
	int			i;

	if (you->pos.x == (int)you->pos.x)
		you->pos.x += 0.0001;
	if (you->pos.y == (int)you->pos.y)
		you->pos.y += 0.0001;
	i = 0;
	while (i <= win->width)
	{
		set_ray(i, &rayDir, &sqDelta, &sideDist, win, you);
		step = DDA(you, win, rayDir, sqDelta, &sideDist);
		normRay = sqrt(rayDir.x * rayDir.x + rayDir.y * rayDir.y);
		if (step == 0)
			draw_wall(unfisheye(you, rayDir, sideDist.x), i, step, win, rayDir,
				(remainder(you->pos.y + rayDir.y * sideDist.x / normRay, win->square) + 1)/win->square);
		else
			draw_wall(unfisheye(you, rayDir, sideDist.y), i, step, win, rayDir,
				(remainder(you->pos.x + rayDir.x * sideDist.y / normRay, win->square) + 1)/win->square);
		i += 1;
	}
}
