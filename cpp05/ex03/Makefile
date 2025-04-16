# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 21:07:14 by asohrabi          #+#    #+#              #
#    Updated: 2025/04/16 17:32:29 by asohrabi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat_forms

FUNCS = main.cpp Bureaucrat.cpp AForm.cpp Intern.cpp \
		ShrubberyCreationForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp

OBJS = ${FUNCS:.cpp=.o}

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
