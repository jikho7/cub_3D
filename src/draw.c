# include <cub3d.h>

// void	info_display(t_data *data);

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	trgb(int t, int red, int green, int blue)
{
	return (t << 24 | red << 16 | green << 8 | blue);
}

int	grad(int i)
{
	int	r;
	int	g;

	r = min(max(0, i - 510), 255);
	g = min(min(i, 1020 - i), 255);
	return (trgb(0, r, g, min(255, max(0, 510 - i))));
}
