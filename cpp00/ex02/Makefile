# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 10:46:20 by asohrabi          #+#    #+#              #
#    Updated: 2024/09/03 14:13:02 by asohrabi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

FUNCS =  Account.cpp tests.cpp

OBJS = ${FUNCS:.cpp=.o}

CFLAGS = -Wall -Wextra -Werror -std=c++98

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