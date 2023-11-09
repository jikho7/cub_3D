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
	char			*map;
	int				EA;
	int				NO;
	int				SO;
	int				WE;
	int				C;
	int				F;
	int				wrong_spell;
	int				is_map;
	t_list			*gc;
	struct	s_mat	*mat;
}t_check;

typedef struct s_mat
{
	struct s_check	*check;
	char			**map_space;
	char			**map;
	int				hei;
	int				wid;
	int				N;
	int				S;
	int				E;
	int				W;
	char			*NO_path;
	char			*SO_path;
	char			*EA_path;
	char			*WE_path;
	int				*F;
	int				*C;
	int				wrong_symbol;
	int				player_sympbol;
	int				pos_x_player;
	int				pos_y_player;
	char			orientation;
}t_mat;

typedef struct s_f_fill
typedef struct s_f_fill
{
	int	x;
	int	y;
	int	x;
	int	y;
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

typedef struct s_ray
{
	t_complex	rDir;
	t_complex	sideDist;
	t_complex	sqDel;
	float		line_loc;
	int			udorlr;
	float		distance;
	int			NWSE;
}t_ray;

typedef struct s_player
{
	t_complex	pos;
	t_complex	dir;
	t_complex	plane;
	int			speed;
}t_player;

typedef struct s_texture
{
	void		*mlx;
	char		*path;
	void		*img_ptr;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			height;
	int			width;

}t_texture;

typedef struct s_data {
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			height;
	int			width;
	t_mat		*map;
	t_mat		*map;
	int			minimap;
	int			sqr;
	t_texture	*tex;
	int			forward;
	int			c;
	t_ray		*ray;
}t_data;

typedef struct s_vars {
	void		*mlx;
	void		*mlx_win;
	t_data		*win;
	t_player	*you;
	t_mat		*map;
}t_vars;

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
int		cancle(float posX, float posY, t_data *win);
int		mouse_hook(int mousecode, int i, int j, t_data *win);
int		key_hook(int keycode, t_vars *vars);
int		render_new_frame(t_vars *vars);
int		destroy(t_vars *vars);
void	raycasting(t_player *you, t_data *win);
int		wall(int i, int j, t_data *win);
void	draw_line(t_data *win, t_complex start, t_complex end);
void	draw_wall(t_ray *ray, int i, int udorlr, t_data *win);
void	create_struct_sprites(t_data *win, t_vars *vars);
void	turn(t_data *win, t_player *you, int clockwise);
int		move(t_data *win, t_player *you, float addX, float addY);
void	pretty_or_legal(t_data *win, int i, int j);
void	init_ray(t_ray *ray, int step, t_player *you, t_data *win);
int		dda_start(t_complex *adelta, t_ray *ray, t_complex *map);
int		x_or_y(t_ray *ray, t_complex *adelta, t_complex *map);

/*----------------MATH-----------------*/
int		sgn(float n);
int		min(int a, int b);
int		max(int a, int b);
int		sgn(float n);
int		min(int a, int b);
int		max(int a, int b);
float	sq(float a);
void	set_comp(t_complex *c, float x, float y);

/*----------------PARSING-----------------*/
t_mat	*parsing(char *map);
void	read_lst(t_parse **lst, t_check *check_lst);
void	init_struct_check(t_check *check, char *map, t_mat *mat);
void	init_mat(t_mat *mat, t_check *check);
void	check_map_extension(char *name);
void	check_tex_extension(t_parse **info, t_check *check);
void	check_spelling(t_parse **lst, t_check *check_lst);
void	check_f_c(t_parse **info, t_mat *mat);
int		ft_is_str_digit(char *str);
void	check_if_info_after_map(t_parse **info, t_check *check);
void	check_excess_info(t_parse **info);
void	strtrim_lst(t_parse **info, t_check *check);
void	create_mat(t_parse **origin, t_mat *mat);
void	get_height(t_parse **map, t_mat *mat);
void	flood_fill(t_mat *mat);
void	strtrim_mat(t_parse info, t_check *check);
void	reduce_spaces_to_one(t_parse **lst, t_check *check);
int		size_len(char *str);
void	check_map(t_mat *mat);
void	strtrim_f_c(char *str, t_mat *mat);
void	get_width(t_parse **map, t_mat *mat);
void	check_spaces_nsew(t_parse **info);
void	remove_empty_block(t_parse **info);
void	get_width2(t_mat *mat);
char	*ft_strcpy(char *s1, char *s2);
void	save_textures(char *str, t_check *check);
void	check_read_lst(t_check *check_lst);
t_parse	*go_through_no_map_char(t_parse *tmp, int i);
void	save_f_c_info(int option, t_mat *matrice, int j, char *split);
void	check_if_space_in_map(t_parse *lst, t_mat *mat);
int		check_up(t_mat *mat, int pos_y, int pos_x);
int		check_directions(t_mat *mat, int pos_y, int pos_x);
int		check_left(t_mat *mat, int pos_y, int pos_x);
int		check_right(t_mat *mat, int pos_y, int pos_x);
int		check_down(t_mat *mat, int pos_y, int pos_x);
int		verif_malloc(void *malloc);
/*----------------LISTS-----------------*/
void	add_back(t_parse **head, t_parse *node_to_add);
int		lstsize(t_parse *lst);
int		create_lst(t_parse **info, t_check *check);
t_parse	*lstnew(char *data, t_list **gc_lst);
void	display_node(t_parse *lst);
void	display_lst(t_parse **ptr_to_head, char *name);
void	cpy_lst(t_parse **dest_lst, t_parse **src_lst, t_check *check);

/*----------------ERRORS-----------------*/
void	error_msg(int option);

#endif
