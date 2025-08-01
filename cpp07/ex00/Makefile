# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 21:07:14 by asohrabi          #+#    #+#              #
#    Updated: 2025/08/01 12:43:47 by asohrabi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = templates

SRCS = main.cpp

OBJS = ${SRCS:.cpp=.o}

CFLAGS = -Wall -Wextra -Werror -std=c++17

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
