SRCS	=	$(MAIN) $(CLASSES)
MAIN	=	main.cpp newZombie.cpp randomChump.cpp
CLASSES	=	Zombie.cpp

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	zombie

CC 		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

VPATH	=	./
HEADER	=	newZombie.hpp randomChump.hpp
INCLUDE	=	-I ./ -I ./includes

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