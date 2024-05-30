# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 11:23:19 by pepealkalin       #+#    #+#              #
#    Updated: 2023/12/04 11:46:57 by pepealkalin      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

 NAME = string

SRC = main.cpp

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