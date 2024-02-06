# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 11:27:36 by abelkace          #+#    #+#              #
#    Updated: 2023/11/24 13:03:33 by abelkace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= sed

SRCS	= main.cpp files.cpp

OBJS	= $(SRCS:.cpp=.o)

CXX	 = c++ 

CXXFLAGS = -Wall -Werror -Wextra  -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(OBJS) -o $@

%.o: %.cpp files.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re