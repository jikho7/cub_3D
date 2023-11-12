/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:23:06 by jdefayes          #+#    #+#             */
/*   Updated: 2023/11/12 13:54:52 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	check_read_lst(t_check *check_lst)
{
	if (check_lst->no > 1 || check_lst->ea > 1 || check_lst->so > 1
		|| check_lst->we > 1 || check_lst->f > 1 || check_lst->c > 1)
		error_msg(0);
	if (check_lst->no == 0 || check_lst->ea == 0 || check_lst->so == 0
		|| check_lst->we == 0 || check_lst->f == 0 || check_lst->c == 0)
		error_msg(12);
}

void	size_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	if (i != 3)
		error_msg(4);
}
