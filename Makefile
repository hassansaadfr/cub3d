# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/17 14:58:24 by hsaadaou          #+#    #+#              #
#    Updated: 2021/01/21 15:53:58 by hsaadaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	clang

FLAGS	=	-Wall -Wextra -Werror -g

NAME	=	cub3d.a

HEADERS	=	-I./includes

SRCS	=	main.c \
			srcs/processing/ft_process_game.c \
			srcs/utils/errors.c \
			srcs/utils/print_colors.c \
			srcs/utils/free_utils.c \
			srcs/parser/map_check.c \
			srcs/parser/ft_map_parser.c \
			srcs/struct_utils/struct_config.c \

OBJECTS	=	${SRCS:.c=.o}

.PHONY	:	all clean fclean re

all		:	$(NAME)

.c.o	:
			${CC} ${FLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}

$(NAME)	:	${OBJECTS}
			@make -C libft
			@cp libft/libft.a $(NAME)
			@ar -rcs ${NAME} ${OBJECTS}
			@${CC} ${FLAGS} ${OBJECTS} ${HEADERS} ${NAME} -o Cub3d

clean	:
			@make clean -C libft
			@rm -rf ${OBJECTS}

fclean	:	clean
			@make fclean -C libft
			@rm -rf $(NAME)
			@rm Cub3d

re		:	fclean all

