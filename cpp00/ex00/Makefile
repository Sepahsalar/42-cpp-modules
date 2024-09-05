# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 10:46:20 by asohrabi          #+#    #+#              #
#    Updated: 2024/09/05 17:11:32 by asohrabi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

FUNC =  megaphone.cpp

OBJ = ${FUNC:.cpp=.o}

CFLAGS = -Wall -Wextra -Werror -std=c++11

%.o: %.cpp
	@c++ ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJ}
	@c++ ${CFLAGS} ${OBJ} -o ${NAME}

clean:
	@rm -f ${OBJ}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all, clean, fclean, re