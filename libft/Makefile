# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edessain <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 15:24:23 by edessain          #+#    #+#              #
#    Updated: 2019/11/27 15:24:25 by edessain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSC		= ft_bzero.c \
				ft_strlen.c \
				ft_isdigit.c \
				ft_strncmp.c \
				ft_atoi.c \
				ft_strdup.c \
				ft_strjoin.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_split.c \
				get_next_line.c \
				get_next_line_annex.c \
				ft_strjoin_free.c

SRCSH		= include/libft.h

OBJS		= $(SRCSC:%.c=%.o)

NAME		= libft.a

CC			= gcc

AR			= ar -rc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
