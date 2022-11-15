SRC		=	main.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME	=	noob_sed

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
	./$(NAME) main.cpp std cavalinho
#	./$(NAME) main.cp string cavalinho
#	./$(NAME) main.cp 1 string cavalinho