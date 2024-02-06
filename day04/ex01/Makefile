# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 12:16:40 by abelkace          #+#    #+#              #
#    Updated: 2023/11/30 10:54:31 by abelkace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= DogCat

SRCS	= main.cpp Cat.cpp Dog.cpp Animal.cpp Brain.cpp WrongCat.cpp WrongAnimal.cpp

OBJS	= $(SRCS:.cpp=.o)

CXX	 = c++

CXXFLAGS = -Wall -Werror -Wextra  -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(OBJS) -o $@

%.o: %.cpp Cat.hpp Dog.hpp Animal.hpp Brain.hpp WrongCat.hpp WrongAnimal.hpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re