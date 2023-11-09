/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:02:32 by mde-sepi          #+#    #+#             */
/*   Updated: 2023/11/09 21:18:39 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	movement(t_vars *vars, int keycode)
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
}

int	key_hook(int key, t_vars *vars)
{
	if (key == 13 || (key <= 2 && key >= 0) || key == 123 || key == 124)
		movement(vars, key);
	else if (key == 53)
		destroy(vars);
	else if (key == 46)
	{
		vars->win->minimap *= -1;
		character(vars->win, vars->you);
	}
	else if (key == 8)
	{
		vars->win->c *= -1;
		character(vars->win, vars->you);
	}
	else if (key == 257)
	{
		if (vars->you->speed == vars->win->sqr / 5)
			vars->you->speed = vars->win->sqr / 2;
		else
			vars->you->speed = vars->win->sqr / 5;
	}
	return (0);
}

int	render_new_frame(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->win->img, 0, 0);
	return (0);
}

int	destroy(t_vars *vars)
{
	int	i;

	free(vars->win->tex);
	free(vars->you);
	free(vars->win->ray);
	free(vars->win);
	i = -1;
	while (vars->map->map[i++])
		free(vars->map->map[i]);
	free(vars->map->map);
	free(vars->map);
	free(vars);
	exit(0);
}
