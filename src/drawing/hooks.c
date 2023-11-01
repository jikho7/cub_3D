#include <cub3d.h>

int move(t_data *win, t_player *you, float addX, float addY)
{
	if (cancle(you->pos.x + addX * you->speed, you->pos.y + addY * you->speed, win))
		return (1);
	you->pos.x += addX * you->speed;
	you->pos.y += addY * you->speed;
	character(win, you);
	return (0);
}

void turn(t_data *win, t_player *you, int clockwise)
{
	float angle;
	float tdirx;

	angle = M_PI /12;
	tdirx = you->dir.x*cos(clockwise * angle) - you->dir.y*sin(clockwise * angle);
	you->dir.y = you->dir.y*cos(clockwise * angle) + you->dir.x*sin(clockwise * angle);
	you->dir.x = tdirx;
	you->plane.x = you->dir.y;
	you->plane.y = you->dir.x;
	character(win, you);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 13)
		move(vars->win, vars->you, vars->you->dir.x, -vars->you->dir.y);
	else if (keycode == 1)
		move(vars->win, vars->you, -vars->you->dir.x, vars->you->dir.y);
	else if (keycode == 0)
		move(vars->win, vars->you, -vars->you->dir.y, -vars->you->dir.x);
	else if (keycode == 2)
		move(vars->win, vars->you, vars->you->dir.y, vars->you->dir.x);
	else if (keycode == 123)
		turn(vars->win, vars->you, 1);
	else if(keycode == 124)
		turn(vars->win, vars->you, -1);
	else if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->mlx_win);
	else if (keycode == 46)
	{
		vars->win->minimap *= -1;
		character(vars->win, vars->you);
	}
	else if (keycode == 257)
	{
		if (vars->you->speed == vars->win->square / 10)
			vars->you->speed = vars->win->square / 5;
		else
			vars->you->speed = vars->win->square / 10;
	}
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
