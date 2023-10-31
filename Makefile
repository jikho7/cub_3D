NAME		= cub3D
CC			= gcc #-g3 -fsanitize=address
CFLAGS		= -Wall -Werror -Wextra -g
SRC_PATH	= ./src
PARSE_PATH	= ./src/parsing

SRC			=	main.c circle.c draw.c hooks.c
PARSE		=	get_next_line.c get_next_line_utils.c parsing.c check_parsing.c lst_utils.c matrice.c flood_fill.c check_map.c save.c
SRCS		= $(addprefix $(SRC_PATH)/,$(SRC)) $(addprefix $(PARSE_PATH)/,$(PARSE)) $(addprefix $(CIRCLE_PATH)/,$(CIRCLE))
OBJ			= ${SRCS:.c=.o}
LIBFT		= libft/libft.a
MLX			= mlx_openGL/libmlx.a
MLX_L		= mlx_linux/libmlx.a

SRCT 	= circle.c draw.c hooks.c
SRCTS 	= $(addprefix $(SRC_PATH)/,$(SRCT))
OBJT	= ${SRCTS:.c=.o}

all: $(NAME)

.c.o:
	${CC} ${CFLAGS} -I. -c $< -o ${<:.c=.o}
## -I. include les dossier .h du dossier courant (racine)
## <> possible si inculs a la compilation (-I) (a la place de "").
## mettre $(MAKE) a la place de make ecrit en dur, bonne pratique.
$(LIBFT) :
	@$(MAKE) -C libft

$(MLX) :
	@$(MAKE) -C mlx_openGL

##$(NAME) : $(OBJ) $(LIBFT) $(MLX_L)
##	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_L) -o $(NAME)
$(NAME) : $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -framework OpenGL -framework AppKit -o $(NAME)

circle : $(OBJT) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJT) $(LIBFT) $(MLX) -framework OpenGL -framework AppKit -o circle

clean :
	rm -f $(OBJ) $(OBJT) $(OBJR)
	make clean -C mlx
	make clean -C libft

fclean : clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY : all re clean fclean
