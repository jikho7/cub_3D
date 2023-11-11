/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:51:36 by jdefayes          #+#    #+#             */
/*   Updated: 2023/11/11 12:54:24 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void add_trash(t_list* trash, t_check *check);

int	create_lst(t_parse **info, t_check *check)
{
	(void)info;
	int		fd;
	t_parse	*new;
	char *res;

	new = NULL;
	fd = open(check->map, O_RDONLY);
	if (fd == -1)
		return (1);
	while (1)
	{
		res = (get_next_line(fd));

		new = lstnew(res, &check->gc);
		//add_back((t_parse**)check->gc, (t_parse*)new);
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

// int create_lst(t_parse **info, t_check *check)
// {
//     int fd;
//     t_parse *new = NULL;

//     fd = open(check->map, O_RDONLY);
//     if(fd == -1)
//         return (1);
//     while(1)
//     {
//         new = lstnew(get_next_line(fd), &check->trash);
//         add_trash(new, &check->trash);
//     //    printf("new->content[0]: %c\n", new->content[0]);
//         add_back(info, new);
//         if (new->content == NULL)
//             break;
//     }
//     //display_lst(info, "map");
//     return (0);
// }

// void add_trash(t_parse *element, t_list **trash)
// {
//     add_back((t_parse **)trash, element);
// }

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
