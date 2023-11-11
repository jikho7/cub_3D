/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:51:51 by jdefayes          #+#    #+#             */
/*   Updated: 2023/11/11 13:22:31 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	chara_loc(t_data *win, t_player *you, t_mat *mat)
{
	int	i;
	int	j;
	int	eye;

	i = -1;
	while (mat->map[++i][0])
	{
		j = -1;
		while (mat->map[i][++j])
		{
			if (mat->map[i][j] == 'N' || mat->map[i][j] == 'W'
				|| mat->map[i][j] == 'S' || mat->map[i][j] == 'E')
			{
				eye = mat->map[i][j] - 69;
				you->pos.x = j * win->sqr + win->sqr / 2;
				you->pos.y = i * win->sqr + win->sqr / 2;
				you->dir.x = ((-eye * sq(eye) + 27 * sq(eye) - 227 * eye)
						/ 585 + 1);
				you->dir.y = -((-73 * eye * sq(eye) + 2101 * sq(eye) - 14166
							* eye) / 10530);
				set_comp(&(you->plane), you->dir.y * 0.8, you->dir.x * 0.8);
				return ;
			}
		}
	}
}

t_data	*init_win(t_mat *map)
{
	t_data	*win;

	win = malloc(sizeof(t_data));
	win->tex = malloc(sizeof(t_texture) * 4);
	win->sqr = 20;
	win->height = 700;
	win->width = 700;
	win->map = map;
	win->forward = 1;
	win->minimap = -1;
	win->c = 1;
	win->ray = malloc(sizeof(t_ray));
	return (win);
}

t_vars	*init_vars(t_data *win, t_player *you, t_mat *map)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	vars->mlx = mlx_init();
	vars->you = you;
	vars->win = win;
	vars->map = map;
	vars->mlx_win = mlx_new_window(vars->mlx, win->width, win->height, "Play");
	return (vars);
}

int	main(int ac, char **av)
{
	t_vars		*vars;
	t_data		*win;
	t_player	*you;
	t_mat		*map;

	(void)ac;
	map = parsing(av[1]);
	win = init_win(map);
	you = malloc(sizeof(t_player));
	vars = init_vars(win, you, map);
	win->img = mlx_new_image(vars->mlx, win->width, win->height);
	win->addr = mlx_get_data_addr(win->img, &(win->bpp),
			&(win->line_len), &(win->endian));
	create_struct_sprites(win, vars);
	chara_loc(win, you, map);
	you->speed = win->sqr / 10;
	character(win, you);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, win->img, 0, 0);
	mlx_hook(vars->mlx_win, 2, 0L, key_hook, vars);
	mlx_hook(vars->mlx_win, 17, 0L, destroy, vars);
	mlx_loop_hook(vars->mlx, render_new_frame, vars);
	mlx_loop(vars->mlx);
	return (0);
}
