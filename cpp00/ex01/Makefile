# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 10:46:20 by asohrabi          #+#    #+#              #
#    Updated: 2024/09/11 17:18:39 by asohrabi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

FUNCS = Contact.cpp PhoneBook.cpp main.cpp

OBJS = ${FUNCS:.cpp=.o}

CFLAGS = -Wall -Wextra -Werror -std=c++11

%.o: %.cpp
	@c++ ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	@c++ ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all, clean, fclean, re