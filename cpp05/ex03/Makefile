NAME 				=	bureaucrat

CC					=	c++
CFLAGS				=	-Wall -Wextra -Werror -std=c++98
RM					=	/bin/rm -f

HEADER				=	Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp \
						RobotomyRequestForm.hpp PresidentialPardonForm.hpp \
						Intern.hpp
SRCS				=	Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
						RobotomyRequestForm.cpp PresidentialPardonForm.cpp \
						Intern.cpp main.cpp

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
