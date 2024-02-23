#include "RPN.hpp"
#include <sstream>
#include <stack>
#include <deque>


void	ft_parsing(std::string str){
	std::stack<int>		s;
	std::string				n_str;
	size_t i;
	size_t index = str.find_first_not_of("0123456789/*-+ ");
	if (index != std::string::npos)
		throw ("Error!");

	//TODO "1 9+" valid or not?
	//TODO return decimal
	//TODO 
	if (str.size() < 4)
		throw ("Wrong format!");
	for (i = 0; i < str.size(); i+=2){
		if (str[0] == ' ' || str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/')
			throw ("Not valid number !");
			if (str[i] != '/' && str[i] != '*' && str[i] != '+' && str[i] != '-'){
				if (atoi(&str[i]) > 10)
					throw ("not less than 10!");
				s.push(atoi(&str[i]));
				std::cout << "top : " << s.top()<< std::endl;
				continue ;
			}
			else{
				if (s.size() == 2){
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
					else if (str[i] == '/' && a != 0)
						s.push(b / a);
					else
						throw ("Errir");
					std::cout << "iwa top : " << s.top()<< std::endl;
				}
				else
					throw ("you need two digits!");
			}
	}
		
		
}
