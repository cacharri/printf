# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/06 18:00:35 by ialvarez          #+#    #+#              #
#    Updated: 2021/06/24 20:46:47 by ialvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_DIR = libft/
LIBFT_NAME = ${LIBFT_DIR}libft.a

GCC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS	= ft_printf.c ft_return.c ft_char2str.c ft_vsprintf.c ft_simple.c

OBJS	= ${SRCS:.c=.o}

${NAME}:	${OBJS} ${LIBFT_NAME}
			${GCC} -o printf ${CFLAGS} ${SRCS} ${LIBFT_NAME} #-fsanitize=address
		##	ar -rcs ${NAME} ${OBJS}

all:		${NAME}

${LIBFT_NAME}:
			${MAKE} -C ${LIBFT_DIR}

clean:
			${MAKE} -C ${LIBFT_DIR} clean
			${RM} ${OBJS}

fclean:		clean
			${MAKE} -C ${LIBFT_DIR} fclean
			${RM} ${NAME}

re:			fclean all

bonus:		${NAME}
			${GCC} -c ${CFLAGS} ${SRCSBN}
			ar -rcs ${NAME} ${OBJSBN}

tag:
	ctags ${SRCS} ${LIBFT_DIR}*

.PHONY:
			clean
			fclean
			all
			re
			bonus
