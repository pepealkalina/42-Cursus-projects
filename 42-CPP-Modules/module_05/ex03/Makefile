# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/25 08:59:17 by pepealkalin       #+#    #+#              #
#    Updated: 2024/03/27 13:19:34 by pepealkalin      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat

SRC = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp  Intern.cpp

OBJECTS = $(SRC:.cpp=.o)

CC = c++

CCFLAGS = -Wall -Wextra -Werror -std=c++98 -o

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CCFLAGS) $(NAME) $(OBJECTS) -g

clean:
	rm -f *.o *_shrubbery

fclean:
	rm -f *.o $(NAME) *_shrubbery

re:	fclean all

.PHONY: all clean fclean re