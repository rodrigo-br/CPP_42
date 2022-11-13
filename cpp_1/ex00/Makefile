SRCS	=	$(MAIN) $(CLASSES)
MAIN	=	main.cpp newZombie.cpp randomChump.cpp
CLASSES	=	Zombie.cpp

OBJ_DIR	=	obj
OBJS	=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

NAME	=	zombie

CC 		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

VPATH	=	./
HEADER	=	utils.hpp Zombie.hpp
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
		./$(NAME)