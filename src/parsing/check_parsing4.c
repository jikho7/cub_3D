/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:28:51 by jdefayes          #+#    #+#             */
/*   Updated: 2023/11/09 19:29:40 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	check_read_lst(t_check *check_lst)
{
	if (check_lst->NO > 1 || check_lst->EA > 1 || check_lst->SO > 1
		|| check_lst->WE > 1 || check_lst->F > 1 || check_lst->C > 1)
		error_msg(0);
	if (check_lst->NO == 0 || check_lst->EA == 0 || check_lst->SO == 0
		|| check_lst->WE == 0 || check_lst->F == 0 || check_lst->C == 0)
		error_msg(12);
}
