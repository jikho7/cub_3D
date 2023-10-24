#include <cub3d.h>

int	key_hook(int keycode, t_vars *vars)
{
	float angle;
	float tdirx;

	angle = M_PI / 12;
	if (keycode == 13)
	{
		if (cancle(vars->you->posX + vars->you->dirX/5, vars->you->posY - vars->you->dirY/5, vars->win))
			return (0);
		vars->you->posX += vars->you->dirX/5;
		vars->you->posY -= vars->you->dirY/5;
		character(vars->win->size, vars->win, vars->you);
	}
	else if (keycode == 1)
	{
		if (cancle(vars->you->posX - vars->you->dirX/5, vars->you->posY + vars->you->dirY/5, vars->win))
			return (0);
		vars->you->posX -= vars->you->dirX/5;
		vars->you->posY += vars->you->dirY/5;
		character(vars->win->size, vars->win, vars->you);
	}
	else if (keycode == 0)
	{
		if (cancle(vars->you->posX - vars->you->dirY/5, vars->you->posY - vars->you->dirX/5, vars->win))
			return (0);
		vars->you->posX -= vars->you->dirY/5;
		vars->you->posY -= vars->you->dirX/5;
		character(vars->win->size, vars->win, vars->you);
	}
	else if (keycode == 2)
	{
		if (cancle(vars->you->posX + vars->you->dirY/5, vars->you->posY + vars->you->dirX/5, vars->win))
			return (0);
		vars->you->posX += vars->you->dirY/5;
		vars->you->posY += vars->you->dirX/5;
		character(vars->win->size, vars->win, vars->you);
	}
	else if (keycode == 123)
	{
		tdirx = vars->you->dirX*cos(angle) - vars->you->dirY*sin(angle);
		vars->you->dirY = vars->you->dirY*cos(angle) + vars->you->dirX*sin(angle);
		vars->you->dirX = tdirx;
		vars->you->planeX = vars->you->dirY;
		vars->you->planeY = vars->you->dirX;
		character(vars->win->size, vars->win, vars->you);
	}
	else if(keycode == 124)
	{
		tdirx = vars->you->dirX*cos(-angle) - vars->you->dirY*sin(-angle);
		vars->you->dirY = vars->you->dirY*cos(-angle) + vars->you->dirX*sin(-angle);
		vars->you->dirX = tdirx;
		vars->you->planeX = vars->you->dirY;
		vars->you->planeY = vars->you->dirX;
		character(vars->win->size, vars->win, vars->you);
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

	win->zoom = 1;
	win->t.x = 0;
	win->t.y = 0;
	you->posX = win->size/2;
	you->posY = win->size/2;
	you->dirX = 0;
	you->dirY = 20;
	you->planeX = (you->dirX*cos(M_PI / 2) - you->dirY*sin(M_PI / 2));
	you->planeY = (you->dirY*cos(M_PI / 2) + you->dirX*sin(M_PI / 2));
	character(win->size, win, you);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, win->img, 0, 0);
	mlx_hook(vars->mlx_win, 4 ,0L, mouse_hook, win);
	mlx_loop_hook(vars->mlx, render_new_frame, vars);
	mlx_hook(vars->mlx_win, 17 ,0L, destroy, vars);
	mlx_hook(vars->mlx_win, 2, 0L, key_hook, vars);
	mlx_loop(vars->mlx);
}
