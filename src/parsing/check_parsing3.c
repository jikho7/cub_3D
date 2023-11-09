/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:17:53 by jdefayes          #+#    #+#             */
/*   Updated: 2023/11/09 21:03:49 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	check_spelling(t_parse **lst, t_check *check_lst)
{
	t_parse	*tmp;

	tmp = *lst;
	while (tmp->next != NULL)
	{
		if (ft_strncmp(tmp->content, "EA", 2) == 0
			|| ft_strncmp(tmp->content, "NO", 2) == 0
			|| ft_strncmp(tmp->content, "SO", 2) == 0
			|| ft_strncmp(tmp->content, "WE", 2) == 0)
		{
			if (ft_strncmp((tmp->content + 2), "./", 2) != 0)
			{
				check_lst->wrong_spell++;
			}
			else if (ft_strncmp((tmp->content + 2), "./", 2) == 0)
			{
				save_textures(tmp->content, check_lst);
			}
		}
		tmp = tmp->next;
	}
	if (check_lst->wrong_spell > 0)
	{
		error_msg(1);
	}
}

void	save_textures(char *str, t_check *check)
{
	if (str[0] == 'E')
	{
		check->mat->EA_path = my_malloc(ft_strlen(str), sizeof(char *),
				&check->trash);
		check->mat->EA_path = ft_strcpy(check->mat->EA_path, str + 2);
	}
	if (str[0] == 'S')
	{
		check->mat->SO_path = my_malloc(ft_strlen(str), sizeof(char *),
				&check->trash);
		check->mat->SO_path = ft_strcpy(check->mat->SO_path, str + 2);
	}
	if (str[0] == 'N')
	{
		check->mat->NO_path = my_malloc(ft_strlen(str), sizeof(char *),
				&check->trash);
		check->mat->NO_path = ft_strcpy(check->mat->NO_path, str + 2);
	}
	if (str[0] == 'W')
	{
		check->mat->WE_path = my_malloc(ft_strlen(str), sizeof(char *),
				&check->trash);
		check->mat->WE_path = ft_strcpy(check->mat->WE_path, str + 2);
	}
}

void	handle_c_norm(int *i, int *j, char **split, t_mat *matrice)
{
	char	sign_c[3];

	sign_c[0] = 'C';
	sign_c[1] = ' ';
	sign_c[2] = '\n';
	split[*i] = ft_strtrim_GC(split[*i], sign_c, &matrice->check->trash);
	save_f_c_info(1, matrice, *j, split[*i]);
	(*j)++;
	(*i)++;
}

void	save_f_c_info(int option, t_mat *matrice, int j, char *split)
{
	int	nb;

	nb = 0;
	nb = ft_atoi(split);
	if (nb < 0 || nb > 255)
	{
		error_msg(4);
	}
	if (option == 0)
		matrice->F[j] = nb;
	if (option == 1)
		matrice->C[j] = nb;
}

int	ft_is_str_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (1);
		}
		i++;
	}
	return (0);
}
