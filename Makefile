# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/17 14:58:24 by hsaadaou          #+#    #+#              #
#    Updated: 2021/01/17 20:52:01 by hsaadaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	clang

FLAGS	=	-Wall -Wextra -Werror -fsanitize=address -g

NAME	=	cub3d.a

HEADERS	=	-I./includes

SRCS	=	main.c \
			srcs/errors.c \
			srcs/map_check.c \

OBJECTS	=	${SRCS:.c=.o}

all		:	$(NAME)

.c.o	:
			${CC} ${FLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}

$(NAME)	:	${OBJECTS}
			@make -C libft
			@cp libft/libft.a $(NAME)
			@ar -rcs ${NAME} ${OBJECTS}
			@${CC} ${FLAGS} ${OBJECTS} ${HEADERS} ${NAME} -o Cube3d

clean	:
			make clean -C libft
			@rm -rf ${OBJECTS}

fclean	:	clean
			@make fclean -C libft
			@rm -rf $(NAME)
			@rm Cube3d

re		:	fclean all

.PHONY	:	all clean fclean re
