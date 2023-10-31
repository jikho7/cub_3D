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
	//	printf("new->content[0]: %c\n", new->content[0]);
		add_back(info, new);
		if (new->content == NULL)
			break;
	}
	//display_lst(info, "map");
	return (0);
}

void cpy_lst(t_parse **dest_lst, t_parse **src_lst)
{
	t_parse *s_tmp;
	t_parse *tmp = NULL;

	s_tmp = *src_lst;
	if (s_tmp)
	{
		while (s_tmp->next != NULL)
		{
			tmp = lstnew(s_tmp->content);
			add_back(dest_lst, tmp);
			s_tmp = s_tmp->next;
		}
	}
	else
	{
		*src_lst = NULL;
		error_msg(10);
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