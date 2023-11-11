/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:51:48 by jdefayes          #+#    #+#             */
/*   Updated: 2023/11/11 16:48:18 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	parsing2(t_parse *info, t_check check, t_mat *mat, t_parse *origin);

t_mat	*parsing(char *map, t_vars *vars)
{
	t_parse	*info;
	t_mat	*mat;

	vars->check.gc = NULL;
	info = NULL;
	mat = NULL;
	mat = my_malloc(1, sizeof(t_mat), &vars->check.gc);
	if (mat == NULL)
		return (NULL);
	init_struct_check(&vars->check, map, mat, vars->check.origin);
	init_mat(mat, &vars->check);
	check_map_extension(map);
	create_lst(&info, &vars->check);
	remove_empty_block(&info);
	cpy_lst(&vars->check.origin, &info, &vars->check);
	get_width(&info, mat);
	strtrim_lst(&info, &vars->check);
	parsing2(info, vars->check, mat, vars->check.origin);
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

void	free_parsing(t_parse *origin, t_check check)
{
	while (origin->next != NULL)
	{
		free(origin->content);
		origin = origin->next;
	}
	free(origin->content);
	ft_lstclear(&check.gc, free);
	check.gc = NULL;
}
