SRCS	=	$(shell ls ./ | grep .cpp$)

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	claptrap

CC 		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

test:	all
		./$(NAME)