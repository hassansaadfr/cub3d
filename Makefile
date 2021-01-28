# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/17 14:58:24 by hsaadaou          #+#    #+#              #
#    Updated: 2021/01/28 23:52:28 by hsaadaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	clang

FLAGS	=	-Wall -Wextra -Werror -g -o cub3D

MLX_F	=	-Lmlx -lmlx -framework OpenGL -framework AppKit

NAME	=	cub3d.a

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

OBJECTS	=	${SRCS:.c=.o}

.PHONY	:	all clean fclean re

all		:	$(NAME)

.c.o	:
			@${CC} ${FLAGS} -I ${HEADERS} -Imlx -c $< -o ${<:.c=.o}

$(NAME)	:	${OBJECTS}
			@make -C libft
			@cp libft/libft.a $(NAME)
			@ar -rcs ${NAME} ${OBJECTS}
			@${CC} ${FLAGS} ${MLX_F} ${OBJECTS} ${HEADERS} ${NAME}
			@printf "\033[92mcub3d compiled\n\033[0m"

clean	:
			@make clean -C libft
			@rm -rf ${OBJECTS}

fclean	:	clean
			@make fclean -C libft
			@rm -rf $(NAME)
			@rm cub3d

re		:	fclean all

