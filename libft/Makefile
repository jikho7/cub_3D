# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 15:50:27 by jdefayes          #+#    #+#              #
#    Updated: 2023/10/18 14:28:11 by jdefayes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########ARGUMENTS########
##
NAME	= libft.a

########SOURCES########
##
SRC 	= 	ft_putnbr_fd.c\
			ft_putendl_fd.c\
			ft_putstr_fd.c\
			ft_putchar_fd.c\
			ft_striteri.c\
			ft_strmapi.c\
			ft_isascii.c\
			ft_itoa.c\
			ft_strtrim.c\
			ft_strjoin.c\
			ft_substr.c\
			ft_strdup.c\
			ft_calloc.c\
			ft_strlcpy.c\
			ft_split.c\
			ft_strlcat.c\
			ft_tolower.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strchr.c\
			ft_toupper.c\
			ft_isprint.c\
			ft_isalnum.c\
			ft_isdigit.c\
			ft_isalpha.c\
			ft_memcmp.c\
			ft_memchr.c\
			ft_memmove.c\
			ft_bzero.c\
			ft_memcpy.c\
			ft_strlen.c\
			ft_strncmp.c\
			ft_atoi.c\
			ft_memset.c\
			ft_split.c\
			ft_strdup.c\
			ft_strjoin.c\
			ft_lstadd_back.c\
			ft_lstadd_front.c\
			ft_lstclear.c\
			ft_lstdelone.c\
			ft_lstiter.c\
			ft_lstlast.c\
			ft_lstmap.c\
			ft_lstnew.c\
			ft_lstsize.c\

OBJ		= ${SRC:.c=.o}
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f

########RULES########
##
all: $(NAME)

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

bonus: $(OBJ)
	ar rcs $(NAME) $(OBJ)

.PHONY: all clean fclean re .c.o
