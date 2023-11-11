/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:51:10 by jdefayes          #+#    #+#             */
/*   Updated: 2023/11/11 16:43:34 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	control_symbol(t_mat *mat);
static void	go_through_map(t_mat *mat, int *j);

void	check_map(t_mat *mat)
{
	int	j;

	j = 0;
	while (mat->map[j])
	{
		go_through_map(mat, &j);
		j++;
	}
	control_symbol(mat);
}

static void	go_through_map(t_mat *mat, int *j)
{
	int	i;

	i = 0;
	while (mat->map[*j][i])
	{
		if (mat->map[*j][i] == 'N' || mat->map[*j][i] == 'E'
			|| mat->map[*j][i] == 'S' || mat->map[*j][i] == 'W')
			mat->player_sympbol++;
		if (mat->map[*j][i] == 'N')
			mat->n++;
		else if (mat->map[*j][i] == 'S')
			mat->s++;
		else if (mat->map[*j][i] == 'E')
			mat->e++;
		else if (mat->map[*j][i] == 'W')
			mat->w++;
		else if (mat->map[*j][i] != '1' && mat->map[*j][i] != '0'
			&& mat->map[*j][i] != '\n')
			mat->wrong_symbol++;
		i++;
	}
}

static void	control_symbol(t_mat *mat)
{
	if (mat->n > 1 || mat->s > 1 || mat->e > 1 || mat->w > 1
		|| mat->player_sympbol > 1)
		error_msg(7);
	if (mat->wrong_symbol != 0)
		error_msg(8);
	if (mat->player_sympbol == 0)
		error_msg(13);
}
