# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 18:32:57 by abelkace          #+#    #+#              #
#    Updated: 2023/11/10 17:51:41 by abelkace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME     := phonebook

SRCS     := main.cpp  PhoneBook.cpp Contact.cpp

OBJS     := $(SRCS:.cpp=.o)

CXX      := c++

CXXFLAGS := -Wall -Werror -Wextra  -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(OBJS) -o $@

%.o: %.cpp Contact.hpp PhoneBook.hpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re