SRC		=	main.cpp Harl.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME	=	harlFilter

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
			./$(NAME) 1
			./$(NAME) DEBUG
			./$(NAME) INFO
			./$(NAME) WARNING
			./$(NAME) ERROR