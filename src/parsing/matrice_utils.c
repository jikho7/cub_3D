#include <cub3d.h>

void get_width(t_parse **map, t_matrice *matrice)
{
	t_parse *tmp;
	int i;

	tmp = *map;
	while (tmp->next != NULL)
	{
		i = 0;
		while (tmp->content[i])
		{
			i++;
		}
		if (matrice->width < i)
		{
			matrice->width = i;
		}
		tmp = tmp->next;
	}
}

void get_width2(t_matrice *matrice)
{
	int i;
	int j;
	int max;

	j = 0;
	i = 0;
	max = 0;
	while (matrice->map[j][i])
	{
		i = 0;
		while (matrice->map[j][i])
		{
			i++;
		}
		if (i > max)
			max = i;
		j++;
	}
	matrice->width = max - 1;
}

void get_height(t_parse **map, t_matrice *matrice)
{
	t_parse *tmp;
	int i;

	tmp = *map;
	while (tmp->next != NULL)
	{
		// printf("%s\n", tmp->content);
		strtrim_matrice(*tmp, i, matrice->check);
		i = 0;
		// while (tmp->content[i] != '\0' && ft_strchr("01 NSWE", tmp->content[i]) != NULL)
		// {
		// 	++i;
		// }
		// if (tmp->content[i] != '\n' || tmp->content[i] != '\0')
		// {
		// 	// is not a line map
		// }
		// else if (tmp->content[i] == '\0')
		// 	matrice->height++;

		if (tmp->next != NULL && tmp->content[i] != '\t' && tmp->content[i] != '1' && tmp->content[i] != '0')
		{
			// printf("> %s\n", tmp->content);
			i = 0;
			tmp = tmp->next;
		}
		else if (tmp->next != NULL && (tmp->content[i] == '1' || tmp->content[i] == '0'))
		{
		//	printf(">> %s\n", tmp->content);
			matrice->height++;
			tmp = tmp->next;
		}
		else if (tmp->next != NULL && tmp->content[i] == '\n')
		tmp = tmp->next;
	}
	if (matrice->height == 0)
		error_msg(11);
}

void strtrim_matrice(t_parse info, int i, t_check *check)
{
	(void)i;
	char sign[] = {' '};
	t_parse cpy;

	cpy = info;
	cpy.content = ft_strtrim_GC(cpy.content, sign, &check->trash);
}
