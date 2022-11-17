SRCS	=	$(MAIN) $(CLASSES)
MAIN	=	main.cpp
CLASSES	=	Fixed.cpp Point.cpp bsp.cpp

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	fixed

CC 		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

VPATH	=	./
HEADER	=	Fixed.hpp Point.hpp
INCLUDE	=	-I ./ -I ./includes

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

test:	all
		wget https://github.com/rodrigo-br/CPP_42/raw/main/cpp_2/ex03/tri%C3%A2ngulo.png
		./$(NAME)