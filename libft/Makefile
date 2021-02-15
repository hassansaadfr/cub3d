# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 22:04:03 by hsaadaou          #+#    #+#              #
#    Updated: 2021/02/14 17:24:24 by hsaadaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES		=	ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c ft_memccpy.c \
					ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlen.c ft_strrchr.c \
					ft_toupper.c ft_calloc.c ft_isdigit.c ft_memchr.c ft_memset.c  \
					ft_putstr_fd.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_putchar.c \
					ft_putstr.c get_next_line.c ft_lstadd_back.c ft_lstadd_front.c \
					ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c \
					ft_lstnew.c ft_lstsize.c \
					ft_printf/ft_printf.c ft_printf/srcs/parse_args.c \
					ft_printf/srcs/ft_lst_init.c ft_printf/srcs/converter/utils.c \
					ft_printf/srcs/converter/ft_convert_base.c \
					ft_printf/srcs/converter/ft_convert_base2.c \
					ft_printf/srcs/ft_treat_precision.c \
					ft_printf/srcs/converter/ft_utoa.c \
					ft_printf/srcs/ft_arg_c.c ft_printf/srcs/ft_arg_d.c \
					ft_printf/srcs/ft_arg_p.c \
					ft_printf/srcs/ft_arg_s.c ft_printf/srcs/ft_arg_x.c

OBJS			=	${SRC_FILES:.c=.o}

HEAD			=	includes

CC				=	clang

CFLAGS			=	-Wall -Werror -Wextra

NAME			=	libft.a

.c.o			:
					${CC} ${CFLAGS} -I ${HEAD} -c $< -o ${<:.c=.o}

${NAME}			:	${OBJS}
					ar -rcs ${NAME} ${OBJS}

all				:	${NAME}

clean			:
					rm -rf ${OBJS}

fclean			:	clean
					rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re
