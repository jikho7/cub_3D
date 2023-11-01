# include <cub3d.h>

static void save_textures(char *str, t_check *check);

void	check_excess_info(t_parse **info)
{
	t_parse *tmp;

	tmp = *info;
	while (tmp->next != NULL)
	{
		if (ft_strncmp(tmp->content, "EA ./", 5) == 0 || ft_strncmp(tmp->content, "EA", 2) == 0)
			tmp = tmp->next;
		else if (ft_strncmp(tmp->content, "NO ./", 5) == 0 || ft_strncmp(tmp->content, "NO", 2) == 0)
			tmp = tmp->next;
		else if (ft_strncmp(tmp->content, "SO ./", 5) == 0 || ft_strncmp(tmp->content, "SO", 2) == 0)
			tmp = tmp->next;
		else if (ft_strncmp(tmp->content, "WE ./", 5) == 0 || ft_strncmp(tmp->content, "WE", 2) == 0)
			tmp = tmp->next;
		else if (ft_strncmp(tmp->content, "F ./", 2) == 0 || ft_strncmp(tmp->content, "F", 1) == 0)
			tmp = tmp->next;
		else if (ft_strncmp(tmp->content, "C ", 2) == 0)
			tmp = tmp->next;
		else if (tmp->content[0] == '\n' || tmp->content[1] == '\0')
			tmp = tmp->next;
		else if (ft_strncmp(tmp->content, "1", 1) == 0 || ft_strncmp(tmp->content, "0", 1) == 0)
			tmp = tmp->next;
		else
		{
			//printf("tmp->content execive: %s\n", tmp->content);
			error_msg(5);
		}
	}
}

void check_if_info_after_map(t_parse **info, t_check *check)
{
	t_parse *tmp;

	tmp = *info;
	while (tmp->next != NULL)
	{
		while (tmp->content[0] != '1' && tmp->content[0] != '0')
		{
			if (check->is_map == 1)
				error_msg(6);
			tmp = tmp->next;
		}
		while (tmp->next != NULL && (tmp->content[0] == '1' || tmp->content[0] == '0'|| tmp->content[0] == '\n'))
		{
			check->is_map = 1;
			tmp = tmp->next;
		}
	}
}

void check_tex_extension(t_parse **info, t_check *check)
{
	(void)check;
	t_parse *tmp;
	int size;
	const char *cpy;

	tmp = *info;
	while (tmp->next != NULL)
	{
		size = ft_strlen(tmp->content);
		cpy = (tmp->content + (size - 5));
		//printf("tex exten: %s\n", tmp->content);
		if ((strncmp(tmp->content, "EA", 2) == 0 || strncmp(tmp->content, "NO", 2) == 0 ||strncmp(tmp->content, "SO", 2) == 0 || strncmp(tmp->content, "WE", 2) == 0))
		{
			if (strncmp(cpy, ".xpm", 4) != 0 && (strncmp(cpy, ".png", 4) != 0))
				error_msg(3);
		}
		tmp = tmp->next;
	}
}

void check_map_extension(char *map_name)
{
	int size;
	const char *cpy;

	size = ft_strlen(map_name);
	//printf("map name: %c\n", map_name[size - 5]);
	cpy = (map_name + (size - 4));
//	printf("cpy: %s\n", cpy);
	if (ft_strncmp(cpy, ".cub", 4) != 0)
	 	error_msg(2);
	if (map_name[size - 5] == '/' || map_name[size - 5] == '.')
		error_msg(2);
}

void check_spelling(t_parse **lst, t_check *check_lst)
{
	t_parse *tmp;

	tmp = *lst;
	while (tmp->next != NULL)
	{
		if (ft_strncmp(tmp->content, "EA", 2) == 0 || ft_strncmp(tmp->content, "NO", 2) == 0 || ft_strncmp(tmp->content, "SO", 2) == 0 || ft_strncmp(tmp->content, "WE", 2) == 0)
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

static void save_textures(char *str, t_check *check)
{
	if (str[0] == 'E')
	{
		check->matrice->EA_path = my_malloc(ft_strlen(str), sizeof(char*), &check->trash);
		check->matrice->EA_path = ft_strcpy(check->matrice->EA_path, str + 2);
	}
	if (str[0] == 'S')
	{
		check->matrice->SO_path = my_malloc(ft_strlen(str), sizeof(char*), &check->trash);
		check->matrice->SO_path = ft_strcpy(check->matrice->SO_path, str + 2);
	}
	if (str[0] == 'N')
	{
		check->matrice->NO_path = my_malloc(ft_strlen(str), sizeof(char*), &check->trash);
		check->matrice->NO_path = ft_strcpy(check->matrice->NO_path, str + 2);
	}
	if (str[0] == 'W')
	{
		check->matrice->WE_path = my_malloc(ft_strlen(str), sizeof(char*), &check->trash);
		check->matrice->WE_path = ft_strcpy(check->matrice->WE_path, str + 2);
	}
}

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s2)
		return (NULL);
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s2);
}
