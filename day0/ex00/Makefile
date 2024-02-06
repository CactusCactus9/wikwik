# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 17:46:22 by abelkace          #+#    #+#              #
#    Updated: 2023/11/10 17:46:23 by abelkace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME     := megaphone

SRCS     := megaphone.cpp

OBJS     := $(SRCS:.cpp=.o)

CXX      := c++

CXXFLAGS := -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean  re