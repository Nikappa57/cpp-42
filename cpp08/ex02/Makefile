NAME 				=	mutantstack

CC					=	c++
CFLAGS				=	-Wall -Wextra -Werror -std=c++98 -g
RM					=	/bin/rm -f

HEADER				=	MutantStack.hpp
SRCS				=	main.cpp

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
