# include <cub3d.h>

void cpy_lst(t_parse **dest_lst, t_parse **src_lst);
// remplacer le \n par \0?
int parsing(char *map)
{
	t_parse *info = NULL;
	t_check check;
	t_matrice matrice;
	t_parse *origin = NULL;

	init_struct_check(&check, map);
	init_matrice(&matrice);
	check_map_extension(map);

	create_lst(&info, &check);
	cpy_lst(&origin, &info);
	get_width(&info, &matrice);


	strtrim_lst(&info);
	get_height(&info, &matrice);
	printf("width: %d, height: %d\n", matrice.width, matrice.height);
//	display_lst(&origin, "origin");
//	display_lst(&info, "info");
	check_tex_extension(&info, &check);

	read_lst(&info, &check);
	check_excess_info(&info);
	check_F_C(&info);
	reduce_spaces_to_one(&info);
	//display_lst(&info, "before spelling\n");
	check_spelling(&info, &check);
	//display_lst(&info, "before check info after map\n");
	check_if_info_after_map(&info, &check);
	create_matrice(&origin, &matrice); // SEGFAULT
	// free(&info);
	// free(&check);
	// free(&matrice);
	return (0);
}

void cpy_lst(t_parse **dest_lst, t_parse **src_lst)
{
	t_parse *s_tmp;
	t_parse *tmp = NULL;

	s_tmp = *src_lst;
	while (s_tmp->next != NULL)
	{
		tmp = lstnew(s_tmp->content);
		add_back(dest_lst, tmp);
		s_tmp = s_tmp->next;
	}

}

void strtrim_lst(t_parse **info)
{
	t_parse *tmp;
	char sign[] = {' ', '\t'};

	tmp = *info;
	while (tmp->next != NULL)
	{
		tmp->content = ft_strtrim(tmp->content, sign);
		tmp = tmp->next;
	}
}

void read_lst(t_parse **lst, t_check *check_lst)
{
	t_parse *tmp;

	tmp = *lst;
	while (tmp->next != NULL)
	{
		if (ft_strncmp(tmp->content, "EA ./", 5) == 0 || ft_strncmp(tmp->content, "EA", 2) == 0)
			check_lst->EA++;
		if (ft_strncmp(tmp->content, "NO ./", 5) == 0|| ft_strncmp(tmp->content, "NO", 2) == 0)
			check_lst->NO++;
		if (ft_strncmp(tmp->content, "SO ./", 5) == 0|| ft_strncmp(tmp->content, "SO", 2) == 0)
			check_lst->SO++;
		if (ft_strncmp(tmp->content, "WE ./", 5) == 0|| ft_strncmp(tmp->content, "WE", 2) == 0)
			check_lst->WE++;
		if (ft_strncmp(tmp->content, "F ", 2) == 0|| ft_strncmp(tmp->content, "F", 1) == 0)
			check_lst->F++;
		if (ft_strncmp(tmp->content, "C ", 2) == 0|| ft_strncmp(tmp->content, "C", 1) == 0)
			check_lst->C++;
		tmp = tmp->next;
	}
	if (check_lst->NO > 1|| check_lst->EA > 1 || check_lst->SO > 1|| check_lst->WE > 1 || check_lst->F > 1 || check_lst->C > 1)
	{
		error_msg(0);
	}
}

void init_struct_check(t_check *check, char *map)
{
	check->map = ft_strdup(map);
	check->EA = 0;
	check->NO = 0;
	check->SO = 0;
	check->WE = 0;
	check->C = 0;
	check->F = 0;
	check->wrong_spell = 0;
	check->is_map = 0;
}

void error_msg(int option)
{
	if (option == 0)
		printf("Error: Doublon\n");
	if (option == 1)
		printf("Error: Wrong spelling\n");
	if (option == 2)
		printf("Error: Invalid extension\n");
	if (option == 3)
		printf("Error: Invalid texture extension\n");
	if (option == 4)
		printf("Error: Bad coordinates\n");
	if (option == 5)
		printf("Error: Excessive information\n");
	if (option == 6)
		printf("Error: Info after map\n");
	exit(0) ;
}