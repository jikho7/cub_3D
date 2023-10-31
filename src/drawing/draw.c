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

void draw_wall(float distance, int i, int NW, t_data *win, t_complex raydir, int texture)
{
	int j;
	int	hight;
	int	percentile;
	int	red;
	int	SE;
	(void)texture;

	hight = win->square;
	percentile = win->height *(distance - win->square /2) / (2 * distance);
	j = 0;
	SE = (NW) * sgn(raydir.y) + (1 - NW) * sgn(raydir.x);
	red = max(0, NW * 100 + SE * 30);
	while (j <= win->height / 2)
	{
		if (j < percentile)
		{
			my_mlx_pixel_put(win, i, j, trgb(1,rand() % 255,0,0));
			my_mlx_pixel_put(win, i, win->height - j, trgb(1,50,rand() % 20 + 20,0));
		}
		else
		{
			my_mlx_pixel_put(win, i, j, trgb(1,texture * 5, 0,0));
			my_mlx_pixel_put(win, i, win->height - j, trgb(1,texture * 5,0,0));
			// my_mlx_pixel_put(win, i, j, trgb(1,red,20,0));
			// my_mlx_pixel_put(win, i, win->height - j, trgb(1,red,20,0));
		}
		j++;
	}
}

void draw_line(t_data *win, float Istart, float Jstart, float Iend, float Jend, int color)
{
	int i;
	int j;
	float len;
	float t;

	len = fabsf(Iend - Istart) + fabsf(Jend - Jstart);
	t = 0;
	while (t <= 1)
	{
		i = t * Istart + (1 - t) * Iend;
		j = t * Jstart + (1 - t) * Jend;
		if ((i < win->width && i > 0) && (j < win->height && j > 0))
			my_mlx_pixel_put(win, (int)i, (int)j, color);
		t = t + (1/len);
	}
}


void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    if (data == NULL || data->addr == NULL) {
        // Handle the error condition, or print a message.
        printf("Invalid data or data->addr is NULL\n");
        return;
    }

    if (x < 0 || x >= data->width || y < 0 || y >= data->height) {
        // Handle out-of-bounds access.
        printf("Out-of-bounds access: (%d, %d)\n", x, y);
        return;
    }

    char *dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
    *(unsigned int *)dst = color;
}

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;
// 	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
// 	// if (y == 0 || y == data->height)
// 	// 	printf("E2 (%d, %d) %p\n", x, y,  dst);
// 	*(unsigned int *)dst = color;
// 	//printf("E3\n");
// }

int	trgb(int t, int red, int green, int blue)
{
	return (t << 24 | red << 16 | green << 8 | blue);
}
