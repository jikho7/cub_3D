# include <cub3d.h>

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
	if (check_lst->NO == 0 || check_lst->EA == 0 || check_lst->SO == 0 || check_lst->WE == 0 || check_lst->F == 0 || check_lst->C == 0)
	{
		error_msg(12);
	}
}

void check_F_C(t_parse **info)
{
	t_parse *tmp;
	int size;
	char *cpy;

	tmp = *info;
	size = 0;
	while(tmp->next != NULL)
	{
		if (strncmp(tmp->content, "F", 1) == 0 || strncmp(tmp->content, "C", 1) == 0)
		{
			cpy = ft_strdup(tmp->content);
			strtrim_F_C(cpy);
			free(cpy);
		}
		tmp = tmp->next;
	}
}

void strtrim_F_C(char *str)
{
	int i = 0;
	char sign[] = {'F', 'C', ' ', '\n'};
	char **split;
	int nb;

	i = 0;
	split = ft_split(str, ',');

	i = 0;
	if (split[1] == 0)
	{
		error_msg(4);
	}
	while (split[i])
	{
		split[i] = ft_strtrim(split[i], sign);
		nb = ft_atoi(split[i]);
		if (nb < 0 || nb > 255)
		{
			error_msg(4);
		}
		i++;
	}
	if (i != 3)
	{
		error_msg(4);
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
