SRC		=	main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME	=	zombieland

CC 		=	c++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $@ $^

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

test:		all
			./$(NAME)