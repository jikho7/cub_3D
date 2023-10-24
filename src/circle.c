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

int wall(int i, int j, t_data *win)
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
	if (map[min(j/win->square, 10)][min(i/win->square, 10)] == 1)
		return (1);
	return (0);
}

void draw_line(t_data *win, float Istart, float Jstart, float Iend, float Jend, int color)
{
	int i;
	int j;
	float len;
	float t;

	len = fabsf(Iend - Istart) + fabsf(Jend - Jstart);
	t = 0;
	while (t <= 1)
	{
		i = t * Istart + (1 - t) * Iend;
		j = t * Jstart + (1 - t) * Jend;
		if ((i < win->size && i > 0) && (j < win->size && j > 0))
			my_mlx_pixel_put(win, (int)i, (int)j, color);
		t = t + (1/len);
	}
}

void direction(t_player *you, t_data *win)
{
	draw_line(win, you->posX, you->posY, you->posX + you->dirX, you->posY - you->dirY, trgb(1,225,0,0));
	draw_line(win, you->posX + you->dirX - you->planeX, you->posY - you->dirY - you->planeY, you->posX + you->dirX + you->planeX, you->posY - you->dirY + you->planeY, trgb(1,225,0,0));
	draw_line(win, you->posX, you->posY, you->posX + (you->dirX + you->planeX) * 5, you->posY + ( - you->dirY + you->planeY) * 5, trgb(1,225,0,0));
	draw_line(win, you->posX, you->posY, you->posX + (you->dirX - you->planeX) * 5, you->posY + ( - you->dirY - you->planeY) * 5, trgb(1,225,0,0));
}

int cancle(float posX, float posY, t_data *win)
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
	if (map[(int)posY/win->square][(int)posX/win->square] == 1)
		return (1);
	return (0);

}

int sgn(float n)
{
	if (n < 0)
		return (-1);
	else
		return (1);
	return (0);
}

void raycasting(t_player *you, t_data *win)
{
	float	rayDirX;
	float	rayDirY;
	float	camX;
	float	sideDistX;
	float	sideDistY;
	float	deltaX;
	float	deltaY;
	float	AdeltaX;
	float	AdeltaY;
	float	delta;
	int		step;
	float	normRay;
	int		mapX;
	int		mapY;
	int i;

	i = 0;
	while (i <= win->size)
	{
		camX = 2 * (double)i/win->size - 1;
		rayDirX = you->dirX + you->planeX * camX;
		rayDirY = -(you->dirY - you->planeY * camX);
		normRay = sqrt(rayDirX * rayDirX + rayDirY * rayDirY);
		//draw_line(win, you->posX, you->posY, you->posX + rayDirX*win->square/normRay, you->posY + rayDirY*win->square/normRay, trgb(1,i,0,100));
		if (rayDirX >= 0.0001 || rayDirX <= -0.0001 )
		{
			deltaX = sqrt(win->square*win->square * (1 + (rayDirY * rayDirY) / (rayDirX * rayDirX)));
			if (rayDirX > 0)
				delta = ceilf(you->posX / win->square) * win->square - you->posX;
			else 
				delta = you->posX - floorf(you->posX / win->square) * win->square;
			sideDistX = delta * sqrt((1 + (rayDirY * rayDirY) / (rayDirX * rayDirX)));
		}
		else
		{
			sideDistY = 10000000;
			deltaX = 100000000;
		}
		if (rayDirY >= 0.0001 || rayDirY <= -0.0001 )
		{
			deltaY = sqrt(win->square*win->square  * (1 + (rayDirX * rayDirX) / (rayDirY * rayDirY)));
			if (rayDirY > 0)
				delta = ceilf(you->posY / win->square) * win->square - you->posY;
			else 
				delta = you->posY - floorf(you->posY / win->square) * win->square;
			sideDistY = delta * sqrt((1 + (rayDirX * rayDirX) / (rayDirY * rayDirY)));
		}
		else
		{
			sideDistX = 10000000;
			deltaY = 100000000;
		}
		//draw_line(win, you->posX, you->posY, you->posX + rayDirX * sideDistX / normRay, you->posY + rayDirY * sideDistX / normRay, trgb(1,0,255,255));
		//draw_line(win, you->posX, you->posY, you->posX + rayDirX * sideDistY / normRay, you->posY + rayDirY * sideDistY / normRay, trgb(1,225,255,0));
		//DDA
		mapX = you->posX / win->square;
		mapY = you->posY / win->square;
		AdeltaX = 0;
		AdeltaY = 0;
		if (sideDistX < sideDistY)
		{
			mapX += sgn(rayDirX);
			step = 0;
			AdeltaX = deltaX;
		}
		else
		{
			mapY += sgn(rayDirY);
			step = 1;
			AdeltaY = deltaY;
		}
		while (1)
		{
			if (wall(mapX * win->square + win->square/2, mapY * win->square + win->square/2, win))
				break;
			if (sideDistX + AdeltaX < sideDistY + AdeltaY)
			{
				sideDistX += AdeltaX;
				step = 0;
				mapX += sgn(rayDirX);
				AdeltaX = deltaX;
			}
			else
			{
				sideDistY += AdeltaY;
				step = 1;
				mapY += sgn(rayDirY);
				AdeltaY = deltaY;
			}
		}
		if (step == 0)
			draw_line(win, you->posX, you->posY, you->posX + rayDirX * sideDistX / normRay, you->posY + rayDirY * sideDistX / normRay, trgb(1,255,100,0));
		else
			draw_line(win, you->posX, you->posY, you->posX + rayDirX * sideDistY / normRay, you->posY + rayDirY * sideDistY / normRay, trgb(1,255,100,0));
		i += 5;
	}
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
			else if (wall(i,j,win))
				my_mlx_pixel_put(win, i, j, trgb(1,0,0,255));
			else
				my_mlx_pixel_put(win, i, j, trgb(1,0,0,0));
			if (i%win->square == 0 || j%win->square == 0)
				my_mlx_pixel_put(win, i, j, trgb(1,200,200,200));
			j++;
		}
		i++;
	}
	direction(you, win);
	raycasting(you, win);
}

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
	win->square = 60;
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
