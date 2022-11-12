SRC		=	megaphone.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME	=	megaphone

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
		./$(NAME) "shhhhh... I think the students are asleep..."
		./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
		./$(NAME)