SRCS	=	$(MAIN) $(CLASSES)
MAIN	=	main.cpp
CLASSES	=	HumanA.cpp HumanB.cpp Weapon.cpp

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	weapon

CC 		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

HEADER	=	HumanA.hpp HumanB.cpp Weapon.cpp

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