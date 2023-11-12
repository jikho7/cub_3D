/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:51:15 by jdefayes          #+#    #+#             */
/*   Updated: 2023/11/12 14:03:30 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	read_lst2(t_parse *tmp, t_check *check_lst);

void	read_lst(t_parse **lst, t_check *check_lst)
{
	t_parse	*tmp;

	tmp = *lst;
	while (tmp->next != NULL)
	{
		if (ft_strncmp(tmp->content, "EA ./", 5) == 0
			|| ft_strncmp(tmp->content, "EA", 2) == 0)
			check_lst->ea++;
		if (ft_strncmp(tmp->content, "NO ./", 5) == 0
			|| ft_strncmp(tmp->content, "NO", 2) == 0)
			check_lst->no++;
		if (ft_strncmp(tmp->content, "SO ./", 5) == 0
			|| ft_strncmp(tmp->content, "SO", 2) == 0)
			check_lst->so++;
		else
			read_lst2(tmp, check_lst);
		tmp = tmp->next;
	}
	check_read_lst(check_lst);
}

static void	read_lst2(t_parse *tmp, t_check *check_lst)
{
	if (ft_strncmp(tmp->content, "WE ./", 5) == 0
		|| ft_strncmp(tmp->content, "WE", 2) == 0)
		check_lst->we++;
	if (ft_strncmp(tmp->content, "F ", 2) == 0
		|| ft_strncmp(tmp->content, "F", 1) == 0)
		check_lst->f++;
	if (ft_strncmp(tmp->content, "C ", 2) == 0
		|| ft_strncmp(tmp->content, "C", 1) == 0)
		check_lst->c++;
}

void	check_f_c(t_parse **info, t_mat *matrice)
{
	t_parse	*tmp;
	int		size;
	char	*cpy;

	tmp = *info;
	size = 0;
	while (tmp->next != NULL)
	{
		if (ft_strncmp(tmp->content, "F", 1) == 0
			|| ft_strncmp(tmp->content, "C", 1) == 0)
		{
			cpy = ft_strdup(tmp->content);
			strtrim_f_c(cpy, matrice);
			free(cpy);
		}
		tmp = tmp->next;
	}
}

void	strtrim_f_c(char *str, t_mat *matrice)
{
	int		i;
	char	**split;
	int		j;

	split = ft_split_gc(str, ',', &matrice->check->gc);
	size_split(split);
	i = 0;
	j = 0;
	while (split[i])
	{
		if (split[i][0] == 'F')
		{
			while (j <= 2)
				handle_f_norm(&j, &i, split, matrice);
		}
		else if (split[i][0] == 'C')
		{
			while (j <= 2)
				handle_c_norm(&j, &i, split, matrice);
		}
		j = 0;
	}
}

void	handle_f_norm(int *i, int *j, char **split, t_mat *matrice)
{
	split[*i] = ft_strtrim_gc(split[*i], "F \n", &matrice->check->gc);
	save_f_c_info(0, matrice, *j, split[*i]);
	(*j)++;
	(*i)++;
}
