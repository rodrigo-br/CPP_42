SRC		=	main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME	=	violence

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

test:	all
		./$(NAME)