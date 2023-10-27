#include <cub3d.h>

void fill_matrice(t_matrice *matrice, t_parse *tmp);
void calloc_maps(t_matrice *matrice);

void init_matrice(t_matrice *matrice)
{
	matrice->height = 0;
	matrice->width = 0;
	matrice->map = NULL;
	matrice->map_with_spaces = NULL;
	matrice->N = 0;
	matrice->S = 0;
	matrice->E = 0;
	matrice->W = 0;
	matrice->wrong_symbol = 0;
	matrice->player_sympbol = 0;
	matrice->pos_y_player = 0;
	matrice->pos_x_player = 0;
}

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
			matrice->width = i;
		tmp = tmp->next;
	}
}

void get_height(t_parse **map, t_matrice *matrice)
{
	t_parse *tmp;
	int i;

	tmp = *map;
	while (tmp->next != NULL)
	{
		// printf("%s\n", tmp->content);
		strtrim_matrice(*tmp, i);
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

void strtrim_matrice(t_parse info, int i)
{
	(void)i;
	char sign[] = {' '};
	t_parse cpy;

	cpy = info;
	cpy.content = ft_strtrim(cpy.content, sign);
}

void create_matrice(t_parse **origin, t_matrice *matrice)
{
	t_parse *tmp;
	int i;

	tmp = *origin;
	calloc_maps(matrice);
	while (tmp->next != NULL)
	{
		i = 0;
		while (tmp->content[i])
		{
			if (tmp->content[i] != ' ' && tmp->content[i] != '0' && tmp->content[i] != '1' && tmp->content[i] != '\n'
				&& tmp->content[i] != 'N' && tmp->content[i] != 'S' && tmp->content[i] != 'W' && tmp->content[i] != 'E')
			{
				i = 0;
				tmp = tmp->next;
				break;
			}
			i++;
		}
		if (tmp->content[0] == '\n') // && tmp->content[i] == '\n')
		{
			i = 0;
			tmp = tmp->next;
		}
		else if (tmp->content[i] == '\0')
		{
			printf("break\n");
			break;
		}
	}
	fill_matrice(matrice, tmp);
}

void fill_matrice(t_matrice *matrice, t_parse *tmp)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (matrice->height > j)
	{
		i = 0;
		while (tmp->content[i])
		{
			//printf("tmp->content[%d]: %c\n", i, tmp->content[i]);
			if (tmp->content[i] == ' ')
			{
				matrice->map_with_spaces[j][i] = ' ';
				matrice->map[j][i] = '1';
			}
			else if (tmp->content[i] == 'N' || tmp->content[i] == 'S' || tmp->content[i] == 'E' || tmp->content[i] == 'W')
			{
				// printf("check poS: i: %d, j: %d\n", i, j);
				matrice->pos_x_player = i + 1;
				matrice->pos_y_player = j + 1;
				matrice->map[j][i] = tmp->content[i];
				matrice->map_with_spaces[j][i] = '0';
			}
			else
			{
				matrice->map[j][i] = tmp->content[i];
				matrice->map_with_spaces[j][i] = tmp->content[i];
			}
			i++;
		}
		j++;
	//	printf("height: %d\n", matrice->height);
		if (tmp->next != NULL)
			tmp = tmp->next;
	}

	j = 0;
	i = matrice->height;
	while (i > 0)
	{
		printf("map[%d]: %s\n", j, matrice->map[j]);
		j++;
		i--;
	}
	j = 0;
	i = matrice->height;
	while (i > 0)
	{
		printf("map_spaces[%d]: %s\n", j, matrice->map_with_spaces[j]);
		j++;
		i--;
	}
}

void calloc_maps(t_matrice *matrice)
{
	int i;

	matrice->map = ft_calloc(sizeof(char *), (matrice->height + 1));
	matrice->map[matrice->height] = 0;
	matrice->map_with_spaces = ft_calloc(sizeof(char *), (matrice->height + 1));
	matrice->map_with_spaces[matrice->height] = 0;
	i = 0;
	while (i < matrice->height)
	{
		matrice->map[i] = ft_calloc(sizeof(char), (matrice->width));
		i++;
	}
	i = 0;
	while (i < matrice->height)
	{
		matrice->map_with_spaces[i] = ft_calloc(sizeof(char), (matrice->width));
		i++;
	}
}
