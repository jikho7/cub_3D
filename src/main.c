# include <cub3d.h>

int main(int ac, char **av)
{
	(void)ac;
	t_vars *vars;
	t_data	*win;
	t_player *you;
	 t_matrice *map;
	int	i;
	int	j;
	printf("Parsing...\n");
	map = parsing(av[1]);
	printf(">>>>>DONE>>>\n");
	vars = malloc(sizeof(t_vars));
	win = malloc(sizeof(t_data));
	you = malloc(sizeof(t_player));
	vars->you = you;
	vars->map = map;
	vars->mlx = mlx_init();
	win->square = 20;
	win->height = 700; //map->height * win->square;
	win->width = 700; //map->width * win->square;
	vars->mlx_win = mlx_new_window(vars->mlx, win->width, win->height, "Play");
	vars->win = win;
	win->img = mlx_new_image(vars->mlx, win->width, win->height);
	win->addr = mlx_get_data_addr(win->img, &(win->bpp), &(win->line_len), &(win->endian));
	win->map = map;

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
				goto found;
			}
			j++;
		}
		i++;
	}
	found:
	you->speed = win->square / 10;
	vars->you->plane.x = vars->you->dir.y * 0.8;
	vars->you->plane.y = vars->you->dir.x * 0.8;
	win->minimap = 1;
	printf("Drawing map...\n");
	character(win, you);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, win->img, 0, 0);
	mlx_hook(vars->mlx_win, 4 ,0L, mouse_hook, win);
	mlx_loop_hook(vars->mlx, render_new_frame, vars);
	mlx_hook(vars->mlx_win, 17 ,0L, destroy, vars);
	mlx_hook(vars->mlx_win, 2, 0L, key_hook, vars);
	mlx_loop(vars->mlx);
	return (0);
}
