#include "../cub3d.h"
#include "../mlx/mlx.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int chara(int i, int j, t_player *you)
{
	float	x;
	float	y;

	x = i - you->posX;
	y = j - you->posY;
	if ((x*x + y*y) <= 25)
		return (1);
	return (0);
}

int wall(int i, int j)
{
	int map[11][11] = {	{1,1,1,1,1,1,1,1,1,1,1},
						{1,0,1,0,0,0,1,0,0,0,1},
						{1,0,1,1,1,0,1,0,1,0,1},
						{1,0,0,0,1,0,1,0,0,0,1},
						{1,0,1,0,0,0,1,0,0,0,1},
						{1,0,1,1,0,0,0,1,0,1,1},
						{1,0,1,0,0,0,1,0,0,0,1},
						{1,0,1,0,1,1,0,0,1,0,1},
						{1,0,1,0,0,0,0,0,0,0,1},
						{1,0,1,0,0,0,0,0,0,0,1},
						{1,1,1,1,1,1,1,1,1,1,1}};
	if (map[i/20][j/20] == 1)
		return (1);
	return (0);
}

int direction(int i, int j, t_player *you)
{
	float	x;
	float	y;

	x = i - you->posX - you->dirX;
	y = j - you->posY + you->dirY;
	if ((x*x + y*y) <= 1)
		return (1);
	return (0);
}

int cancle(float posX, float posY)
{
	int map[11][11] = {	{1,1,1,1,1,1,1,1,1,1,1},
						{1,0,1,0,0,0,1,0,0,0,1},
						{1,0,1,1,1,0,1,0,1,0,1},
						{1,0,0,0,1,0,1,0,0,0,1},
						{1,0,1,0,0,0,1,0,0,0,1},
						{1,0,1,1,0,0,0,1,0,1,1},
						{1,0,1,0,0,0,1,0,0,0,1},
						{1,0,1,0,1,1,0,0,1,0,1},
						{1,0,1,0,0,0,0,0,0,0,1},
						{1,0,1,0,0,0,0,0,0,0,1},
						{1,1,1,1,1,1,1,1,1,1,1}};
	if (map[(int)posX/20][(int)posY/20] == 1)
		return (1);
	return (0);

}

void	character(double size, t_data *win, t_player *you)
{
	int i = 0;
	int j;

	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (chara(i, j, you))
				my_mlx_pixel_put(win, i, j, trgb(1,0,255,0));
			else if (direction(i, j, you))
				my_mlx_pixel_put(win, i, j, trgb(1,255,0,0));
			else if (wall(i,j))
				my_mlx_pixel_put(win, i, j, trgb(1,0,0,255));
			else
				my_mlx_pixel_put(win, i, j, trgb(1,0,0,0));
			j++;
		}
		i++;
	}
}


int	key_hook(int keycode, t_vars *vars)
{
	float angle;
	float tdirx;

	angle = M_PI / 6;
	if (keycode == 13)
	{	
		if (cancle(vars->you->posX + vars->you->dirX, vars->you->posY - vars->you->dirY))
			return (0);
		vars->you->posX += vars->you->dirX;
		vars->you->posY -= vars->you->dirY;
		character(vars->win->size, vars->win, vars->you);
	}
	else if (keycode == 1)
	{
		if (cancle(vars->you->posX - vars->you->dirX, vars->you->posY + vars->you->dirY))
			return (0);
		vars->you->posX -= vars->you->dirX;
		vars->you->posY += vars->you->dirY;
		character(vars->win->size, vars->win, vars->you);
	}
	else if (keycode == 0)
	{
		if (cancle(vars->you->posX - vars->you->dirY, vars->you->posY - vars->you->dirX))
			return (0);
		vars->you->posX -= vars->you->dirY;
		vars->you->posY -= vars->you->dirX;
		character(vars->win->size, vars->win, vars->you);
	}	
	else if (keycode == 2)
	{
		if (cancle(vars->you->posX + vars->you->dirY, vars->you->posY + vars->you->dirX))
			return (0);
		vars->you->posX += vars->you->dirY;
		vars->you->posY += vars->you->dirX;
		character(vars->win->size, vars->win, vars->you);
	}
	else if (keycode == 123)
	{
		tdirx = vars->you->dirX*cos(angle) - vars->you->dirY*sin(angle);
		vars->you->dirY = vars->you->dirY*cos(angle) + vars->you->dirX*sin(angle);
		vars->you->dirX = tdirx;
		vars->you->planeX = (vars->you->dirX*cos(M_PI / 2) - vars->you->dirY*sin(M_PI / 2)) * 0.1;
		vars->you->planeY = (vars->you->dirY*cos(M_PI / 2) + vars->you->dirX*sin(M_PI / 2)) * 0.1;
		character(vars->win->size, vars->win, vars->you);
	}
	else if(keycode == 124)
	{
		tdirx = vars->you->dirX*cos(-angle) - vars->you->dirY*sin(-angle);
		vars->you->dirY = vars->you->dirY*cos(-angle) + vars->you->dirX*sin(-angle);
		vars->you->dirX = tdirx;
		vars->you->planeX = (vars->you->dirX*cos(M_PI / 2) - vars->you->dirY*sin(M_PI / 2)) * 0.1;
		vars->you->planeY = (vars->you->dirY*cos(M_PI / 2) + vars->you->dirX*sin(M_PI / 2)) * 0.1;
		character(vars->win->size, vars->win, vars->you);
	}
	else if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->mlx_win);
	else
		printf("%d\n", keycode);
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

int view(t_player you)
{

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
	win->size = atoi(argv[1]);
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
	you->planeX = (you->dirX*cos(M_PI / 2) - you->dirY*sin(M_PI / 2)) * 0.1;
	you->planeY = (you->dirY*cos(M_PI / 2) + you->dirX*sin(M_PI / 2)) * 0.1 ;
	character(win->size, win, you);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, win->img, 0, 0);
	mlx_loop_hook(vars->mlx, render_new_frame, vars);
	mlx_hook(vars->mlx_win, 17 ,0L, destroy, vars);
	mlx_key_hook(vars->mlx_win, key_hook, vars);
	mlx_loop(vars->mlx);
}