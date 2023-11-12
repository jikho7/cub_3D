/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:51:41 by jdefayes          #+#    #+#             */
/*   Updated: 2023/11/09 18:08:34 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	fill_mat(t_mat *mat, t_parse *tmp);
static void	calloc_maps(t_mat *mat);
static void	get_orientation(char c, t_mat *mat);
static void	filling_matrice(char c, t_mat *mat, int j, int i);

void	create_mat(t_parse **origin, t_mat *mat)
{
	t_parse	*tmp;
	int		i;

	tmp = *origin;
	calloc_maps(mat);
	i = 0;
	tmp = go_through_no_map_char(tmp, i);
	check_if_space_in_map(tmp, mat);
	fill_mat(mat, tmp);
}

static void	fill_mat(t_mat *mat, t_parse *tmp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mat->hei > j)
	{
		i = 0;
		while (tmp->content[i])
		{
			filling_matrice(tmp->content[i], mat, j, i);
			i++;
		}
		j++;
		if (tmp->next != NULL)
			tmp = tmp->next;
	}
}

static void	filling_matrice(char c, t_mat *mat, int j, int i)
{
	if (c == ' ')
	{
		mat->map_space[j][i] = ' ';
		mat->map[j][i] = '1';
	}
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		get_orientation(c, mat);
		mat->pos_x_player = i + 1;
		mat->pos_y_player = j + 1;
		mat->map[j][i] = c;
		mat->map_space[j][i] = '0';
	}
	else
	{
		mat->map[j][i] = c;
		mat->map_space[j][i] = c;
	}
}

static void	get_orientation(char c, t_mat *mat)
{
	if (c == 'N')
		mat->orientation = 'N';
	if (c == 'S')
		mat->orientation = 'S';
	if (c == 'W')
		mat->orientation = 'W';
	if (c == 'E')
		mat->orientation = 'E';
}

static void	calloc_maps(t_mat *mat)
{
	int	i;

	mat->map = my_malloc(mat->hei + 1, sizeof(char *), &mat->check->gc);
	verif_malloc(mat->map);
	mat->map[mat->hei] = 0;
	mat->map_space = my_malloc((mat->hei + 1), sizeof(char *),
			&mat->check->gc);
	verif_malloc(mat->map_space);
	mat->map_space[mat->hei] = 0;
	i = -1;
	while (++i < mat->hei)
	{
		mat->map[i] = my_malloc(mat->wid + 1, sizeof(char), &mat->check->gc);
		verif_malloc(mat->map[i]);
	}
	i = -1;
	while (++i < mat->hei)
	{
		mat->map_space[i] = my_malloc(mat->wid + 1, sizeof(char),
				&mat->check->gc);
		verif_malloc(mat->map_space[i]);
	}
}
