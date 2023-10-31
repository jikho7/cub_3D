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

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
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
