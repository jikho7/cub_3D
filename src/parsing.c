# include <cub3d.h>

// check extension .cub
// check extension .png
int create_lst(t_parse **info);
t_parse	*lstnew(char *str);
void	add_back(t_parse **head, t_parse *node_to_add);
void is_valid(t_check *lst);
void read_lst(t_parse **lst, t_check *check_lst);
void init_struct_parse(t_check *check);
void check_spelling(t_parse **lst, t_check *check_lst);
void error_msg(int option);
void check_map_extension(char *name);

int parsing()
{
	//(void)map;
	t_parse *info = NULL;
	t_check check;

	//check_map_extension(map);
	init_struct_parse(&check);
	create_lst(&info);
	read_lst(&info, &check);
	check_spelling(&info, &check);
	is_valid(&check);
	return (0);
}

void check_map_extension(char *map)
{
	//int i;
	(void)map;
	char *name = "map0.csub";
	int size;
	const char *cpy;

	size = ft_strlen(name);
//	i = size - 4;
	cpy = (name + (size - 4));
	printf("cpy : %s\n", cpy);
	printf("size : %d\n", size);
	// if (ft_strncmp(cpy, ".cub", 4) == 1)
	//  	printf("invalid extension\n");
	// while (name[size - i])
	// {

	// }
}

int create_lst(t_parse **info)
{
	int fd;
	t_parse *new = NULL;

	fd = open("map0.cub", O_RDONLY);
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
	printf("check0\n");
	while (tmp->next != NULL)
	{
		printf("check1\n");
		if (ft_strncmp(tmp->content, "EA ", 3) == 0)
			check_lst->EA++;
		if (ft_strncmp(tmp->content, "NO ", 3) == 0)
			check_lst->NO++;
		if (ft_strncmp(tmp->content, "SO ", 3) == 0)
			check_lst->SO++;
		if (ft_strncmp(tmp->content, "WE ", 3) == 0)
			check_lst->WE++;
		if (ft_strncmp(tmp->content, "F ", 2) == 0)
			check_lst->F++;
		if (ft_strncmp(tmp->content, "C ", 2) == 0)
			check_lst->C++;
	//	display_node(tmp);
		printf("check1\n");
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
		//printf("error msg doublon\n");
		error_msg(0);
	}
	if (lst->wrong_spell > 0)
	{
		//printf("error msg wrong spelling\n");
		error_msg(1);
	}
}

void init_struct_parse(t_check *check)
{
	check->EA = 0;
	check->NO = 0;
	check->SO = 0;
	check->WE = 0;
	check->C = 0;
	check->F = 0;
	check->wrong_spell = 0;
}

void error_msg(int option)
{
	if (option == 0)
		printf("Error: Doublon\n");
	if (option == 1)
		printf("Error: Wrong spell\n");
	return ;
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
