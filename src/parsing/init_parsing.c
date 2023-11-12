/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:51:29 by jdefayes          #+#    #+#             */
/*   Updated: 2023/11/12 16:04:10 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_struct_check(t_check *check, char *map, t_mat *mat,
		t_parse *origin)
{
	(void)origin;
	check->map = ft_strdup_gc(map, &check->gc);
	check->ea = 0;
	check->no = 0;
	check->so = 0;
	check->we = 0;
	check->c = 0;
	check->f = 0;
	check->wrong_spell = 0;
	check->is_map = 0;
	check->mat = mat;
	check->origin = NULL;
}

void	init_mat(t_mat *mat, t_check *check)
{
	mat->check = check;
	mat->hei = 0;
	mat->wid = 0;
	mat->map = NULL;
	mat->map_space = NULL;
	mat->n = 0;
	mat->s = 0;
	mat->e = 0;
	mat->w = 0;
	mat->no_path = NULL;
	mat->so_path = NULL;
	mat->ea_path = NULL;
	mat->we_path = NULL;
	mat->f = my_malloc(3, sizeof(int), &check->gc);
	verif_malloc(mat->f);
	mat->c = my_malloc(3, sizeof(int), &check->gc);
	verif_malloc(mat->c);
	mat->wrong_symbol = 0;
	mat->player_sympbol = 0;
	mat->pos_y_player = 0;
	mat->pos_x_player = 0;
	mat->orientation = '\0';
}
