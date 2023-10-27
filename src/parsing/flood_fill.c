# include <cub3d.h>

int check_up(t_matrice *matrice, int pos_y, int pos_x);
int check_directions(t_matrice *matrice, int pos_y, int pos_x);
int check_left(t_matrice *matrice, int pos_y, int pos_x);
int check_right(t_matrice *matrice, int pos_y, int pos_x);
int check_down(t_matrice *matrice, int pos_y, int pos_x);

void flood_fill(t_matrice *matrice)
{
	int i;
	int j;

	i = 0;
	j = 0;
//	printf("flloo\n");
	while (matrice->map_with_spaces[j])
	{
		i = 0;
		while (matrice->map_with_spaces[j][i])
		{
			if (matrice->map_with_spaces[j][i] == '0' || matrice->map[j][i] == 'N' || matrice->map[j][i] == 'E' || matrice->map[j][i] == 'S' || matrice->map[j][i] == 'W')
				check_directions(matrice, j, i);
			i++;
		}
		j++;
	}
}

int check_directions(t_matrice *matrice, int pos_y, int pos_x)
{
	//printf("pos_y: %d, pos_x: %d\n", pos_y, pos_x);
	if (check_left(matrice, pos_y, pos_x) == 1)
	{
		//printf("left error\n");
		error_msg(9);
	}
	if (check_right(matrice, pos_y, pos_x) == 1)
	{
		//printf("right error\n");
		error_msg(9);
	}
	if (check_up(matrice, pos_y, pos_x) == 1)
	{
		//printf("up error\n");
		error_msg(9);
	}
	if (check_down(matrice, pos_y, pos_x) == 1)
	{
		//printf("down error\n");
		error_msg(9);
	}
	return (0);
}

int check_left(t_matrice *matrice, int pos_y, int pos_x)
{
	while(pos_x >= 0)
	{
		//printf("left : %c\n ", matrice->map[pos_y][pos_x]);
		if (matrice->map_with_spaces[pos_y][pos_x] == '1')
		{
			//printf("left char: %c\n ", matrice->map[pos_y][pos_x]);
			return (0);
		}
		if (matrice->map_with_spaces[pos_y][pos_x] == ' ')
			return (1);
		pos_x--;
	}
	return (1);
}

int check_right(t_matrice *matrice, int pos_y, int pos_x)
{
	while(pos_x < matrice->width)
	{
		//printf("right: %c\n ", matrice->map[pos_y][pos_x]);
		if (matrice->map_with_spaces[pos_y][pos_x] == '1')
		{
		//	printf("right char: %c\n ", matrice->map[pos_y][pos_x]);
			return (0);
		}
		if (matrice->map_with_spaces[pos_y][pos_x] == ' ')
		{
			return (1);
		}
		pos_x++;
	}
	return (1);
}

int check_up(t_matrice *matrice, int pos_y, int pos_x)
{
	while(pos_y >= 0)
	{
		//printf("up: %c\n ", matrice->map[pos_y][pos_x]);
		if (matrice->map_with_spaces[pos_y][pos_x] == '1')
		{
		//	printf("up char: %c\n ", matrice->map[pos_y][pos_x]);
			return (0);
		}
		if (matrice->map_with_spaces[pos_y][pos_x] == ' ')
			return (1);
		pos_y--;
	}
	return (1);
}

int check_down(t_matrice *matrice, int pos_y, int pos_x)
{
	while(pos_y < matrice->height)
	{
		//printf("down: %c\n ", matrice->map[pos_y][pos_x]);
		if (matrice->map_with_spaces[pos_y][pos_x] == '1')
		{
		//	printf("down char: %c\n ", matrice->map[pos_y][pos_x]);
			return (0);
		}
		if (matrice->map_with_spaces[pos_y][pos_x] == ' ')
			return (1);
		pos_y++;
	}

	return (1);
}
