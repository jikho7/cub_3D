/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:02:32 by mde-sepi          #+#    #+#             */
/*   Updated: 2023/10/31 19:33:58 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 13)
		move(vars->win, vars->you, vars->you->dir.x, -vars->you->dir.y);
	else if (keycode == 1)
		move(vars->win, vars->you, -vars->you->dir.x, vars->you->dir.y);
	else if (keycode == 0)
		move(vars->win, vars->you, -vars->you->dir.y, -vars->you->dir.x);
	else if (keycode == 2)
		move(vars->win, vars->you, vars->you->dir.y, vars->you->dir.x);
	else if (keycode == 123)
		turn(vars->win, vars->you, 1);
	else if (keycode == 124)
		turn(vars->win, vars->you, -1);
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
	return (0);
}

int	mouse_hook(int mousecode, int i, int j, t_data *win)
{
	if (mousecode == 1)
		printf("(i,j) = (%d,%d)\n", i, j);
	(void) win;
	return (0);
}

int	render_new_frame(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->win->img, 0, 0);
	return (0);
}

int	destroy(t_vars *vars)
{
	printf("GO\n");
	free(vars->map);
	printf("GOO\n");
	free(vars->you);
	printf("GOOD\n");
	free(vars->win);
	printf("GOODB\n");
	free(vars);
	printf("GOODBYE\n");
	exit(0);
}
