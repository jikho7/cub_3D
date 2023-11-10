/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:51:48 by jdefayes          #+#    #+#             */
/*   Updated: 2023/11/10 01:03:35 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	parsing2(t_parse *info, t_check check, t_mat *mat, t_parse *origin);

t_mat	*parsing(char *map)
{
	t_parse	*info;
	t_check	check;
	t_mat	*mat;
	t_parse	*origin;

	check.gc = NULL;
	info = NULL;
	mat = NULL;
	origin = NULL;
	mat = my_malloc(1, sizeof(t_mat), &check.gc);
	if (mat == NULL)
		return (NULL);
	init_struct_check(&check, map, mat);
	init_mat(mat, &check);
	check_map_extension(map);
	create_lst(&info, &check);
	remove_empty_block(&info);
	cpy_lst(&origin, &info, &check);
	get_width(&info, mat);
	strtrim_lst(&info, &check);
	parsing2(info, check, mat, origin);
	return (mat);
}

static void	parsing2(t_parse *info, t_check check, t_mat *mat, t_parse *origin)
{
	check_spaces_nsew(&info);
	get_height(&info, mat);
	check_tex_extension(&info, &check);
	read_lst(&info, &check);
	check_excess_info(&info);
	check_f_c(&info, mat);
	reduce_spaces_to_one(&info, &check);
	check_spelling(&info, &check);
	check_if_info_after_map(&info, &check);
	create_mat(&origin, mat);
	check_map(mat);
	flood_fill(mat);
	get_width2(mat);
}

int	verif_malloc(void *malloc)
{
	if (malloc == NULL)
		error_msg(15);
	return (0);
}
