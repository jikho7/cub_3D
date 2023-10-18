# include <cub3d.h>

int create_lst(t_list *info);
t_list	*ft_lstnew(char *str);
void	add_back(t_list **head, t_list *node_to_add);

int parsing()
{
	t_list *info = NULL;

	create_lst(info);
	return (0);
}

int create_lst(t_list *info)
{
	int fd;
	t_list *new = NULL;

	fd = open("map0.cub", O_RDONLY);
	if(fd == -1)
		return (1);
	info = ft_lstnew(get_next_line(fd));
	while(get_next_line(fd) != NULL)
	{
		new = ft_lstnew(get_next_line(fd));
//		display_node(new);
		add_back(&info, new);
	}
	display_lst(&info, "map");
	return (0);

}

void	display_lst(t_list **ptr_to_head, char *name)
{
	t_list	*current_node;
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

void	display_node(t_list *lst)
{
	if (lst != NULL)
	{
		printf("[%p] {content = %s | nx = %p}\n", lst,
			lst->content,
			lst->next);
	}
}

t_list	*ft_lstnew(char *str)
{
	t_list	*new_element;

	new_element = ft_calloc(1, (sizeof(t_list)));
	if (new_element == NULL)
		return (NULL);
	(*new_element).content = str;
	new_element->next = NULL;
	return (new_element);
}

void	add_back(t_list **head, t_list *node_to_add)
{
	t_list	*current;

	current = *head;
	while (current->next)
		current = current->next;
	current->next = node_to_add;
	node_to_add->next = NULL;
}
