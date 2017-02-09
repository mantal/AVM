# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+       #
#    By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+             #
#    Created: 2013/11/29 09:40:24 by mde-jesu          #+#    #+#              #
#    Updated: 2017/02/09 17:55:24 by mde-jesu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= abstractVM
SRC		= main.cpp OperandFactory.cpp Operator.cpp VM.cpp Expression.cpp Lexer.cpp Exceptions.cpp Parser.cpp \
		  Push.cpp Pop.cpp Dump.cpp Assert.cpp Add.cpp Sub.cpp Mul.cpp Div.cpp Mod.cpp NoOp.cpp Print.cpp Exit.cpp
OBJ		= $(SRC:.cpp=.o)
CFLAGS  = -std=c++1z -Wall -Wextra

BOOSTDIR= boost

debug: CFLAGS += -O0 -g3 -fsanitize=address
release: CFLAGS += -O3 -march=native

all: debug

debug: $(NAME)
release: $(NAME)

$(BOOSTDIR):
	sh install.sh

$(NAME): $(BOOSTDIR) $(OBJ)
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
