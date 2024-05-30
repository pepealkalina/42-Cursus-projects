# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 10:57:24 by pepealkalin       #+#    #+#              #
#    Updated: 2023/11/30 13:28:22 by pepealkalin      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Zombie

SRC = Zombie.cpp main.cpp zombieHorde.cpp

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