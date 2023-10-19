#include <cub3d.h>

void	circle(double size, t_data *win)
{
	(void) size;
	(void) win;
}

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
	if (map[j/20][i/20] == 1)
		return (1);
	return (0);
}

void direction(t_player *you, t_data *win)
{
	float		len;
	float	t;
	int i;
	int j;

	len = fabsf(you->dirX) +fabsf(you->dirY);
	t = 0;
	while (t <= 1)
	{
		i = t * (you->posX) + (1 - t) * (you->posX + you->dirX);
		j = t * (you->posY) + (1 - t) * (you->posY - you->dirY);
		my_mlx_pixel_put(win, i, j, trgb(1,225,0,0));
		t = t + (1/len);
	}
	len = fabsf(you->planeX) +fabsf(you->planeY);
	t = 0;
	while (t <= 1)
	{
		i = t * (you->posX + you->dirX) + (1 - t) * (you->posX + you->dirX + you->planeX);
		j = t * (you->posY - you->dirY) + (1 - t) * (you->posY - you->dirY + you->planeY);
		my_mlx_pixel_put(win, i, j, trgb(1,225,0, 200));
		i = t * (you->posX + you->dirX) + (1 - t) * (you->posX + you->dirX - you->planeX);
		j = t * (you->posY - you->dirY) + (1 - t) * (you->posY - you->dirY - you->planeY);
		my_mlx_pixel_put(win, i, j, trgb(1,225,200,0));
		t = t + (1/len);
	}
	len = (fabsf(you->planeX) + fabsf(you->planeY)) * 5;
	t = 0;
	while (t <= 1)
	{
		i = t * (you->posX) + (1 - t) * (you->posX + (you->dirX + you->planeX) * 5);
		j = t * (you->posY) + (1 - t) * (you->posY + ( - you->dirY + you->planeY) * 5);
		if ((i < win->size && i > 0) && (j < win->size && j > 0))
			my_mlx_pixel_put(win, i, j, trgb(1,225,0, 200));
		i = t * (you->posX) + (1 - t) * (you->posX + (you->dirX - you->planeX) * 5);
		j = t * (you->posY) + (1 - t) * (you->posY + ( - you->dirY - you->planeY) * 5);
		if ((i < win->size && i > 0) && (j < win->size && j > 0))
			my_mlx_pixel_put(win, i, j, trgb(1,225,200,0));
		t = t + (1/len);
	}
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
	if (map[(int)posY/20][(int)posX/20] == 1)
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
			// else if (direction(i, j, you))
			// 	my_mlx_pixel_put(win, i, j, trgb(1,255,0,0));
			else if (wall(i,j))
				my_mlx_pixel_put(win, i, j, trgb(1,0,0,255));
			else
				my_mlx_pixel_put(win, i, j, trgb(1,0,0,0));
			j++;
		}
		i++;
	}
	direction(you, win);
}

int	key_hook(int keycode, t_vars *vars)
{
	float angle;
	float tdirx;

	angle = M_PI / 6;
	if (keycode == 13)
	{
		if (cancle(vars->you->posX + vars->you->dirX/5, vars->you->posY - vars->you->dirY/5))
			return (0);
		vars->you->posX += vars->you->dirX/5;
		vars->you->posY -= vars->you->dirY/5;
		character(vars->win->size, vars->win, vars->you);
	}
	else if (keycode == 1)
	{
		if (cancle(vars->you->posX - vars->you->dirX/5, vars->you->posY + vars->you->dirY/5))
			return (0);
		vars->you->posX -= vars->you->dirX/5;
		vars->you->posY += vars->you->dirY/5;
		character(vars->win->size, vars->win, vars->you);
	}
	else if (keycode == 0)
	{
		if (cancle(vars->you->posX - vars->you->dirY/5, vars->you->posY - vars->you->dirX/5))
			return (0);
		vars->you->posX -= vars->you->dirY/5;
		vars->you->posY -= vars->you->dirX/5;
		character(vars->win->size, vars->win, vars->you);
	}
	else if (keycode == 2)
	{
		if (cancle(vars->you->posX + vars->you->dirY/5, vars->you->posY + vars->you->dirX/5))
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
		vars->you->planeX = vars->you->dirY * 0.8;
		vars->you->planeY = vars->you->dirX * 0.8;
		character(vars->win->size, vars->win, vars->you);
	}
	else if(keycode == 124)
	{
		tdirx = vars->you->dirX*cos(-angle) - vars->you->dirY*sin(-angle);
		vars->you->dirY = vars->you->dirY*cos(-angle) + vars->you->dirX*sin(-angle);
		vars->you->dirX = tdirx;
		vars->you->planeX = vars->you->dirY * 0.8;
		vars->you->planeY = vars->you->dirX * 0.8;
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
	/*double x;
	double y;
	double size;

	size = win->size;
	x = win->zoom * (4 * ((double)(i + win->t.x) - size/2) / size);
	y = win->zoom * (4 * (size/2 - (double)(j + win->t.y)) / size);
	if (mousecode == 1)
	{
		if (i >= 0 && i < size && j >= 0 && j < size)
		{
	   		my_mlx_pixel_put(win, i, j, grad(1000));
	   		printf("%f, %f\n", x, y);
		}
	}
	else if (mousecode == 2)
		printf("mouseright\n");
	else if (mousecode == 3)
		printf("mousemiddle\n");
	else if (mousecode == 4)
	{
		win->zoom *= 1.1;
		win->t.x += (i - win->size / 2) / 10;
		win->t.y += (j - win->size / 2) / 10;
		circle(win->size, win);
	}
	else if (mousecode == 5)
	{
		win->zoom /= 1.1;
		win->t.x += (i - win->size / 2) / 10;
		win->t.y += (j - win->size / 2) / 10;
		circle(win->size, win);
	}
	else
		printf("%i\n", mousecode);*/
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
	you->planeX = (you->dirX*cos(M_PI / 2) - you->dirY*sin(M_PI / 2)) * 0.9;
	you->planeY = (you->dirY*cos(M_PI / 2) + you->dirX*sin(M_PI / 2)) * 0.9;
	character(win->size, win, you);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, win->img, 0, 0);
	mlx_hook(vars->mlx_win, 4 ,0L, mouse_hook, win);
	mlx_loop_hook(vars->mlx, render_new_frame, vars);
	mlx_hook(vars->mlx_win, 17 ,0L, destroy, vars);
	mlx_hook(vars->mlx_win, 2, 0L, key_hook, vars);
	mlx_loop(vars->mlx);
}
