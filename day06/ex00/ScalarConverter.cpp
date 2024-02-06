#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>

ScalarConverter::ScalarConverter(){};
ScalarConverter::~ScalarConverter(){};
ScalarConverter::ScalarConverter(const ScalarConverter &obj){
	(void)obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other){
	(void)other;
	return (*this);
}

void	to_int(std::string str){
	int		integer;
	char	*endptr;

	std::cout << "int: ";
	integer = strtod(str.c_str(), &endptr);
	if (pseudo_literal(str))
		std::cout << "impossible" << std::endl;
	else
		std::cout << (static_cast<int>(integer)) << std::endl;
}

void	to_double(std::string &str){
	double	integer;
	char	*endptr;
	int		i;

	std::cout << "double: " ;
	if (pseudo_literal(str)){
		if (str == "+inff" || str == "+inf")
			std::cout << "+inf" << std::endl;
		else if (str == "-inff" || str == "-inf")
			std::cout << "-inf" <<std::endl;
		else if (str == "nan" || str == "+nan" || str == "-nan")
			std::cout << "nan"<< std::endl;
		return ;
	}
	integer = strtod(str.c_str(), &endptr);
	if (integer == 0)
		std::cout << "0.0" << std::endl;
	else{
		i = str.find('.');
		if (i == -1){
			std::cout  << static_cast<double>(integer) << ".0" <<std::endl;
		}
		else if (i != -1 && (str[i + 1] == '0' || str[i + 1] == '\0' || str[i + 1] == 'f'))
			std::cout  << static_cast<double>(integer) << ".0" <<std::endl;
		else
			std::cout  << static_cast<double>(integer) <<std::endl;//COMPILE TIME

	}
}
//The static_cast operator is the most commonly used casting operator in C++. 
//It performs compile-time type conversion and is mainly used for explicit conversions that are considered safe by the compiler. 
//The static_cast can be used to convert between related types, such as numeric types or pointers in the same inheritance hierarchy.


void	to_float(std::string &str){
	double	integer;
	char	*endptr;
	int		i;

	std::cout << "float: " ;
	if (pseudo_literal(str)){
		if (str == "+inff" || str == "+inf")
			std::cout << "+inff" << std::endl;
		else if (str == "-inff" || str == "-inf")
			std::cout << "-inff" <<std::endl;
		else if (str == "nan" || str == "+nan" || str == "-nan")
			std::cout << "nanf"<< std::endl;
		return ;
	}
	integer = strtod(str.c_str(), &endptr);
	if (integer == 0)
		std::cout << "0.0f" << std::endl;
	else{
		i = str.find('.');
		if (i == -1)
			std::cout  << static_cast<float>(integer) << ".0f" <<std::endl;
		else if (i != -1 && (str[i + 1] == '0' || str[i + 1] == '\0' || str[i + 1] == 'f'))
			std::cout  << static_cast<float>(integer) << ".0f" <<std::endl;
		else
			std::cout  << static_cast<float>(integer) << "f" <<std::endl;

	}
}

void	to_char(std::string &str){
	int		integer;
	char	*endptr;

	integer = strtod(str.c_str(), &endptr);
	std::cout << "char: " ;
	if (pseudo_literal(str))
			std::cout << "impossible"<< std::endl;

	else if (integer >= 32 && integer <= 126){

		std::cout << "'" << static_cast<char>(integer) << "'" << std::endl;
	}
	else if (endptr[0] != '\0'){
		std::cout <<  endptr  <<  std::endl;
	}
	else{
		std::cout << "Non displayable" << std::endl;}
}

void	ScalarConverter::convert(std::string &str){
	to_char(str);
	to_int(str);
	to_float(str);
	to_double(str);
}
