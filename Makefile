NAME		= cub3D
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
SRC_PATH	= ./src

SRC			=	main.c window.c draw.c get_next_line.c get_next_line_utils.c hooks.c init.c parsing.c
SRCS		= $(addprefix $(SRC_PATH)/,$(SRC))
OBJ			= ${SRCS:.c=.o}
LIBFT		= libft

all: $(NAME)

.c.o:
	${CC} ${CFLAGS} -Imlx -c $< -o ${<:.c=.o}
## %.o: %.c cub3d.h
##	$(CC) $(CFLAGS) -Imlx -o $@ -c $<

$(NAME) : $(OBJ)
	make -C $(LIBFT)
	cp libft/libft.a .
	make -C mlx
	cp mlx/libmlx.dylib .
	$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	rm -f $(OBJ)
	make clean -C mlx
	make clean -C $(LIBFT)
	rm -f libmlx.dylib
	rm -f libft.a

fclean : clean
	rm -f $(NAME)
	rm -f $(LIBFT)/libft.a

re: fclean all

.PHONY : all re clean fclean
