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

void	draw_texture(t_data *win, int x, int sky, float line_loc, int NWSE)
{
	int		j;
	float	jump;
	int		color;
	int		x_dep;
	int		y_dep;

	j = max(0, sky);
	jump = (float)win->tex[NWSE].height / (float)(win->height - 2 * sky);
	x_dep = (int)(line_loc * win->tex[NWSE].height) * (win->tex[NWSE].bpp / 8);
	while (j < win->height - sky)
	{
		y_dep = (int)((float)(j - sky) * jump) * win->tex[NWSE].line_len;
		color = *(unsigned int *)(win->tex[NWSE].addr + (x_dep + y_dep));
		my_mlx_pixel_put(win, x, j, max(0, color));
		j++;
	}
	my_mlx_pixel_put(win, x, j, max(0, color));
}

/*(udorlr ; uord_lorr): (1;1) = N = , (1,-1) = S, (0,1) = W , (0, -1) = E*/
void	draw_wall(float distance, int i, int udorlr, t_data *win, t_complex raydir, float line_loc)
{
	int	j;
	int	sky;
	int	uord_lorr;
	int	clr;

	sky = win->height * (distance - win->square / 2) / (2 * distance);
	uord_lorr = (udorlr) * sgn(raydir.y) + (1 - udorlr) * sgn(raydir.x);
	j = 0;
	while (j <= win->height / 2)
	{
		if (j < sky)
		{
			clr = 255 * ((rand() % 4900) / 4899);
			my_mlx_pixel_put(win, i, j, trgb(1, clr, clr, clr));
			my_mlx_pixel_put(win, i, win->height - j, trgb(1, 0, rand() % 50, 0));
		}
		else
		{
			draw_texture(win, i, sky, line_loc, udorlr + uord_lorr + 1);
			break ;
		}
		j++;
	}
}

void	draw_line(t_data *win, float Istart, float Jstart, float Iend, float Jend, int color)
{
	int		i;
	int		j;
	float	len;
	float	t;

	len = fabsf(Iend - Istart) + fabsf(Jend - Jstart);
	t = 0;
	while (t <= 1)
	{
		i = t * Istart + (1 - t) * Iend;
		j = t * Jstart + (1 - t) * Jend;
		if ((i < win->width && i > 0) && (j < win->height && j > 0))
			my_mlx_pixel_put(win, (int)i, (int)j, color);
		t = t + (1 / len);
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
