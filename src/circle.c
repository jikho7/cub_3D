#include <cub3d.h>

int chara(int i, int j, t_player *you)
{
	float	x;
	float	y;

	x = i - you->pos.x;
	y = j - you->pos.y;
	if ((x*x + y*y) <= 25)
		return (1);
	return (0);
}

int wall(int i, int j, t_data *win)
{
	if (win->map->map[j/win->square][i/win->square] == '1')
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
		if ((i < win->width && i > 0) && (j < win->height && j > 0))
			my_mlx_pixel_put(win, (int)i, (int)j, color);
		t = t + (1/len);
	}
}

void direction(t_player *you, t_data *win)
{
	draw_line(win, you->pos.x, you->pos.y, you->pos.x + you->dir.x, you->pos.y - you->dir.y, trgb(1,225,0,0));
	draw_line(win, you->pos.x + you->dir.x - you->plane.x, you->pos.y - you->dir.y - you->plane.y, you->pos.x + you->dir.x + you->plane.x, you->pos.y - you->dir.y + you->plane.y, trgb(1,225,0,0));
	draw_line(win, you->pos.x, you->pos.y, you->pos.x + (you->dir.x + you->plane.x) * 5, you->pos.y + ( - you->dir.y + you->plane.y) * 5, trgb(1,225,0,0));
	draw_line(win, you->pos.x, you->pos.y, you->pos.x + (you->dir.x - you->plane.x) * 5, you->pos.y + ( - you->dir.y - you->plane.y) * 5, trgb(1,225,0,0));
}

int cancle(float posX, float posY, t_data *win)
{
	if (win->map->map[(int)posY/win->square][(int)posX/win->square] == '1')
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

void draw_wall(float distance, int i, int NW, t_data *win, t_complex raydir, int texture)
{
	int j;
	int	hight;
	int	percentile;
	int	red;
	int	SE;
	(void)texture;

	hight = win->square;
	percentile = win->height *(distance - win->square /2) / (2 * distance);
	j = 0;
	SE = (NW) * sgn(raydir.y) + (1 - NW) * sgn(raydir.x);
	red = max(0, NW * 100 + SE * 30);
	while (j <= win->height / 2)
	{
		if (j < percentile)
		{
			my_mlx_pixel_put(win, i, j, trgb(1,rand() % 255,0,0));
			my_mlx_pixel_put(win, i, win->height - j, trgb(1,50,rand() % 20 + 20,0));
		}
		else
		{
			my_mlx_pixel_put(win, i, j, trgb(1,texture * 5, 0,0));
			my_mlx_pixel_put(win, i, win->height - j, trgb(1,texture * 5,0,0));
			// my_mlx_pixel_put(win, i, j, trgb(1,red,20,0));
			// my_mlx_pixel_put(win, i, win->height - j, trgb(1,red,20,0));
		}
		j++;
	}
}

void	set_ray(int i, t_complex *rayDir, t_complex *sqDelta, t_complex *sideDist, t_data *win, t_player *you)
{
	float	delta;
	float	camX;

	camX = 2 * (double)i/win->width - 1;
	rayDir->x = you->dir.x + you->plane.x * camX;
	rayDir->y = -(you->dir.y - you->plane.y * camX);
	if (rayDir->x >= 0.0001 || rayDir->x <= -0.0001 )
	{
		sqDelta->x = sqrt(win->square*win->square * (1 + (rayDir->y * rayDir->y) / (rayDir->x * rayDir->x)));
		if (rayDir->x > 0)
			delta = ceilf(you->pos.x / win->square) * win->square - you->pos.x;
		else
			delta = you->pos.x - floorf(you->pos.x / win->square) * win->square;
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
			delta = ceilf(you->pos.y / win->square) * win->square - you->pos.y;
		else
			delta = you->pos.y - floorf(you->pos.y / win->square) * win->square;
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

	mapX = you->pos.x / win->square;
	mapY = you->pos.y / win->square;
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
	t_complex	dist;
	float		normRay;

	normRay = sqrt(rayDir.x * rayDir.x + rayDir.y * rayDir.y);
	dist.x = rayDir.x * sideDist / normRay;
	dist.y = - rayDir.y * sideDist / normRay;
	return (fabsf(proj_dist(dist, you->dir)));
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
	while (i <= win->width)
	{
		set_ray(i, &rayDir, &sqDelta, &sideDist, win, you);
		step = DDA(you, win, rayDir, sqDelta, &sideDist);
		normRay = sqrt(rayDir.x * rayDir.x + rayDir.y * rayDir.y);
		if (step == 0)
		{
			if (win->minimap == 1)
			{
				if (i % 2)
					draw_line(win, you->pos.x, you->pos.y, you->pos.x + rayDir.x * sideDist.x / normRay, you->pos.y + rayDir.y * sideDist.x / normRay, trgb(1,255,100,0));
			}
			else
				draw_wall(unfisheye(you, rayDir, sideDist.x), i, 0, win, rayDir, max((int)(you->pos.x + rayDir.x * sideDist.x / normRay)%win->square, (int)(you->pos.y + rayDir.y * sideDist.x / normRay)%win->square));
		}
		else
		{
			if (win->minimap == 1)
			{
				if (i % 2)
					draw_line(win, you->pos.x, you->pos.y, you->pos.x + rayDir.x * sideDist.y / normRay, you->pos.y + rayDir.y * sideDist.y / normRay, trgb(1,255,100,0));
			}
			else
				draw_wall(unfisheye(you, rayDir, sideDist.y), i, 1, win, rayDir, max((int)(you->pos.x + rayDir.x * sideDist.y / normRay)%win->square,(int)(you->pos.y + rayDir.y * sideDist.y / normRay)%win->square));
		}
		i += 1;
	}
}

void	character(t_data *win, t_player *you)
{
	int i;
	int j;
	int	shiftx;
	int	shifty;

	i = 0;
	shiftx = max(0,you->pos.x - win->width/2);
	shifty = min(max(0, win->map->height * win->square - win->height), max(0, you->pos.y - win->height/2));
	if (win->minimap == 1)
	{
		while (i < min(win->width, win->map->width * win->square))
		{
			j = 0;
			while (j < min(win->width, win->map->height * win->square))
			{
				if (chara(i + shiftx,j + shifty, you))
					my_mlx_pixel_put(win, i, j, trgb(1,0,255,0));
				else if (wall(i + shiftx, j + shifty, win))
					my_mlx_pixel_put(win, i, j, trgb(1,0,0,255));
				else
					my_mlx_pixel_put(win, i, j, trgb(1,0,0,0));
				if ((i + shiftx)%win->square == 0 || (j + shifty)%win->square == 0)
					my_mlx_pixel_put(win, i, j, trgb(1,100,100,100));
				j++;
			}
			i++;
		}
		//direction(you, win);
		while (i < win->width)
		{
			while(j < win->height)
			{
				my_mlx_pixel_put(win, i, j, 0);
				j++;
			}
			i++;
		}
	}
	if (you->pos.x == (int)you->pos.x)
		you->pos.x += 0.0001;
	if (you->pos.y == (int)you->pos.y)
		you->pos.y += 0.0001;
	raycasting(you, win);
}
