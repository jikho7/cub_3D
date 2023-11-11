/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:17:53 by jdefayes          #+#    #+#             */
/*   Updated: 2023/11/11 16:54:51 by jdefayes         ###   ########.fr       */
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

void	save_textures(char *s, t_check *ch)
{
	if (s[0] == 'E')
	{
		ch->mat->ea_path = my_malloc(ft_strlen(s), sizeof(char *), &ch->gc);
		verif_malloc(ch->mat->ea_path);
		ft_strlcpy(ch->mat->ea_path, s + 2, ft_strlen(s + 2));
	}
	if (s[0] == 'S')
	{
		ch->mat->so_path = my_malloc(ft_strlen(s), sizeof(char *), &ch->gc);
		verif_malloc(ch->mat->so_path);
		ft_strlcpy(ch->mat->so_path, s + 2, ft_strlen(s + 2));
	}
	if (s[0] == 'N')
	{
		ch->mat->no_path = my_malloc(ft_strlen(s), sizeof(char *), &ch->gc);
		verif_malloc(ch->mat->no_path);
		ft_strlcpy(ch->mat->no_path, s + 2, ft_strlen(s + 2));
	}
	if (s[0] == 'W')
	{
		ch->mat->we_path = my_malloc(ft_strlen(s), sizeof(char *), &ch->gc);
		verif_malloc(ch->mat->we_path);
		ft_strlcpy(ch->mat->we_path, s + 2, ft_strlen(s + 2));
	}
}

void	handle_c_norm(int *i, int *j, char **split, t_mat *matrice)
{
	char	sign_c[3];

	sign_c[0] = 'C';
	sign_c[1] = ' ';
	sign_c[2] = '\n';
	split[*i] = ft_strtrim_gc(split[*i], sign_c, &matrice->check->gc);
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
		matrice->f[j] = nb;
	if (option == 1)
		matrice->c[j] = nb;
}
