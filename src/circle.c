#include <cub3d.h>

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

void draw_wall(float distance, int i, int side, t_data *win)
{
	int j;
	int	hight;
	int	percentile;
	int	red;

	hight = win->square;
	percentile = max(0,(win->size * (distance - hight)) / distance);
	printf("h %d\n", percentile);
	j = 0;
	red = side * 200;
	while (j <= win->size / 2)
	{
		if (j < percentile)
		{
			my_mlx_pixel_put(win, i, j, trgb(1,100,100,0));
			my_mlx_pixel_put(win, i, win->size - j, trgb(1,0,100,100));
		}
		else
		{
			my_mlx_pixel_put(win, i, j, trgb(1,red,0,200));
			my_mlx_pixel_put(win, i, win->size - j, trgb(1,red,0,200));
		}
		j++;
	}
}

void	set_ray(int i, t_complex *rayDir, t_complex *sqDelta, t_complex *sideDist, t_data *win, t_player *you)
{
	float	delta;
	float	camX;

	camX = 2 * (double)i/win->size - 1;
	rayDir->x = you->dirX + you->planeX * camX;
	rayDir->y = -(you->dirY - you->planeY * camX);
	if (rayDir->x >= 0.0001 || rayDir->x <= -0.0001 )
	{
		sqDelta->x = sqrt(win->square*win->square * (1 + (rayDir->y * rayDir->y) / (rayDir->x * rayDir->x)));
		if (rayDir->x > 0)
			delta = ceilf(you->posX / win->square) * win->square - you->posX;
		else 
			delta = you->posX - floorf(you->posX / win->square) * win->square;
		sideDist->x = delta * sqrt((1 + (rayDir->y * rayDir->y) / (rayDir->x * rayDir->x)));
	}
	else
	{
		sideDist->y = 10000000;
		sqDelta->x = 100000000;
	}
	if (rayDir->y >= 0.0001 || rayDir->y <= -0.0001 )
	{
		sqDelta->y = sqrt(win->square*win->square  * (1 + (rayDir->x * rayDir->x) / (rayDir->y * rayDir->y)));
		if (rayDir->y > 0)
			delta = ceilf(you->posY / win->square) * win->square - you->posY;
		else 
			delta = you->posY - floorf(you->posY / win->square) * win->square;
		sideDist->y = delta * sqrt((1 + (rayDir->x * rayDir->x) / (rayDir->y * rayDir->y)));
	}
	else
	{
		sideDist->x = 10000000;
		sqDelta->y = 100000000;
	}
}

int	DDA(t_player *you, t_data *win, t_complex rayDir, t_complex sqDelta, t_complex *sideDist)
{
	t_complex Adelta;
	int		mapX;
	int		mapY;
	int		step;

	mapX = you->posX / win->square;
	mapY = you->posY / win->square;
	Adelta.x = 0;
	Adelta.y = 0;
	if (sideDist->x < sideDist->y)
	{
		mapX += sgn(rayDir.x);
		step = 0;
		Adelta.x = sqDelta.x;
	}
	else
	{
		mapY += sgn(rayDir.y);
		step = 1;
		Adelta.y = sqDelta.y;
	}
	while (1)
	{
		if (wall(mapX * win->square + win->square/2, mapY * win->square + win->square/2, win))
			break;
		if (sideDist->x + Adelta.x < sideDist->y + Adelta.y)
		{
			sideDist->x += Adelta.x;
			step = 0;
			mapX += sgn(rayDir.x);
			Adelta.x = sqDelta.x;
		}
		else
		{
			sideDist->y += Adelta.y;
			step = 1;
			mapY += sgn(rayDir.y);
			Adelta.y = sqDelta.y;
		}
	}
	return (step);
}

float proj_dist(t_complex a, t_complex b)
{
	return ((a.x*b.x + a.y*b.y) / sqrtf(b.x*b.x + b.y*b.y));
}

float unfisheye(t_player *you, t_complex rayDir, float sideDist)
{
	t_complex	dir;
	t_complex	dist;
	float		normRay;

	normRay = sqrt(rayDir.x * rayDir.x + rayDir.y * rayDir.y);
	dir.x = you->dirX;
	dir.y = you->dirY;
	dist.x = rayDir.x * sideDist / normRay;
	dist.y = rayDir.y * sideDist / normRay;
	return (proj_dist(dist, dir));
}

void raycasting(t_player *you, t_data *win)
{
	t_complex rayDir;
	t_complex sideDist;
	t_complex sqDelta;
	int		step;
	float	normRay;
	int i;

	i = 0;
	while (i <= win->size)
	{
		set_ray(i, &rayDir, &sqDelta, &sideDist, win, you);
		step = DDA(you, win, rayDir, sqDelta, &sideDist);
		normRay = sqrt(rayDir.x * rayDir.x + rayDir.y * rayDir.y);
		if (step == 0)
		{
			// CARTE VU DU DESSUS
			//draw_line(win, you->posX, you->posY, you->posX + rayDir.x * sideDist.x / normRay, you->posY + rayDir.y * sideDist.x / normRay, trgb(1,255,100,0));
			// 3D avec fisheye
			//draw_wall(sideDist.x, i, 0, win);
			// 3D sans fisheye
			draw_wall(unfisheye(you, rayDir, sideDist.x), i, 0, win);
		}
		else
		{
			//draw_line(win, you->posX, you->posY, you->posX + rayDir.x * sideDist.y / normRay, you->posY + rayDir.y * sideDist.y / normRay, trgb(1,255,100,0));
			//draw_wall(sideDist.y, i, 1, win);
			draw_wall(unfisheye(you, rayDir, sideDist.y), i, 1, win);
		}
		i += 1;
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
				my_mlx_pixel_put(win, i, j, trgb(1,100,100,100));
			j++;
		}
		i++;
	}
	direction(you, win);
	raycasting(you, win);
}