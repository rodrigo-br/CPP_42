SRCS	=	$(shell ls ./ | grep .cpp$)

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	convert

CC 		=	c++
CFLAGS	=	-g3 -Wall -Wextra -Werror -Wshadow -std=c++98

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			rm -rf $(OBJS)
			rm -rf leaks*

fclean:		clean
			rm -f $(NAME)

re:			fclean all

test:	re
		valgrind --leak-check=full --show-leak-kinds=all --log-file="leaks.txt" ./$(NAME) 10.123456
		./$(NAME) 42.654321f
		./$(NAME) 10
		./$(NAME) a
		./$(NAME) 10.0.0
		./$(NAME) cavalinho
		./$(NAME) nan
		valgrind --leak-check=full --show-leak-kinds=all --log-file="leaks1.txt" ./$(NAME) 23156165165165
		valgrind --leak-check=full --show-leak-kinds=all --log-file="leaks2.txt" ./$(NAME) +inff