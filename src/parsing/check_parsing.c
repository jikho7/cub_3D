# include <cub3d.h>

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
		else if (*tmp->content == '\n')
			tmp = tmp->next;
		else if (ft_strncmp(tmp->content, "1", 1) == 0 || ft_strncmp(tmp->content, "0", 1) == 0)
			tmp = tmp->next;
		else if (*tmp->content == EOF)
			tmp = tmp->next;
		else
		{
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

void check_F_C(t_parse **info)
{
	t_parse *tmp;
	int size;
	int i;

	tmp = *info;
	size = 0;
	printf("%d\n", size);
	while(tmp->next != NULL)
	{
		i = 0;
		size = ft_strlen(tmp->content);
		if (strncmp(tmp->content, "F", 1) == 0 || strncmp(tmp->content, "C", 1) == 0)
		{
			strtrim_F_C(*tmp, i);
		}
		tmp = tmp->next;
	}
}

void strtrim_F_C(t_parse info, int i)
{
	char sign[] = {'F', 'C', ' ', '\n'};
	t_parse cpy;
	char **split;

	cpy = info;
	cpy.content = ft_strtrim(cpy.content, sign);
	split = ft_split(cpy.content, ',');
	while (split[i])
	{
		if (ft_is_str_digit(split[i]) == 1)
		{
			error_msg(4);
		}
		i++;
	}
}

int ft_is_str_digit(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (1);
		}
		i++;
	}
	return (0);
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
		if ((strncmp(tmp->content, "EA", 2) == 0 || strncmp(tmp->content, "NO", 2) == 0 ||strncmp(tmp->content, "SO", 2) == 0 || strncmp(tmp->content, "WE", 2) == 0) && (strncmp(cpy, ".png", 4) != 0))
		{
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
	cpy = (map_name + (size - 4));
	if (ft_strncmp(cpy, ".cub", 4) != 0)
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
            if (ft_strncmp((tmp->content + 3), "./", 2) != 0)
            {
			    check_lst->wrong_spell++;
            }
		}
		tmp = tmp->next;
	}
	if (check_lst->wrong_spell > 0)
	{
		error_msg(1);
	}
}