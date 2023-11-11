/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:51:36 by jdefayes          #+#    #+#             */
/*   Updated: 2023/11/11 19:01:31 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	create_lst(t_parse **info, t_check *check)
{
	int		fd;
	t_parse	*new;
	char	*res;

	(void)info;
	new = NULL;
	fd = open(check->map, O_RDONLY);
	if (fd == -1)
		return (1);
	while (1)
	{
		res = (get_next_line(fd));
		new = lstnew(res, &check->gc);
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

	tmp = *info;
	if (tmp)
	{
		while (tmp->next != NULL)
		{
			tmp->content = ft_strtrim_gc(tmp->content, " \t", &check->gc);
			tmp = tmp->next;
		}
	}
}
