SRCS	=	$(MAIN) $(CLASSES)
MAIN	=	main.cpp
CLASSES	=	Harl.cpp

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	harl

CC 		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

HEADER	=	Harl.hpp

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