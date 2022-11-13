SRC		=	Account.cpp tests.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME	=	account

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