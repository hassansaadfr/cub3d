# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/17 14:58:24 by hsaadaou          #+#    #+#              #
#    Updated: 2021/01/17 17:47:34 by hsaadaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	clang
FLAGS	=	-Wall -Wextra -Werror
NAME	=	cub3d.a
HEADERS	=	-I./includes
SRCS	=	main.c
OBJECTS	=	${SRCS:.c=.o}

all		:	$(NAME)

.c.o	:
			${CC} ${FLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}

$(NAME)	:	${OBJECTS}
			make -C libft
			cp libft/libft.a $(NAME)
			ar -rcs ${NAME} ${OBJECTS}
			${CC} ${FLAGS} ${OBJECTS} ${HEADERS} ${NAME}

clean	:
			make clean -C libft
			rm -rf ${OBJECTS}

fclean	:	clean
			make fclean -C libft
			rm -rf $(NAME)
			rm a.out

re		:	fclean all

.PHONY	:	all clean fclean re
