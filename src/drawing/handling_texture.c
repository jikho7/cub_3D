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

void	create_struct_sprites(t_data *win, t_vars *vars)
{
	int	i;

	win->tex[1].path = vars->map->NO_path;
	win->tex[3].path = vars->map->SO_path;
	win->tex[2].path = vars->map->EA_path;
	win->tex[0].path = vars->map->WE_path;

	i = 0;
	while (i < 4)
	{
		win->tex[i].img_ptr = mlx_xpm_file_to_image(vars->mlx, win->tex[i].path, &win->tex[i].width, &win->tex[i].height);
		if (!win->tex[i].img_ptr)
			printf("Error: Texture not found: -%s...\n", win->tex[i].path);
		else
			win->tex[i].addr = mlx_get_data_addr(win->tex[i].img_ptr, &win->tex[i].bpp, &win->tex[i].line_len, &win->tex[i].endian);
		i++;
	}
}
