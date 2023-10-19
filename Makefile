NAME		= cub3D
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
SRC_PATH	= ./src
PARSE_PATH	= ./src/parsing

SRC			=	main.c
PARSE		=	get_next_line.c get_next_line_utils.c parsing.c
SRCS		= $(addprefix $(SRC_PATH)/,$(SRC)) $(addprefix $(PARSE_PATH)/,$(PARSE)) $(addprefix $(CIRCLE_PATH)/,$(CIRCLE))
OBJ			= ${SRCS:.c=.o}
LIBFT		= libft/libft.a
MLX			= mlx_openGL/libmlx.a

SRCT 	= circle.c draw.c
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

$(NAME) : $(OBJ) $(LIBFT) $(MLX)
##	make -C mlx
##	cp mlx/libmlx.dylib .
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -framework OpenGL -framework AppKit -o $(NAME)

circle : $(OBJT) $(LIBFT) $(MLX)
##	make -C $(LIBFT)
##	cp libft/libft.a .
##	make -C mlx
##	cp mlx/libmlx.dylib .
	$(CC) $(CFLAGS) $(OBJT) $(LIBFT) $(MLX) -framework OpenGL -framework AppKit -o circle

clean :
	rm -f $(OBJ)
	make clean -C mlx
	make clean -C libft

fclean : clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY : all re clean fclean
