# include <cub3d.h>

int		create_lst(t_parse **info, t_check *check);
t_parse	*lstnew(char *str);
void	add_back(t_parse **head, t_parse *node_to_add);
void	is_valid(t_check *lst);
void	read_lst(t_parse **lst, t_check *check_lst);
void	init_struct_check(t_check *check, char *map);
void	check_spelling(t_parse **lst, t_check *check_lst);
void	error_msg(int option);
void	check_map_extension(char *name);
void	check_tex_extension(t_parse **info, t_check *check);
void	check_spelling(t_parse **lst, t_check *check_lst);
void	check_F_C(t_parse **info);
int		ft_is_str_digit(char *str);
void	check_if_info_after_map(t_parse **info, t_check *check);
void	strtrim_F_C(t_parse info, int i);
void	check_excess_info(t_parse **info);
void	strtrim_cub(t_parse info);

int parsing(char *map)
{
	t_parse *info = NULL;
	t_check check;

	init_struct_check(&check, map);
	//printf("1\n");
	check_map_extension(map);
	//printf("2\n");
	create_lst(&info, &check);
	//printf("3\n");
	read_lst(&info, &check);
	check_excess_info(&info);
	display_lst(&info, "check0");
	//printf("4\n");
	check_tex_extension(&info, &check);
	//display_lst(&info, "check1");
	check_F_C(&info);
	//display_lst(&info, "check2");
	//printf("5\n");
	check_spelling(&info, &check);
	//check_if_info_after_map(&info, &check);
	//display_lst(&info, "check3");
	//printf("6\n");
	is_valid(&check);
	//printf("7\n");
	return (0);
}

void	check_excess_info(t_parse **info)
{
	t_parse *tmp;
	char sign[] = {'\t', ' '};
	tmp = *info;
	while (tmp->next != NULL)
	{
		ft_strtrim(tmp->content, sign);
		if (ft_strncmp(tmp->content, "EA ", 3) == 0 || ft_strncmp(tmp->content, "EA", 2) == 0)
			tmp = tmp->next;
		else if (ft_strncmp(tmp->content, "NO ", 3) == 0 || ft_strncmp(tmp->content, "NO", 2) == 0)
			tmp = tmp->next;
		else if (ft_strncmp(tmp->content, "SO ", 3) == 0 || ft_strncmp(tmp->content, "SO", 2) == 0)
			tmp = tmp->next;
		else if (ft_strncmp(tmp->content, "WE ", 3) == 0 || ft_strncmp(tmp->content, "WE", 2) == 0)
			tmp = tmp->next;
		else if (ft_strncmp(tmp->content, "F ", 2) == 0)
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
		tmp = tmp->next;
	}
}

// void check_if_info_after_map(t_parse **info, t_check *check)
// {
// 	t_parse *tmp;
// 	int i;
// 	int j;
// 	i = 0;

// 	tmp = *info;
// 	while (tmp->next != NULL)
// 	{
// 		printf("BEGIN check line[%d]: %s\n", i, tmp->content);
// 		if (tmp->content[i] == ' ' || tmp->content[i] == '\t' || tmp->content[i] == '1' || tmp->content[i] == '0')
// 		{
// 			j = 0;
// 			while (tmp->content[j])
// 			{
// 				if (tmp->content[j] == '1' || tmp->content[j] == '0')
// 				{
// 					check->is_map = 1;
// 					break;
// 				}
// 				j++;
// 			}
// 			i++;
// 		}
// 		//if ((tmp->content[i] != ' ' || tmp->content[i] != '\t' || tmp->content[i] != '1' || tmp->content[i] != '0' || tmp->content[i] != '\n') && check->is_map == 1)
// 		printf(">>>check line: %c\n", tmp->content[i]);
// 		if ((tmp->content[i] != '0' && tmp->content[i] != '1' && tmp->content[i] != '\n' && tmp->content[i] != EOF && tmp->content[i] != ' ' && tmp->content[i] != '\t' && tmp->content[i] != '\0') && check->is_map == 1)
// 		{
// 			printf("check line: %c\n", tmp->content[i]);
// 			printf("Error: Smbol after map/n");
// 			return ;
// 		}
// 		tmp = tmp->next;
// 	}
// }

// void check_if_info_after_map(t_parse **info, t_check *check)
// {
// 	t_parse *tmp;
// 	int i;
// 	int j;
// 	i = 0;

// 	tmp = *info;
// 	while (tmp->next != NULL)
// 	{
// 		//printf("BEGIN check line[%d]: %s\n", i, tmp->content);
// 		if (tmp->content[i] == ' ' || tmp->content[i] == '\t' || tmp->content[i] == '\n')
// 		{
// 			while (tmp->content[i] == ' ' || tmp->content[i] == '\t' || tmp->content[i] == '\n')
// 				i++;
// 			if (tmp->content[i] == '1' || tmp->content[i] == '0')
// 			{
// 				check->is_map = 1;
// 				tmp = tmp->next;
// 			}
// 		//	if (check->EA == 1 || check->NO == 1 || check->SO == 1 || check->WE == 1)
// 		}
// 		if (check->is_map == 1 && ft_strncmp(tmp->content, "EA ", 3) == 0 || ft_strncmp(tmp->content, "EA", 2) == 0)
// 		if (ft_strncmp(tmp->content, "NO ", 3) == 0|| ft_strncmp(tmp->content, "NO", 2) == 0)
// 		if (ft_strncmp(tmp->content, "SO ", 3) == 0|| ft_strncmp(tmp->content, "SO", 2) == 0)
// 		if (ft_strncmp(tmp->content, "WE ", 3) == 0|| ft_strncmp(tmp->content, "WE", 2) == 0)
// 		if (ft_strncmp(tmp->content, "F ", 2) == 0|| ft_strncmp(tmp->content, "F", 1) == 0)
// 		if (ft_strncmp(tmp->content, "C ", 2) == 0|| ft_strncmp(tmp->content, "C", 1) == 0)
// 		tmp = tmp->next;
// 		//printf(">>>check line: %c\n", tmp->content[i]);
// 	}
// }

void check_F_C(t_parse **info)
{
	t_parse *tmp;
	int size;
//	char **split;
	int i;
	//char sign[] = {'F', 'C', ' ', '\n'};

	tmp = *info;
	while(tmp->next != NULL)
	{
		i = 0;
		size = ft_strlen(tmp->content);
		if (strncmp(tmp->content, "F", 1) == 0 || strncmp(tmp->content, "C", 1) == 0)
		{
			strtrim_F_C(*tmp, i);
			// tmp->content = ft_strtrim(tmp->content, sign);
			// split = ft_split(tmp->content, ',');
			// while (split[i])
			// {
			// 	if (ft_is_str_digit(split[i]) == 1)
			// 	{
			// 		error_msg(4);
			// 	}
			// 	i++;
			// }
		}
		tmp = tmp->next;
	}
//	tmp = *info;
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
	// printf("map_name : %s\n", map_name);
	//printf("cpy : %s\n", cpy);
	// printf("size : %d\n", size);
	if (ft_strncmp(cpy, ".cub", 4) != 0)
	 	error_msg(2);
}

int create_lst(t_parse **info, t_check *check)
{
	int fd;
	t_parse *new = NULL;

	fd = open(check->map, O_RDONLY);
	if(fd == -1)
		return (1);
	while(1)
	{
		new = lstnew(get_next_line(fd));
		add_back(info, new);
		if (new->content == NULL)
			break;
	}
	//display_lst(info, "map");
	return (0);
}

t_parse	*lstnew(char *str)
{
	t_parse	*new_element;

	new_element = ft_calloc(1, (sizeof(t_parse)));
	if (new_element == NULL)
		return (NULL);
	(*new_element).content = str;
	new_element->next = NULL;
	return (new_element);
}

void	add_back(t_parse **head, t_parse *node_to_add)
{
	t_parse	*current;

	current = *head;
	if (*head == NULL)
	{
		*head = node_to_add;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = node_to_add;
	node_to_add->next = NULL;
}

void read_lst(t_parse **lst, t_check *check_lst)
{
	t_parse *tmp;

	tmp = *lst;
	while (tmp->next != NULL)
	{
		if (ft_strncmp(tmp->content, "EA ", 3) == 0 || ft_strncmp(tmp->content, "EA", 2) == 0)
			check_lst->EA++;
		if (ft_strncmp(tmp->content, "NO ", 3) == 0|| ft_strncmp(tmp->content, "NO", 2) == 0)
			check_lst->NO++;
		if (ft_strncmp(tmp->content, "SO ", 3) == 0|| ft_strncmp(tmp->content, "SO", 2) == 0)
			check_lst->SO++;
		if (ft_strncmp(tmp->content, "WE ", 3) == 0|| ft_strncmp(tmp->content, "WE", 2) == 0)
			check_lst->WE++;
		if (ft_strncmp(tmp->content, "F ", 2) == 0|| ft_strncmp(tmp->content, "F", 1) == 0)
			check_lst->F++;
		if (ft_strncmp(tmp->content, "C ", 2) == 0|| ft_strncmp(tmp->content, "C", 1) == 0)
			check_lst->C++;
	//	display_node(tmp);
	//	printf("check1\n");
		tmp = tmp->next;
	}
}

void check_spelling(t_parse **lst, t_check *check_lst)
{
	(void)check_lst;
	t_parse *tmp;

	tmp = *lst;
	while (tmp->next != NULL)
	{
		if (ft_strncmp(tmp->content, "EA", 2) == 0 || ft_strncmp(tmp->content, "NO", 2) == 0 || ft_strncmp(tmp->content, "SO", 2) == 0 || ft_strncmp(tmp->content, "WE", 2) == 0)
		{
			if (tmp->content[2] != ' ')
			{
				check_lst->wrong_spell++;
			}
		}
		tmp = tmp->next;
	}
}

void is_valid(t_check *lst)
{
	if (lst->NO > 1|| lst->EA > 1 || lst->SO > 1|| lst->WE > 1 || lst->F > 1 || lst->C > 1)
	{
		error_msg(0);
	}
	if (lst->wrong_spell > 0)
	{
		error_msg(1);
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
		printf("Error: Wrong spell\n");
	if (option == 2)
		printf("Error: Invalid extension\n");
	if (option == 3)
		printf("Error: Invalid texture extension\n");
	if (option == 4)
		printf("Error: Bad coordinates\n");
	if (option == 5)
		printf("Error: Excessive information\n");
	exit(0) ;
}

void	display_lst(t_parse **ptr_to_head, char *name)
{
	t_parse	*current_node;
	int		count;

	current_node = *ptr_to_head;
	count = 0;
	printf("\n%s :\n", name);
	if (*ptr_to_head != NULL)
	{
		while (current_node->next != NULL)
		{
			printf("Index = %d : ", count);
			display_node(current_node);
			current_node = current_node->next;
			count++;
		}
		printf("Index = %d : ", count);
		display_node(current_node);
	}
	else
		printf("The stack is empty.\n");
	printf("\n");
}

void	display_node(t_parse *lst)
{
	if (lst != NULL)
	{
		printf("[%p] {content = %s | nx = %p}\n", lst,
			lst->content,
			lst->next);
	}
}
