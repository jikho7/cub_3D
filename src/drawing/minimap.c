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

void direction(t_player *you, t_data *win, int shiftx, int shifty)
{
	draw_line(win, you->pos.x - shiftx, you->pos.y - shifty, you->pos.x - shiftx + you->dir.x * 10, you->pos.y - you->dir.y * 10 -	 shifty, trgb(1,225,0,0));
	// draw_line(win, you->pos.x + you->dir.x - you->plane.x, you->pos.y - you->dir.y - you->plane.y, you->pos.x + you->dir.x + you->plane.x, you->pos.y - you->dir.y + you->plane.y, trgb(1,225,0,0));
	// draw_line(win, you->pos.x, you->pos.y, you->pos.x + (you->dir.x + you->plane.x) * 5, you->pos.y + ( - you->dir.y + you->plane.y) * 5, trgb(1,225,0,0));
	// draw_line(win, you->pos.x, you->pos.y, you->pos.x + (you->dir.x - you->plane.x) * 5, you->pos.y + ( - you->dir.y - you->plane.y) * 5, trgb(1,225,0,0));
}

int cancle(float posX, float posY, t_data *win) 
{
	if (win->map->map[(int)posY/win->square][(int)posX/win->square] == '1')
		return (1);
	return (0);

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
			while(j < win->height)
			{
				my_mlx_pixel_put(win, i, j, 0);
				j++;
			}
			i++;
		}
		direction(you, win, shiftx, shifty);
		while (i < win->width)
		{
			j = 0;
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
