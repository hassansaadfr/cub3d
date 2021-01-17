# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 18:31:54 by hsaadaou          #+#    #+#              #
#    Updated: 2021/01/17 16:06:30 by hsaadaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	clang

FLAGS		=	-Wall -Wextra -Werror

NAME		=	libftprintf.a

SRCS		=	ft_printf.c srcs/parse_args.c srcs/ft_lst_init.c \
				srcs/converter/utils.c srcs/converter/ft_convert_base.c \
				srcs/converter/ft_convert_base2.c srcs/ft_treat_precision.c \
				srcs/converter/ft_utoa.c \
				srcs/ft_arg_c.c srcs/ft_arg_d.c srcs/ft_arg_p.c \
				srcs/ft_arg_s.c srcs/ft_arg_x.c

LIBFT		=	libft

HEADERS		=	-I./includes

OBJECTS		=	${SRCS:.c=.o}

all:			$(NAME)

.c.o:
				${CC} ${FLAGS} ${HEADERS} -c $< -o ${<:.c=.o}

$(NAME) :		${OBJECTS}
				make bonus -C $(LIBFT)
				@cp libft/libft.a ./$(NAME)
				@ar -rcs ${NAME} ${OBJECTS}

clean:
				rm -rf ${OBJECTS}
				make clean -C libft

fclean:			clean
				rm -rf $(NAME) ${OBJECTS}
				make fclean -C libft

re:				fclean all

.PHONY:			all clean fclean re
