# include <cub3d.h>

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
