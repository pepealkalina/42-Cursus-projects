# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 12:56:16 by pepealkalin       #+#    #+#              #
#    Updated: 2023/12/05 13:51:27 by pepealkalin      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harlFilter

SRC = main.cpp Harl.cpp

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