# include "../cub3d.h"
#include "mlx.h"

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		write(1, "error", 5);
	data->mlx_win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "CUB3D");
	data->img.img_ptr = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	return (0);
}

// void	info_display(t_data *data)
// {
// 	data->fra.zoom = "Zoom:";
// 	mlx_string_put(data->mlx, data->mlx_win, 0, 50, 0xffffff, data->fra.zoom);
// 	mlx_string_put(data->mlx, data->mlx_win, 50, 50, 0xffffff,
// 		fra_itoa(data->fra.z));
// }

// int	close_window(t_data *data)
// {
// 	(void)data;
// 	exit(0);
// 	return (0);
// }

// void	reject(void)
// {
// 	write(1, "Fractales:\n-> mandelbrot\n-> julia\n-> burning_ship\n", 50);
// 	exit(0);
// }
