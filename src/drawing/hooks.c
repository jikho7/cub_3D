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
