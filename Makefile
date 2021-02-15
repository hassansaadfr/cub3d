# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/17 14:58:24 by hsaadaou          #+#    #+#              #
#    Updated: 2021/02/14 16:26:12 by hsaadaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D

CC				=	clang

SRCS			=	main.c \
					processing/ft_process_game.c \
					processing/ft_flood_fill.c \
					utils/errors.c \
					utils/print_colors.c \
					utils/colors.c \
					utils/array_utils.c \
					parser/map_check.c \
					parser/color_parser.c \
					parser/ft_map_parser.c \
					struct_utils/struct_config_alloc.c \
					struct_utils/struct_config_free.c \
					struct_utils/struct_config_utils.c \
					screen/common.c \
					screen/hooks.c \
					screen/draw_utils.c \
					screen/draw_map_2d.c \
					engine/move_player.c \
					engine/ray.c \
					debug_tools/debug_window.c \

OBJS			=	${addprefix srcs/,${SRCS:.c=.o}}

HEAD			=	-I includes -I libft/includes -I ${MLX_DIR}

CC				=	clang

CFLAGS			=	-Wall -Werror -Wextra -g

LIBFT_DIR		=	libft

MLX_DIR			=	mlx/mlx_linux

LDFLAGS			=	-L ${LIBFT_DIR} -L ${MLX_DIR}

MLX_LINUX		=	-lm -lft -lmlx -lXext -lX11

MLX_MAC			=	-Lmlx  -lft -lmlx -framework OpenGL -framework AppKit

LIBS			=	${MLX_LINUX}

.c.o			:
					${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

$(NAME)			:	${OBJS}
					make -C ${LIBFT_DIR}
					make -C ${MLX_DIR}
					${CC} ${CFLAGS} ${LDFLAGS} ${OBJS} -o ${NAME} ${LIBS}

all				:	${NAME}

clean			:
					rm -rf ${OBJS}

fclean			:	clean
					rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re
