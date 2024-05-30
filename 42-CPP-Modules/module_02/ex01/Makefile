# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 11:26:50 by preina-g          #+#    #+#              #
#    Updated: 2023/12/13 16:45:56 by preina-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fixed

SRC = main.cpp Fixed.cpp

OBJECTS = $(SRC:.cpp=.o)

CC = c++

CCFLAGS = -Wall -Wextra -Werror -std=c++98 -o

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CCFLAGS) $(NAME) $(OBJECTS)

clean:
	rm -f *.o

fclean:
	rm -f *.o $(NAME)

re:	fclean all