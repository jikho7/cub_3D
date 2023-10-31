# include <cub3d.h>

t_matrice *parsing(char *map)
{
	t_parse *info = NULL;
	t_check check;
	t_matrice *matrice;
	t_parse *origin = NULL;

	init_struct_check(&check, map);
	matrice = malloc(sizeof(t_matrice));
	init_matrice(matrice);
	check_map_extension(map);

	create_lst(&info, &check);
	//display_lst(&info, "info");
	remove_empty_block(&info);
	//display_lst(&info, "after removed empty blocks");
	cpy_lst(&origin, &info);
	get_width(&info, matrice);

	strtrim_lst(&info);
	check_spaces_NSEW(&info);
	get_height(&info, matrice);
//	printf("width: %d, height: %d\n", matrice.width, matrice.height);
//	display_lst(&origin, "origin");
//	display_lst(&info, "info");
	// char * line_debug = info->content;
	// (void) line_debug;
	check_tex_extension(&info, &check);
	read_lst(&info, &check);
//	display_lst(&info, "before spelling\n");
	check_excess_info(&info);
	check_F_C(&info);
	reduce_spaces_to_one(&info);
	check_spelling(&info, &check);
	//display_lst(&origin, "ORIGIN\n");
	check_if_info_after_map(&info, &check);
	create_matrice(&origin, matrice);
	//printf("pX: %d, pY: %d\n", matrice.pos_x_player, matrice.pos_y_player);
	check_map(matrice);
	flood_fill(matrice);
	get_width2(matrice);
//	printf("orientation: %c\n", matrice->orientation);
	return (matrice);
}
