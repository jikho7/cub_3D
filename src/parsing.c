# include "../cub3d.h"
#include "mlx.h"

int parsing()
{
	int fd;
	t_list info;

	ft_lstnew(info);
	printf("check\n");
	create_lst(&info);
	fd = open("map0.cub", O_RDONLY);
	if(fd == -1)
		return (1);
	gnl_cub(fd);
	return (0);
}

// void create_lst(t_list *info)
// {
// 	ft_add_back
// }
