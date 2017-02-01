# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+       #
#    By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+             #
#    Created: 2013/11/29 09:40:24 by dlancar           #+#    #+#              #
#    Updated: 2016/11/30 18:44:11 by dlancar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= abstractVM
SRC		= main.cpp OperandFactory.cpp Operator.cpp VM.cpp Expression.cpp Lexer.cpp Exceptions.cpp Parser.cpp\
		  Push.cpp Add.cpp NoOp.cpp
OBJ		= $(SRC:.cpp=.o)
CFLAGS  = -std=c++1z -Wall -Wextra

debug: CFLAGS += -O0 -g3 -fsanitize=address
release: CFLAGS += -O3 -march=native

all: debug

debug: $(NAME)
release: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) -o $(NAME) $(CFLAGS) $(LBFLAG) $(OBJ)

%.o: %.cpp
	@$(CXX) -I. -I./boost -o $@ -c $? $(CFLAGS)

.PHONY: clean fclean re

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

suicide: fclean
	@rm -f $(SRC)
