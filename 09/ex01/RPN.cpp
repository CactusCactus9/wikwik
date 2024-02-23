#include "RPN.hpp"
#include <sstream>
#include <stack>
#include <deque>

RPN::RPN(){}

RPN::~RPN(){}


void	ft_parsing(std::string str){
	std::stack<int>		s;
	std::string				n_str;
	size_t i;
	size_t index = str.find_first_not_of("0123456789/*-+ ");
	if (index != std::string::npos)
		throw ("Error!");

	//TODO no sign before number
	for (i = 0; i < str.size(); i+=2){
			if (str[i] != '/' && str[i] != '*' && str[i] != '+' && str[i] != '-'){
				if (atoi(&str[i]) > 10)
					throw ("not less than 10!");
				s.push(atoi(&str[i]));
				std::cout << "top : " << s.top()<< std::endl;
				continue ;
			}
			else{
				int a = s.top();
				s.pop();
				int b = s.top();
				s.pop();
				if (str[i] == '+')
					s.push(a + b);
				else if (str[i] == '-')
					s.push(b - a);
				else if (str[i] == '*')
					s.push(a * b);
				else if (str[i] == '/' && b != 0)
					s.push(b / a);
				std::cout << "iwa top : " << s.top()<< std::endl;
			}
	}
		
		
}
