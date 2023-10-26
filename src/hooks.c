#include <cub3d.h>

int	key_hook(int keycode, t_vars *vars)
{
	float angle;
	float tdirx;

	angle = M_PI / 12;
	if (keycode == 13)
	{
		if (cancle(vars->you->pos.x + vars->you->dir.x * vars->you->speed, vars->you->pos.y - vars->you->dir.y * vars->you->speed, vars->win))
			return (0);
		vars->you->pos.x += vars->you->dir.x * vars->you->speed;
		vars->you->pos.y -= vars->you->dir.y * vars->you->speed;
		character(vars->win, vars->you);
	}
	else if (keycode == 1)
	{
		if (cancle(vars->you->pos.x - vars->you->dir.x * vars->you->speed, vars->you->pos.y + vars->you->dir.y * vars->you->speed, vars->win))
			return (0);
		vars->you->pos.x -= vars->you->dir.x * vars->you->speed;
		vars->you->pos.y += vars->you->dir.y * vars->you->speed;
		character(vars->win, vars->you);
	}
	else if (keycode == 0)
	{
		if (cancle(vars->you->pos.x - vars->you->dir.y * vars->you->speed, vars->you->pos.y - vars->you->dir.x * vars->you->speed, vars->win))
			return (0);
		vars->you->pos.x -= vars->you->dir.y * vars->you->speed;
		vars->you->pos.y -= vars->you->dir.x * vars->you->speed;
		character(vars->win, vars->you);
	}
	else if (keycode == 2)
	{
		if (cancle(vars->you->pos.x + vars->you->dir.y * vars->you->speed, vars->you->pos.y + vars->you->dir.x * vars->you->speed, vars->win))
			return (0);
		vars->you->pos.x += vars->you->dir.y * vars->you->speed;
		vars->you->pos.y += vars->you->dir.x * vars->you->speed;
		character(vars->win, vars->you);
	}
	else if (keycode == 123)
	{
		tdirx = vars->you->dir.x*cos(angle) - vars->you->dir.y*sin(angle);
		vars->you->dir.y = vars->you->dir.y*cos(angle) + vars->you->dir.x*sin(angle);
		vars->you->dir.x = tdirx;
	vars->you->plane.x = vars->you->dir.y;
	vars->you->plane.y = vars->you->dir.x;
		character(vars->win, vars->you);
	}
	else if(keycode == 124)
	{
		tdirx = vars->you->dir.x*cos(-angle) - vars->you->dir.y*sin(-angle);
		vars->you->dir.y = vars->you->dir.y*cos(-angle) + vars->you->dir.x*sin(-angle);
		vars->you->dir.x = tdirx;
	vars->you->plane.x = vars->you->dir.y;
	vars->you->plane.y = vars->you->dir.x;
		character(vars->win, vars->you);
	}
	else if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->mlx_win);
	else
		printf("%d\n", keycode);
	return(0);
}

int mouse_hook(int mousecode, int i, int j, t_data *win)
{
	if (mousecode == 1)
		printf("(i,j) = (%d,%d)\n", i, j);
	(void) win;
	return(0);
}

int render_new_frame(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->win->img, 0, 0);
	return(0);
}

int destroy(t_vars *vars)
{
	free(vars->win);
	free(vars);
	exit(0);
}

int main(int argc, char **argv)
{
	t_vars *vars;
	t_data	*win;
	t_player *you;
	int	i;
	int	j;
	char map[12][12] =	{"11111111111",
						"10100010001",
						"10111010101",
						"10001010001",
						"10100010001",
						"10110001011",
						"10100010001",
						"10101100101",
						"10100000001",
						"101000000N1",
						"11111111111"};
	
	if (argc != 2)
	{
		printf("forgot argument");
		return (1);
	}
	vars = malloc(sizeof(t_vars));
	win = malloc(sizeof(t_data));
	you = malloc(sizeof(t_player));
	vars->you = you;
	vars->mlx = mlx_init();
	win->square = 10 * atoi(argv[1]);
	win->size = 11 * win->square;
	vars->mlx_win = mlx_new_window(vars->mlx, win->size, win->size, "Play");
	vars->win = win;
	win->img = mlx_new_image(vars->mlx, win->size, win->size);
	win->addr = mlx_get_data_addr(win->img, &(win->bpp), &(win->line_len), &(win->endian));

	i = 0;
	while (i < 11)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W'|| map[i][j] == 'S'|| map[i][j] == 'E')
			{
				you->pos.x = j * win->square + win->square/2;
				you->pos.y = i * win->square + win->square/2;
				map[i][j] -= 69;
				you->dir.x = ((-map[i][j] * map[i][j] * map[i][j] + 27 * map[i][j] * map[i][j] - 227 * map[i][j])/585 + 1);
				you->dir.y = -((- 73 * map[i][j] * map[i][j] * map[i][j] + 2101 * map[i][j] * map[i][j] - 14166 * map[i][j])/10530);
				i = 10;
				break;
			}
			
			j++;
		}
		i++;
	}
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
}
