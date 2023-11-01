#include <cub3d.h>

void get_data_sprites()
{


}

void create_struct_sprites(t_data *win, t_vars *vars)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (i == 0)
			win->tex[i].path = "./xpm/Wall_North.xpm";
		else if (i == 1)
			win->tex[i].path = "./xpm/Wall_South.xpm";
		else if (i == 2)
			win->tex[i].path = "./xpm/Wall_West.xpm";
		else if (i == 3)
			win->tex[i].path = "./xpm/Wall_East.xpm";
		i++;
	}
	i = 0;
	while (i < 4)
	{
		win->tex[i].img_ptr = mlx_xpm_file_to_image(vars->mlx, win->tex[i].path, &win->tex[i].width, &win->tex[i].height);
		if (!win->tex[i].img_ptr)
		{
			printf("Error: Texture not found: %s\n", win->tex[i].path);
			//exit(EXIT_FAILURE);
		}
		else
			win->tex[i].addr = mlx_get_data_addr(win->tex[i].img_ptr, &win->tex[i].bpp, &win->tex[i].line_len, &win->tex[i].endian);
		i++;
		// if (win->tex[i]texture->img->height != texture->img->width)
		// {
		// 		printf("Error: Texture not square: %s\n",  win->tex[i].path);
		// 	//exit(EXIT_FAILURE);
		// }
	}
	i = 0;
	while (i < 4)
	{
		printf("bpp: %d\n line_len: %d\n", win->tex[i].bpp, win->tex[i].line_len);
		i++;
	}
}
