/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:02:32 by mde-sepi          #+#    #+#             */
/*   Updated: 2023/11/10 13:36:06 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_texture(t_data *win, int x, int sky, t_ray *ray)
{
	int		j;
	float	jump;
	int		color;
	int		x_dep;
	int		y_dep;

	j = max(0, sky);
	jump = (float)win->tex[ray->nwse].height / (float)(win->height - 2 * sky);
	x_dep = (int)(ray->line_loc * win->tex[ray->nwse].height)
		* (win->tex[ray->nwse].bpp / 8);
	while (j < win->height - sky && j < win->height)
	{
		y_dep = (int)((float)(j - sky) *jump) *win->tex[ray->nwse].line_len;
		color = *(unsigned int *)(win->tex[ray->nwse].addr + (x_dep + y_dep));
		my_mlx_pixel_put(win, x, j, max(0, color));
		j++;
	}
	my_mlx_pixel_put(win, x, j, max(0, color));
}

void	pretty_or_legal(t_data *win, int i, int j)
{
	int	clr;

	clr = 255 * ((rand() % 4900) / 4899);
	if (win->c == 1)
	{
		my_mlx_pixel_put(win, i, j, trgb(1, clr, clr, clr));
		my_mlx_pixel_put(win, i, win->height - j, trgb(1, 0, rand() % 50, 0));
	}
	else
	{
		my_mlx_pixel_put(win, i, j, trgb(1, win->map->C[0],
				win->map->C[1], win->map->C[2]));
		my_mlx_pixel_put(win, i, win->height - j, trgb(1, win->map->F[0],
				win->map->F[1], win->map->F[2]));
	}
}

void	draw_wall(t_ray *ray, int i, int udorlr, t_data *win)
{
	int	j;
	int	sky;

	sky = win->height * (ray->distance - win->sqr / 2) / (2 * ray->distance);
	j = 0;
	ray->nwse = udorlr + (udorlr * sgn(ray->rdir.y) + (1 - udorlr)
			* sgn(ray->rdir.x) + 1);
	while (j <= win->height / 2)
	{
		if (j < sky)
			pretty_or_legal(win, i, j);
		else
		{
			draw_texture(win, i, sky, ray);
			break ;
		}
		j++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (data == NULL)
		return ;
	if (data->addr == NULL)
		return ;
	if (x < 0 || x >= data->width || y < 0 || y >= data->height)
		return ;
	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	trgb(int t, int red, int green, int blue)
{
	return (t << 24 | red << 16 | green << 8 | blue);
}
