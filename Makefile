NAME		= cub3D
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g3 -fsanitize=address
SRC_PATH	= ./src
PARSE_PATH	= ./src/parsing
DRAW_PATH	= ./src/drawing

SRC			=	main.c
DRAW		=	minimap.c draw.c hooks.c raycasting.c math.c handling_texture.c hook_actions.c raycasting_utils.c
PARSE		=	get_next_line.c get_next_line_utils.c parsing.c parsing_utils.c init_parsing.c check_parsing1.c check_parsing2.c check_parsing3.c check_parsing4.c lst_utils.c lst_utils2.c matrice.c matrice2.c matrice_utils.c flood_fill.c flood_fill2.c check_map.c errors_parsing.c
SRCS		= $(addprefix $(SRC_PATH)/,$(SRC)) $(addprefix $(PARSE_PATH)/,$(PARSE)) $(addprefix $(DRAW_PATH)/,$(DRAW))
OBJ			= ${SRCS:.c=.o}
LIBFT		= libft/libft.a
MLX			= mlx_openGL/libmlx.a
MLX_L		= mlx_linux/libmlx.a

SRCT 	= test.c
SRCTS 	= $(addprefix $(SRC_PATH)/,$(SRCT))
OBJT	= ${SRCTS:.c=.o}

all: $(NAME)

.c.o: cub3d.h
	${CC} ${CFLAGS} -I. -c $< -o ${<:.c=.o}

$(LIBFT) :
	@$(MAKE) -C libft

$(MLX) :
	@$(MAKE) -C mlx_openGL

$(NAME) : $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -framework OpenGL -framework AppKit -o $(NAME)

circle : $(OBJT) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJT) $(LIBFT) $(MLX) -framework OpenGL -framework AppKit -o test

clean :
	rm -f $(OBJ) $(OBJT) $(OBJR)
	make clean -C mlx
	make clean -C libft

fclean : clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY : all re clean fclean
