#include "RPN.hpp"
#include <sstream>
#include <stack>
#include <deque>
#include <cfloat>

void	ft_parsing(std::string str){
	std::stack<double>	s;
	std::string		n_str;
	size_t 			i;
	size_t index = str.find_first_not_of("0123456789/*-+ ");
	if (index != std::string::npos)
		throw ("Error!");
	std::cout << std::fixed;
	if (str.size() < 4)
		throw ("Wrong format!");
	for (i = 0; i < str.size(); i++){
		if (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/')
			throw ("Not valid number !");
		if (str[i] != ' ' && str[i] != '/' && str[i] != '*' && str[i] != '+' && str[i] != '-'){
			if (atoi(&str[i]) >= 10)
				throw ("not less than 10!");
				s.push(atoi(&str[i]));
		}
		else if (str[i] != ' '){
			if (s.size() >= 2){
				double a = s.top();
				s.pop();
				double b = s.top();
				s.pop();
				if (str[i] == '+' )
					s.push(a + b);
				else if (str[i] == '-' )
					s.push(b - a);
				else if (str[i] == '*'){
					s.push(a * b);
				}
				else if (str[i] == '/'){
					if (a == 0)
						throw ("Error: cant devide by 0");
					s.push(b / a);
				}
				else
					throw ("Error");
			}
			else
				throw ("you need two digits!");
		}
	}
	if (s.size() != 1)
		throw ("Error! No operation to do!");
	std::cout << "Result : " << s.top()<< std::endl;
}