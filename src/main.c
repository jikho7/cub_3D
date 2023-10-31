# include <cub3d.h>

// int main(int ac, char **av)
// {
//  	(void)ac;
// 	(void)av;
//  	t_vars *vars;
//  	t_data	*win;
//  	t_player *you;
//  //	 t_matrice *map;
// // 	int	i;
// // 	int	j;

// //	void	*mlx;
// //	void	*img;
// 	char	*relative_path = ".xpm/cartoon-old-brick-wall-texture-for-2d-game-vector.xpm";
// //	int		img_width;
// //	int		img_height;

// //	mlx = mlx_init();
// // 	map = parsing(av[1]);
// // 	printf(">>>>>DONE>>>\n");
//  	vars = malloc(sizeof(t_vars));
//  	win = malloc(sizeof(t_data));
//  	you = malloc(sizeof(t_player));
//  	vars->you = you;
//  //	vars->map = map;
//  	vars->mlx = mlx_init();
//  	win->square = 40;
//  	win->height = 700; //map->height * win->square;
//  	win->width = 700; //map->width * win->square;
// // 	printf("a %d %d\n", map->width, map->height);
// // 	printf("b %d %d\n", win->width, win->height);
//  	vars->mlx_win = mlx_new_window(vars->mlx, win->width, win->height, "Play");
//  	vars->win = win;
//  	win->img = mlx_new_image(vars->mlx, win->width, win->height);
//  	win->addr = mlx_get_data_addr(win->img, &(win->bpp), &(win->line_len), &(win->endian));
//  //	win->minimap = 1;
//  //	win->map = map;
// 	win->img = mlx_xpm_file_to_image(vars->mlx, relative_path, &win->width, &win->height);

// // 	i = 0;
// // 	while (map->map[i][0])
// // 	{
// // 		j = 0;
// // 		while (map->map[i][j])
// // 		{
// // 			if (map->map[i][j] == 'N' || map->map[i][j] == 'W'|| map->map[i][j] == 'S'|| map->map[i][j] == 'E')
// // 			{
// // 				you->pos.x = j * win->square + win->square/2;
// // 				you->pos.y = i * win->square + win->square/2;
// // 				map->map[i][j] -= 69;
// // 				you->dir.x = ((-map->map[i][j] * map->map[i][j] * map->map[i][j] + 27 * map->map[i][j] * map->map[i][j] - 227 * map->map[i][j])/585 + 1);
// // 				you->dir.y = -((- 73 * map->map[i][j] * map->map[i][j] * map->map[i][j] + 2101 * map->map[i][j] * map->map[i][j] - 14166 * map->map[i][j])/10530);
// // 				goto found;
// // 			}
// // 			j++;
// // 		}
// // 		i++;
// // 	}
// // 	found:
// // 	you->speed = win->square / 10;
// // 	vars->you->plane.x = vars->you->dir.y * 0.8;
// // 	vars->you->plane.y = vars->you->dir.x * 0.8;
// // 	character(win, you);
//  	mlx_put_image_to_window(vars->mlx, vars->mlx_win, win->img, 0, 0);
// // 	mlx_hook(vars->mlx_win, 4 ,0L, mouse_hook, win);
//  	mlx_loop_hook(vars->mlx, render_new_frame, vars);
// // 	mlx_hook(vars->mlx_win, 17 ,0L, destroy, vars);
// // 	mlx_hook(vars->mlx_win, 2, 0L, key_hook, vars);
//  	mlx_loop(vars->mlx);
// // 	return (0);
// }

int	main(void)
{
	void	*mlx;
	t_data	*mlx_win = NULL;
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

	mlx = mlx_init();
	mlx_win = malloc(sizeof(t_data));
	mlx_win->width = 800;
	mlx_win->height = 800;
	mlx_win->img = mlx_new_image(mlx, mlx_win->width, mlx_win->height);
	mlx_win = mlx_new_window(mlx, mlx_win->width, mlx_win->height, "test");
	//img = mlx_new_image(mlx, 800, 800);
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	printf("width: %d, height: %d\n", img_width, img_height);
	while (i < img_width * img_height)
	{
		my_mlx_pixel_put(mlx_win, i/img_width, i%img_width, (int)(img + i*mlx_win->bpp / 8));
		i++;
	}
	// addr = mlx_get_data_addr(img, &bpp,
	// 		&line_len, &endian);
	//img.img = +mlx, path, &img.width, &img.height);
	if (img != NULL)
    {
        mlx_put_image_to_window(mlx, mlx_win, mlx_win->img, 0, 0);
        mlx_loop(mlx);
    }
    else
    {
        printf("Failed to load the XPM image.\n");
    }
    return 0;
}

