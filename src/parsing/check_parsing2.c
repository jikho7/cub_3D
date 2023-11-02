# include <cub3d.h>

void save_F_C_info(int option, t_matrice *matrice, int j, char *split);
void handle_C_norm(int *j, int *i, char **split, t_matrice *matrice);
void handle_F_norm(int *i, int *j, char **split, t_matrice *matrice);

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

void check_F_C(t_parse **info, t_matrice *matrice)
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
			strtrim_F_C(cpy, matrice);
			free(cpy);
		}
		tmp = tmp->next;
	}
}

void strtrim_F_C(char *str, t_matrice *matrice)
{
	int i;
	char **split;
	int j;

	split = ft_split_GC(str, ',', &matrice->check->trash);
	i = 0;
	j = 0;
	if (split[1] == 0)
		error_msg(4);
	while (split[i])
	{
		if (split[i][0] == 'F')
		{
			while (j <= 2)
				handle_F_norm(&j, &i, split, matrice);
		}
		else if (split[i][0] == 'C')
		{
			while (j <= 2)
				handle_C_norm(&j, &i, split, matrice);
		}
		j = 0;
	}
	if (i != 3)
		error_msg(4);
}

void handle_F_norm(int *i, int *j, char **split, t_matrice *matrice)
{
	char sign_F[] = {'F', ' ', '\n'};

	split[*i] = ft_strtrim_GC(split[*i], sign_F, &matrice->check->trash);
	save_F_C_info(0, matrice, *j, split[*i]);
	(*j)++;
	(*i)++;
}

void handle_C_norm(int *i, int *j, char **split, t_matrice *matrice)
{
	char sign_C[] = {'C', ' ', '\n'};

	split[*i] = ft_strtrim_GC(split[*i], sign_C, &matrice->check->trash);
	save_F_C_info(1, matrice, *j, split[*i]);
	(*j)++;
	(*i)++;
}

void save_F_C_info(int option, t_matrice *matrice, int j, char *split)
{
	int nb;
	//char sign_C[] = {' ', '\n'};
	nb = 0;
	nb = ft_atoi(split);
	//printf("i: %d, split: %s\n", j, split);

	if (nb < 0 || nb > 255)
	{
		error_msg(4);
	}
	if (option == 0)
		matrice->F[j] = nb;
	if (option == 1)
		matrice->C[j] = nb;
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
