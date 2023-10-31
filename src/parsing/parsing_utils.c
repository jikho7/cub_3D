# include <cub3d.h>

void reduce_spaces_to_one(t_parse ** lst)
{
	t_parse *tmp;
	int i;
	int j;
	char *res;
	int size;

	j = 0;
	tmp = *lst;
	while (tmp->next != NULL)
	{
		size = size_len(tmp->content);
		res = ft_calloc(size, sizeof(char));
		i = 0;
		j = 0;
		while (tmp->content[i])
		{
			if (tmp->content[i] == ' ')
				i++;
			else if (tmp->content[i])
			{
				res[j] = tmp->content[i];
				j++;
				i++;
			}
		}
		free(tmp->content);
		tmp->content = NULL;
		tmp->content = res;
		tmp = tmp->next;
	}
}

void remove_empty_block(t_parse **info)
{
	t_parse *tmp;

	tmp = *info;
	if (tmp->next == NULL)
		error_msg(10);
	if (tmp)
	{
		while (tmp->content[0] == '\n')
		{
			tmp = tmp->next;
		}
	}
	*info = tmp;
}

void check_spaces_NSEW(t_parse **info)
{
	int i;
	t_parse *tmp;

	tmp = *info;
	while (tmp->next != NULL)
	{
		if (ft_strncmp(tmp->content, "EA", 2) == 0 || ft_strncmp(tmp->content, "NO", 2) == 0 ||ft_strncmp(tmp->content, "SO", 2) == 0 ||ft_strncmp(tmp->content, "WE", 2) == 0)
		{
			i = 0;
			while (tmp->content[i] != '.')
				i++;
			while (tmp->content[i])
			{
				if (tmp->content[i] == ' ')
				{
					//printf("spaces in NSEW\n");
					error_msg(1);
				}
				i++;
			}

		}
		tmp = tmp->next;
	}
}

int size_len(char *str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		while (str[i] && str[i] != ' ')
		{
			i++;
			j++;
		}
	}
	return (j);
}
