# include <cub3d.h>

void init_struct_check(t_check *check, char *map, t_matrice *matrice)
{
	check->map = ft_strdup_GC(map, &check->trash); //pas oublier de free
	check->EA = 0;
	check->NO = 0;
	check->SO = 0;
	check->WE = 0;
	check->C = 0;
	check->F = 0;
	check->wrong_spell = 0;
	check->is_map = 0;
	check->matrice = matrice;
}

void init_matrice(t_matrice *matrice, t_check *check)
{
	matrice->check = check;
	matrice->height = 0;
	matrice->width = 0;
	matrice->map = NULL;
	matrice->map_with_spaces = NULL;
	matrice->N = 0;
	matrice->S = 0;
	matrice->E = 0;
	matrice->W = 0;
	matrice->NO_path = NULL;
	matrice->SO_path = NULL;
	matrice->EA_path = NULL;
	matrice->WE_path = NULL;
	matrice->F = my_malloc(3, sizeof(int), &check->trash);
	matrice->C = my_malloc(3, sizeof(int), &check->trash);
	matrice->wrong_symbol = 0;
	matrice->player_sympbol = 0;
	matrice->pos_y_player = 0;
	matrice->pos_x_player = 0;
	matrice->orientation = '\0';
}
