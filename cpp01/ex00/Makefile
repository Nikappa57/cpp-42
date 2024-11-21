NAME 				=	zombie

CC					=	c++
CFLAGS				=	-Wall -Wextra -Werror -std=c++98
RM					=	/bin/rm -f

HEADER				=	Zombie.hpp
SRCS				=	main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

OBJS				=	$(SRCS:.cpp=.o)

%.o: %.cpp
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$(OBJS) $(HEADER)
					$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
					$(RM) $(OBJS)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re norm
