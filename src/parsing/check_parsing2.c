/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:51:15 by jdefayes          #+#    #+#             */
/*   Updated: 2023/11/09 20:58:05 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	save_f_c_info(int option, t_mat *matrice, int j, char *split);
void	handle_c_norm(int *j, int *i, char **split, t_mat *matrice);
void	handle_f_norm(int *i, int *j, char **split, t_mat *matrice);
void	size_split(char **split);

void	read_lst(t_parse **lst, t_check *check_lst)
{
	t_parse	*tmp;

	tmp = *lst;
	while (tmp->next != NULL)
	{
		if (ft_strncmp(tmp->content, "EA ./", 5) == 0
			|| ft_strncmp(tmp->content, "EA", 2) == 0)
			check_lst->EA++;
		if (ft_strncmp(tmp->content, "NO ./", 5) == 0
			|| ft_strncmp(tmp->content, "NO", 2) == 0)
			check_lst->NO++;
		if (ft_strncmp(tmp->content, "SO ./", 5) == 0
			|| ft_strncmp(tmp->content, "SO", 2) == 0)
			check_lst->SO++;
		if (ft_strncmp(tmp->content, "WE ./", 5) == 0
			|| ft_strncmp(tmp->content, "WE", 2) == 0)
			check_lst->WE++;
		if (ft_strncmp(tmp->content, "F ", 2) == 0
			|| ft_strncmp(tmp->content, "F", 1) == 0)
			check_lst->F++;
		if (ft_strncmp(tmp->content, "C ", 2) == 0
			|| ft_strncmp(tmp->content, "C", 1) == 0)
			check_lst->C++;
		tmp = tmp->next;
	}
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
		if (strncmp(tmp->content, "F", 1) == 0
			|| strncmp(tmp->content, "C", 1) == 0)
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

	split = ft_split_GC(str, ',', &matrice->check->trash);
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
	printf("i: %d\n", i);
}

void	size_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		i++;
	}
	if (i != 3)
		error_msg(4);
}

void	handle_f_norm(int *i, int *j, char **split, t_mat *matrice)
{
	char	sign_f[3];

	sign_f[0] = 'F';
	sign_f[1] = ' ';
	sign_f[2] = '\n';
	split[*i] = ft_strtrim_GC(split[*i], sign_f, &matrice->check->trash);
	save_f_c_info(0, matrice, *j, split[*i]);
	(*j)++;
	(*i)++;
}
