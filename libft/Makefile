# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/17 17:19:55 by hsaadaou          #+#    #+#              #
#    Updated: 2021/01/17 17:28:58 by hsaadaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

all		:	$(NAME)

$(NAME)	:	${OBJECTS}
			make -C ft_printf
			cp ft_printf/libftprintf.a $(NAME)
			make -C get_next_line
			cp get_next_line/get_next_line.a get_next_line.a
			ar -rcs ${NAME} get_next_line.a
			rm get_next_line.a

clean	:
			make clean -C ft_printf
			make clean -C get_next_line

fclean	:	clean
			make fclean -C ft_printf
			make fclean -C get_next_line
			rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
