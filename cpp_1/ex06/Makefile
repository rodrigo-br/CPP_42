SRCS	=	$(MAIN) $(CLASSES)
MAIN	=	main.cpp
CLASSES	=	Harl.cpp

OBJ_DIR	=	obj
OBJS	=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

NAME	=	harl

CC 		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

VPATH	=	./
HEADER	=	Harl.hpp
INCLUDE	=	-I ./ -I ./includes

all:		$(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(OBJ_DIR):
	mkdir -p $@

clean:
			rm -rf obj

fclean:		clean
			rm -f $(NAME)

re:			fclean all

test:	all
		./$(NAME) DEBUG
		./$(NAME) INFO
		./$(NAME) WARNING
		./$(NAME) ERROR
		./$(NAME) RANDOM
		./$(NAME)