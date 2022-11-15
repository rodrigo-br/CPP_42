SRC		=	main.cpp

OBJS	=	$(SRC:.cpp=.o)

NAME	=	zombie

CC 		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98


all:		$(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

test:		all
			./$(NAME)