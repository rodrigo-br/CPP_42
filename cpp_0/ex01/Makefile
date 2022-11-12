SRC		=	PhoneBook.cpp Contact.cpp main.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME	=	phonebook

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