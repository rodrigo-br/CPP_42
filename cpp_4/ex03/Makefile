SRCS	=	$(shell ls ./ | grep .cpp$)

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	interface

CC 		=	c++
CFLAGS	=	-Wall -Wextra -Werror -Wshadow -std=c++98

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			rm -rf $(OBJS)
			rm -rf leaks.txt

fclean:		clean
			rm -f $(NAME)

re:			fclean all

test:	re
		valgrind --leak-check=full --log-file="leaks.txt" ./$(NAME)