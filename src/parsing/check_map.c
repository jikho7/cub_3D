# include <cub3d.h>

void check_map(t_matrice *matrice)
{
	int i = 0;
	int j = 0;

	// while (matrice->map[j])
	// {
	// 	i = 0;
	// 	while (matrice->map_with_spaces[j][i])
	// 	{
	// 		printf("map[%d][%d]: %c\n", j, i, matrice->map_with_spaces[j][i]);
	// 		i++;
	// 	}
	// 	j++;
	// }

	while (matrice->map[j])
	{
		i = 0;
		while (matrice->map[j][i])
		{
			//printf("char[%d][%d]: %c\n", j, i, matrice->map[j][i]);
			if (matrice->map[j][i] == 'N' || matrice->map[j][i] == 'E' || matrice->map[j][i] == 'S' || matrice->map[j][i] == 'W')
			{
			//	printf("player symbol++");
				matrice->player_sympbol++;
			}
			if (matrice->map[j][i] == 'N')
				matrice->N++;
			else if (matrice->map[j][i] == 'S')
			{
			//	printf("matrice S..\n");
				matrice->S++;
			}
			else if (matrice->map[j][i] == 'E')
				matrice->E++;
			else if (matrice->map[j][i] == 'W')
				matrice->W++;
			else if (matrice->map[j][i] != '1' && matrice->map[j][i] != '0' && matrice->map[j][i] != '\n')
			{
			//	printf("wrong symbol: %c\n", matrice->map[j][i]);
				matrice->wrong_symbol++;
			}
			i++;
		}
		j++;
	}
	if (matrice->N > 1 || matrice->S > 1 || matrice->E > 1 || matrice->W > 1 || matrice->player_sympbol > 1)
		error_msg(7);
	if (matrice->wrong_symbol != 0)
		error_msg(8);
	if (matrice->player_sympbol == 0)
		error_msg(13);
}
