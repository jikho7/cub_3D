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

int	move(t_data *win, t_player *you, float addX, float addY)
{
	if (cancle(you->pos.x + addX * you->speed, you->pos.y + addY * you->speed, win))
		return (1);
	you->pos.x += addX * you->speed;
	you->pos.y += addY * you->speed;
	win->forward = 0;
	character(win, you);
	return (0);
}

void	turn(t_data *win, t_player *you, int clockwise)
{
	float	angle;
	float	tdirx;

	angle = M_PI / 12;
	tdirx = you->dir.x * cos(clockwise * angle) - you->dir.y * sin(clockwise * angle);
	you->dir.y = you->dir.y * cos(clockwise * angle) + you->dir.x * sin(clockwise * angle);
	you->dir.x = tdirx;
	you->plane.x = you->dir.y;
	you->plane.y = you->dir.x;
	win->forward = 1;
	character(win, you);
}