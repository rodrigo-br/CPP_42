SRCS	=	$(MAIN) $(CLASSES)
MAIN	=	main.cpp
CLASSES	=	Fixed.cpp

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	fixed

CC 		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

VPATH	=	./
HEADER	=	Fixed.hpp
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