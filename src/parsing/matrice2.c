/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:35:31 by jdefayes          #+#    #+#             */
/*   Updated: 2023/11/09 20:35:58 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_parse	*go_through_no_map_char(t_parse *tmp, int i)
{
	while (tmp->next != NULL)
	{
		i = 0;
		while (tmp->content[i])
		{
			if (tmp->content[i] != ' ' && tmp->content[i] != '0'
				&& tmp->content[i] != '1' && tmp->content[i] != '\n'
				&& tmp->content[i] != 'N' && tmp->content[i] != 'S'
				&& tmp->content[i] != 'W' && tmp->content[i] != 'E')
			{
				i = 0;
				tmp = tmp->next;
				break ;
			}
			i++;
		}
		if (tmp->content[0] == '\n')
		{
			i = 0;
			tmp = tmp->next;
		}
		else if (tmp->content[i] == '\0')
			break ;
	}
	return (tmp);
}
