# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 13:07:59 by preina-g          #+#    #+#              #
#    Updated: 2024/01/09 17:53:30 by preina-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Animal

SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp

OBJECTS = $(SRC:.cpp=.o)

CC = c++

CCFLAGS = -Wall -Wextra -Werror -std=c++98 -o

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CCFLAGS) $(NAME) $(SRC) -g

clean:
	rm -f *.o

fclean:
	rm -f *.o $(NAME)

re:	fclean all