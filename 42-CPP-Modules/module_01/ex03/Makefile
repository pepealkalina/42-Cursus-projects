# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 12:02:54 by pepealkalin       #+#    #+#              #
#    Updated: 2023/12/04 13:07:57 by pepealkalin      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = weapon

SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

OBJECTS = $(SRC:.cpp=.o)

CC = g++

CCFLAGS = -Wall -Wextra -Werror -std=c++98 -o

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CCFLAGS) $(NAME) $(OBJECTS)

clean:
	rm -f *.o

fclean:
	rm -f *.o $(NAME)

re:	fclean all