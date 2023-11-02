# include <cub3d.h>

void	chara_loc(t_data *win, t_player *you, t_matrice *map)
{
	int i;
	int j;

	i = 0;
	while (map->map[i][0])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'W'|| map->map[i][j] == 'S'|| map->map[i][j] == 'E')
			{
				you->pos.x = j * win->square + win->square/2;
				you->pos.y = i * win->square + win->square/2;
				map->map[i][j] -= 69;
				you->dir.x = ((-map->map[i][j] * map->map[i][j] * map->map[i][j] + 27 * map->map[i][j] * map->map[i][j] - 227 * map->map[i][j])/585 + 1);
				you->dir.y = -((- 73 * map->map[i][j] * map->map[i][j] * map->map[i][j] + 2101 * map->map[i][j] * map->map[i][j] - 14166 * map->map[i][j])/10530);
				you->plane.x = you->dir.y * 0.8;
				you->plane.y = you->dir.x * 0.8;
				return;
			}
			j++;
		}
		i++;
	}
}

t_data *init_win(t_matrice *map)
{
	t_data	*win;

	win = malloc(sizeof(t_data));
	win->tex = malloc(sizeof(t_texture) * 4);
	win->square = 20;
 	win->height = 700;
 	win->width = 700;
	win->map = map;
	win->forward = 1;
	win->minimap = -1;
	win->c		= 1;
	win->ray = malloc(sizeof(t_ray));
	return (win);
}

t_vars	*init_vars(t_data *win, t_player *you, t_matrice *map)
{
	t_vars *vars;

	vars = malloc(sizeof(t_vars));
	vars->mlx = mlx_init();
	vars->you = you;
	vars->win = win;
	vars->map = map;
	vars->mlx_win = mlx_new_window(vars->mlx, win->width, win->height, "Play");
	return(vars);
}

int main(int ac, char **av)
{
 	(void)ac;
 	t_vars *vars;
 	t_data	*win;
 	t_player *you;
 	t_matrice *map;

	map = parsing(av[1]);
	win = init_win(map);
 	you = malloc(sizeof(t_player));
	vars = init_vars(win, you, map);
 	win->img = mlx_new_image(vars->mlx, win->width, win->height);
 	win->addr = mlx_get_data_addr(win->img, &(win->bpp), &(win->line_len), &(win->endian));
	create_struct_sprites(win, vars);
	chara_loc(win, you, map);
	you->speed = win->square / 10;
	character(win, you);
 	mlx_put_image_to_window(vars->mlx, vars->mlx_win, win->img, 0, 0);
	mlx_hook(vars->mlx_win, 4 ,0L, mouse_hook, win);
	mlx_hook(vars->mlx_win, 2, 0L, key_hook, vars);
	mlx_hook(vars->mlx_win, 17 ,0L, destroy, vars);
	mlx_loop_hook(vars->mlx, render_new_frame, vars);
 	mlx_loop(vars->mlx);
	return (0);
}

