/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:38:53 by jdefayes          #+#    #+#             */
/*   Updated: 2023/11/10 00:30:56 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	flood_fill(t_mat *mat)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mat->map_space[j])
	{
		i = 0;
		while (mat->map_space[j][i])
		{
			if (mat->map_space[j][i] == '0'
				|| mat->map[j][i] == 'N' || mat->map[j][i] == 'E'
					|| mat->map[j][i] == 'S' || mat->map[j][i] == 'W')
				check_directions(mat, j, i);
			i++;
		}
		j++;
	}
}
