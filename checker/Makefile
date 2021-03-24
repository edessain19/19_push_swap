SRCS = main.c \
		ft_cmd.c \
		

OBJS	=	$(SRCS:%.c=%.o)

LIBFT	=	utils/libft/libft.a

NAME	=	checker

CFLAGS	=	-Wall -Wextra -Werror -g

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
			gcc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

clean:		
			rm -rf $(OBJS)
			cd utils/libft/ && make $@

fclean:		clean
			rm -rf $(NAME)
			rm -rf $(LIBFT)

re:			fclean all

$(LIBFT):
			make bonus -C ./utils/libft