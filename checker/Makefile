NAME = checker
SRCS = main.c \
		./srcs/ft_itoa.c \
		./srcs/ft_libft.c \
		

OBJS = $(SRCS:.c=.o)

INCLUDE = ../include/checker.h
CC = gcc -g -Wall -Werror -Wextra -pthread 
RM = rm -f

all:		${NAME}

$(NAME):	$(OBJS)
			$(CC) -I./ $(OBJS) -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all