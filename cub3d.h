#ifndef CUB3D_H
# define CUB3D_H

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "mlx/mlx.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <string.h>


# define BUFFER_SIZE 11
# define WIN_WIDTH 1440
# define WIN_HEIGHT 960
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define FOV 60

typedef struct s_check
{
	char	*map;
	int		EA;
	int		NO;
	int		SO;
	int		WE;
	int		C;
	int		F;
	int		wrong_spell;
	int		is_map;
}t_check;

typedef struct s_parse
{
	char			*content;
	struct s_parse	*next;
}t_parse;

typedef struct s_complex {
	double	x;
	double	y;
}	t_complex;

typedef struct s_player
{
	float posX;
	float posY;
	float dirX;
	float dirY;
	float planeX;
	float planeY;

}		t_player;

typedef struct s_data {
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			size;
	double		zoom;
	t_complex	t;
	int			itter;
}	t_data;

typedef struct s_vars {
	void		*mlx;
	void		*mlx_win;
	t_data		*win;
	t_complex	c;
	char		*frac;
	t_player	*you;
}		t_vars;

typedef struct s_map
{
	int mapX;
	int mapY;
	int mapS;
}		t_map;

int		init_mlx(t_data *data);
int		parsing(char *map);
int		gnl_cub(int fd);
char	*get_next_line(int fd);
char	*gnl_strchr(char *s);
size_t	gnl_strlen(char *s);
char	*gnl_strjoin(char *s1, char *s2);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	trgb(int t, int red, int green, int blue);
int	grad(int i);

//void	init(t_list *info);
void	display_node(t_parse *lst);
void	display_lst(t_parse **ptr_to_head, char *name);
#endif
