# include <cub3d.h>

/*
int main(int ac, char **av)
{
 	(void)ac;
	(void)av;
 	t_vars *vars;
 	t_data	*win;
 	t_player *you;
 	t_matrice *map;
	int	i;
	int	j;

	printf("parsing...\n");
	map = parsing(av[1]);
	printf(">>>>>DONE>>>\n");
 	vars = malloc(sizeof(t_vars));
 	win = malloc(sizeof(t_data));
 	you = malloc(sizeof(t_player));
 	vars->you = you;
	vars->map = map;
 	vars->mlx = mlx_init();
 	win->square = 40;
 	win->height = 700;
 	win->width = 700;
	vars->mlx_win = mlx_new_window(vars->mlx, win->width, win->height, "Play");
 	vars->win = win;
 	win->img = mlx_new_image(vars->mlx, win->width, win->height);
 	win->addr = mlx_get_data_addr(win->img, &(win->bpp), &(win->line_len), &(win->endian));
 	win->minimap = -1;
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
	printf("drawing map...\n");
	you->speed = win->square / 10;
	vars->you->plane.x = vars->you->dir.y * 0.8;
	vars->you->plane.y = vars->you->dir.x * 0.8;
	character(win, you);
 	mlx_put_image_to_window(vars->mlx, vars->mlx_win, win->img, 0, 0);
	mlx_hook(vars->mlx_win, 4 ,0L, mouse_hook, win);
 	mlx_loop_hook(vars->mlx, render_new_frame, vars);
	mlx_hook(vars->mlx_win, 17 ,0L, destroy, vars);
	mlx_hook(vars->mlx_win, 2, 0L, key_hook, vars);
 	mlx_loop(vars->mlx);
	return (0);
}*/

int	main(void)
{
	t_vars	*vars;
	t_data	*win;
	void	*img = NULL;
	char	*relative_path = "./xpm/cartoon-old-brick-wall-texture-for-2d-game-vector.xpm";
	int		img_width = 0;
	int		img_height = 0;
	int		i = 0;
	//void	*img_ptr = NULL;
	// char	*addr;
	// int		bpp;
	// int		line_len;
	// int		endian;

 	vars = malloc(sizeof(t_vars));
 	win = malloc(sizeof(t_data));
	vars->win = win;
 	vars->mlx = mlx_init();
 	win->height = 700;
 	win->width = 700;
	vars->mlx_win = mlx_new_window(vars->mlx, win->width, win->height, "Play");
 	win->img = mlx_new_image(vars->mlx, win->width, win->height);
 	win->addr = mlx_get_data_addr(win->img, &(win->bpp), &(win->line_len), &(win->endian));

	//img = mlx_new_image(mlx, 800, 800);
	img = mlx_xpm_file_to_image(vars->mlx, relative_path, &img_width, &img_height);
	printf("width: %d, height: %d\n", img_width, img_height);
	while (i < img_width * img_height - 1)
	{
		my_mlx_pixel_put(win, i/img_width, i%img_width, (unsigned int)(img + i*win->bpp / 8));
		i++;
	}
	printf("done copu\n");
	if (img != NULL)
    {
		printf("hi\n");
        mlx_put_image_to_window(vars->mlx, vars->mlx_win, win->img, 0, 0);
        mlx_loop(vars->mlx);
    }
    else
    {
        printf("Failed to load the XPM image.\n");
    }
    return 0;
}

