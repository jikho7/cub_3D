#include <cub3d.h>

static void fill_matrice(t_matrice *matrice, t_parse *tmp);
static void calloc_maps(t_matrice *matrice);
static void get_orientation(char c, t_matrice *matrice);

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
			break;
		}
	}
	fill_matrice(matrice, tmp);
}

static void fill_matrice(t_matrice *matrice, t_parse *tmp)
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
			if (tmp->content[i] == ' ')
			{
				matrice->map_with_spaces[j][i] = ' ';
				matrice->map[j][i] = '1';
			}
			else if (tmp->content[i] == 'N' || tmp->content[i] == 'S' || tmp->content[i] == 'E' || tmp->content[i] == 'W')
			{
				get_orientation(tmp->content[i], matrice);
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
		if (tmp->next != NULL)
			tmp = tmp->next;
	}
}

static void get_orientation(char c, t_matrice *matrice)
{
	if (c == 'N')
		matrice->orientation = 'N';
	if (c == 'S')
		matrice->orientation = 'S';
	if (c == 'W')
		matrice->orientation = 'W';
	if (c == 'E')
		matrice->orientation = 'E';
}

static void calloc_maps(t_matrice *matrice)
{
	int i;

	matrice->map = my_malloc(matrice->height + 1, sizeof(char *), &matrice->check->trash); //ft_calloc(sizeof(char *), (matrice->height + 1));
	matrice->map[matrice->height] = 0;
	matrice->map_with_spaces = my_malloc((matrice->height + 1), sizeof(char *), &matrice->check->trash);//ft_calloc(sizeof(char *), (matrice->height + 1));
	matrice->map_with_spaces[matrice->height] = 0;
	i = 0;
	while (i < matrice->height)
	{
		matrice->map[i] = my_malloc(matrice->width, sizeof(char), &matrice->check->trash);//ft_calloc(sizeof(char), (matrice->width));
		i++;
	}
	i = 0;
	while (i < matrice->height)
	{
		matrice->map_with_spaces[i] = my_malloc(matrice->width, sizeof(char), &matrice->check->trash);//ft_calloc(sizeof(char), (matrice->width));
		i++;
	}
}
