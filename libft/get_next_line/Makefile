# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/17 17:20:09 by hsaadaou          #+#    #+#              #
#    Updated: 2021/01/24 16:28:49 by hsaadaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	clang
FLAGS	=	-Wall -Wextra -Werror
NAME	=	get_next_line.a
HEADERS	=	-I.
SRCS	=	get_next_line.c get_next_line_utils.c
OBJECTS	=	${SRCS:.c=.o}

all		:	$(NAME)

.c.o	:
			@${CC} ${FLAGS} ${HEADERS} -c $< -o ${<:.c=.o}

$(NAME)	:	${OBJECTS}
			@printf "\033[92mGNL Compiled\n\033[0m"
clean	:
			@rm -rf ${OBJECTS}

fclean	:	clean
			@rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
