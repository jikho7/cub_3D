/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:51:36 by jdefayes          #+#    #+#             */
/*   Updated: 2023/11/10 00:49:55 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	create_lst(t_parse **info, t_check *check)
{
	int		fd;
	t_parse	*new;

	new = NULL;
	fd = open(check->map, O_RDONLY);
	if (fd == -1)
		return (1);
	while (1)
	{
		new = lstnew(get_next_line(fd), &check->gc);
		add_back(info, new);
		if (new->content == NULL)
			break ;
	}
	return (0);
}

void	cpy_lst(t_parse **dest_lst, t_parse **src_lst, t_check *check)
{
	t_parse	*s_tmp;
	t_parse	*tmp;

	tmp = NULL;
	s_tmp = *src_lst;
	if (s_tmp)
	{
		while (s_tmp->next != NULL)
		{
			tmp = lstnew(s_tmp->content, &check->gc);
			add_back(dest_lst, tmp);
			s_tmp = s_tmp->next;
		}
	}
	else
	{
		*src_lst = NULL;
		error_msg(10);
	}
}

void	strtrim_lst(t_parse **info, t_check *check)
{
	t_parse	*tmp;
	char	sign[2];

	sign[0] = ' ';
	sign[1] = '\t';
	tmp = *info;
	while (tmp->next != NULL)
	{
		tmp->content = ft_strtrim_gc(tmp->content, sign, &check->gc);
		tmp = tmp->next;
	}
}
