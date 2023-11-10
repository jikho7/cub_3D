/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:51:29 by jdefayes          #+#    #+#             */
/*   Updated: 2023/11/10 00:49:53 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_struct_check(t_check *check, char *map, t_mat *mat)
{
	check->map = ft_strdup_gc(map, &check->gc);
	check->EA = 0;
	check->NO = 0;
	check->SO = 0;
	check->WE = 0;
	check->C = 0;
	check->F = 0;
	check->wrong_spell = 0;
	check->is_map = 0;
	check->mat = mat;
}

void	init_mat(t_mat *mat, t_check *check)
{
	mat->check = check;
	mat->hei = 0;
	mat->wid = 0;
	mat->map = NULL;
	mat->map_space = NULL;
	mat->N = 0;
	mat->S = 0;
	mat->E = 0;
	mat->W = 0;
	mat->NO_path = NULL;
	mat->SO_path = NULL;
	mat->EA_path = NULL;
	mat->WE_path = NULL;
	mat->F = my_malloc(3, sizeof(int), &check->gc);
	verif_malloc(mat->F);
	mat->C = my_malloc(3, sizeof(int), &check->gc);
	verif_malloc(mat->C);
	mat->wrong_symbol = 0;
	mat->player_sympbol = 0;
	mat->pos_y_player = 0;
	mat->pos_x_player = 0;
	mat->orientation = '\0';
}
