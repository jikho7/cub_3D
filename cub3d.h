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

typedef struct s_matrice
{
	int		height;
	int		width;
}t_matrice;

typedef struct  s_f_fill
{
    int           x;
    int           y;
}t_f_fill;

typedef struct s_parse
{
	char			*content;
	struct s_parse	*next;
}t_parse;

typedef struct s_complex {
	float	x;
	float	y;
}	t_complex;

typedef struct s_player
{
	t_complex	pos;
	t_complex	dir;
	t_complex	plane;
	int			speed;
}		t_player;

typedef struct s_data {
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			size;
	int			square;
}		t_data;

typedef struct s_vars {
	void		*mlx;
	void		*mlx_win;
	t_data		*win;
	t_player	*you;
}		t_vars;

typedef struct s_map
{
	int mapX;
	int mapY;
	int mapS;
}		t_map;

int		init_mlx(t_data *data);

char	*get_next_line(int fd);
char	*gnl_strchr(char *s);
size_t	gnl_strlen(char *s);
char	*gnl_strjoin(char *s1, char *s2);

/*----------------DRAWING-----------------*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		trgb(int t, int red, int green, int blue);
int		grad(int i);
int		min(int a, int b);
int		max(int a, int b);
void	character(t_data *win, t_player *you);
int cancle(float posX, float posY, t_data *win);

/*----------------PARSING-----------------*/
int		parsing(char *map);
void	read_lst(t_parse **lst, t_check *check_lst);
void	init_struct_check(t_check *check, char *map);
void	check_spelling(t_parse **lst, t_check *check_lst);
void	init_matrice(t_matrice *matrice);
void	check_map_extension(char *name);
void	check_tex_extension(t_parse **info, t_check *check);
void	check_spelling(t_parse **lst, t_check *check_lst);
void	check_F_C(t_parse **info);
int		ft_is_str_digit(char *str);
void	check_if_info_after_map(t_parse **info, t_check *check);
//void	strtrim_F_C(t_parse info, int i);
void	check_excess_info(t_parse **info);
void	strtrim_lst(t_parse **info);
char** create_matrice(t_parse **info, t_matrice *matrice);
void	matrice_size(t_parse **map, t_matrice *matrice);
void reduce_spaces_to_one(t_parse ** lst);
void reduce_spaces_F_C(char *str);
/*----------------LISTS-----------------*/
void	add_back(t_parse **head, t_parse *node_to_add);

/*----------------ERRORS-----------------*/
void	error_msg(int option);
int		create_lst(t_parse **info, t_check *check);
t_parse	*lstnew(char *str);
void	display_node(t_parse *lst);
void	display_lst(t_parse **ptr_to_head, char *name);
#endif
