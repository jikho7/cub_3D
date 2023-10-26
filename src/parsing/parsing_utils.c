# include <cub3d.h>



void init_matrice(t_matrice *matrice)
{
	matrice->height = 0;
	matrice->width = 0;
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
		//printf("%s\n", tmp->content);
		strtrim_matrice(*tmp, i);
		i = 0;
		if (tmp->next != NULL && tmp->content[i] != '\t' && tmp->content[i] != '1' && tmp->content[i] != '0')
		{
		   // printf("> %s\n", tmp->content);
			i = 0;
			tmp = tmp->next;
		}
		else if (tmp->next != NULL && (tmp->content[i] == '1' || tmp->content[i] == '0'))
		{
		   // printf(">> %s\n", tmp->content);
			matrice->height++;
			tmp = tmp->next;
		}
		else if (tmp->next != NULL && tmp->content[i] == '\n')
			tmp = tmp->next;
	}
}

void strtrim_matrice(t_parse info, int i)
{
	(void)i;
	char sign[] = {' '};
	t_parse cpy;

	cpy = info;
	cpy.content = ft_strtrim(cpy.content, sign);
}

char** create_matrice(t_parse **origin, t_matrice *matrice)
{
	t_parse *tmp;
	int i;
	int j;
	char **tab;
	int fuck = 0;

	j = 0;
	tmp = *origin;
	tab = ft_calloc(sizeof(char *), (matrice->height + 1));
	tab[matrice->height] = 0;
	i = 0;
	while(i < matrice->height)
	{
		tab[i] = ft_calloc(sizeof(char), (matrice->width));
		i++;
	}

	while(tmp->next != NULL)
	{
		while (tmp->content[i])
		{
			if (tmp->content[i] != ' ' && tmp->content[i] != '0' && tmp->content[i] != '1')
			{
				printf("loop fuck: %s\n", tmp->content);
				i = 0;
				break;
				tmp = tmp->next;
			}
			i++;
		}
		if (fuck == 1)
			break;
		tmp = tmp->next;
	}
	printf("out loop fuck: %s\n", tmp->content);
	while (tmp->next != NULL)
	{
		while (tmp->content[i])
		{
			if (tmp->content[i] == ' ')
				tab[j][i] = '1';
			else
				tab[j][i] = tmp->content[i];
			i++;
		}
		j++;
		tmp = tmp->next;
		i = 0;
	}
	j = 0;
	// i = matrice->height;
	// while (i >= 0)
	// {
	// 	printf("tab[%d]: %s\n", j, tab[j]);
	// 	j++;
	// 	i--;
	// }
	return (tab);
}
