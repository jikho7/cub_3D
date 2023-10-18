#ifndef CUB3D_H
# define CUB3D_H

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "mlx/mlx.h"
# include <fcntl.h>


# define BUFFER_SIZE 11
# define WIN_WIDTH 1440
# define WIN_HEIGHT 960
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define FOV 60

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_player
{
	float posX;
	float posY;
	float dir;
}t_player;

typedef struct s_map
{
	int mapX;
	int mapY;
	int mapS;
}t_map;

// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }t_list;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	t_img		img;
	t_player	player;
	t_map		map;
	int			len;
//	t_list		list;
}t_data;

int		init_mlx(t_data *data);
int		parsing();
int		gnl_cub(int fd);
char	*get_next_line(int fd);
char	*gnl_strchr(char *s);
size_t	gnl_strlen(char *s);
char	*gnl_strjoin(char *s1, char *s2);
//void	init(t_list *info);
#endif
