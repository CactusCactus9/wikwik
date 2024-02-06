# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 19:09:16 by abelkace          #+#    #+#              #
#    Updated: 2023/11/24 13:05:21 by abelkace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= harl

SRCS	= main.cpp Harl.cpp

OBJS	= $(SRCS:.cpp=.o)

CXX	 = c++

CXXFLAGS = -Wall -Werror -Wextra  -std=c++98

%.o: %.cpp Harl.hpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<
	
all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@


clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re