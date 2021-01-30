# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/17 14:58:24 by hsaadaou          #+#    #+#              #
#    Updated: 2021/01/30 20:50:07 by hsaadaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	clang

FLAGS	=	-Wall -Wextra -Werror -g

MLX_F	=	-L./libft -lft -I/usr/local/include -L/usr/local/lib -lmlx -L/usr/include -lm -lbsd -lX11 -lXext

NAME	=	cub3D

HEADERS	=	-I./includes

SRCS	=	main.c \
			srcs/processing/ft_process_game.c \
			srcs/processing/ft_flood_fill.c \
			srcs/utils/errors.c \
			srcs/utils/print_colors.c \
			srcs/utils/colors.c \
			srcs/utils/array_utils.c \
			srcs/parser/map_check.c \
			srcs/parser/color_parser.c \
			srcs/parser/ft_map_parser.c \
			srcs/struct_utils/struct_config_alloc.c \
			srcs/struct_utils/struct_config_free.c \
			srcs/struct_utils/struct_config_utils.c \
			srcs/screen/common.c \
			srcs/screen/hooks.c \
			srcs/screen/draw_utils.c \

OBJECTS	=	${SRCS:.c=.o}

.PHONY	:	all clean fclean re

all		:	$(NAME)

.c.o	:
			@${CC} ${FLAGS} ${HEADERS} -o $@ -c $<

$(NAME)	:	${OBJECTS}
			@make -C libft
			@cp libft/libft.a $(NAME)
			@ar -rcs ${NAME} ${OBJECTS}
			@${CC} ${FLAGS} ${MLX_F} ${OBJECTS} ${HEADERS} -o $(NAME)
			@printf "\033[92mcub3d compiled\n\033[0m"

clean	:
			@make clean -C libft
			@rm -rf ${OBJECTS}

fclean	:	clean
			@make fclean -C libft
			@rm cub3D cub3d.a

re		:	fclean all

