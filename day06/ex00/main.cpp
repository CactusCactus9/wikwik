#include "ScalarConverter.hpp"

int	pseudo_literal(std::string str){
	if (str == "+inff" ||  str == "-inff" || str == "+inf" ||  str == "-inf" || str == "nan" || str == "nanf")
		return (1);
	return (0);
}

int	ft_validate(std::string &str){
	if (str.length() == 1 && isprint(str[0])){
		return (1);
	}
	// else if (str.length() == 1 && !isprint(str[0]))
	// 	return (0);
	if (pseudo_literal(str))
		return (1);
	size_t i = 0;
	if (str[0] == '+' || str[0] == '-'){
		i++;
	}
	for(; i < str.length(); i++){
		if (!isdigit(str[i]) && str[i] != '.' && str[i] != 'f')
			return (0);
		if (str[i] == 'f' && i != (str.length() - 1))
			return (0);
	}
	return (1);
}
int	main(int ac, char **av)
{
	
		if (ac == 2)
		{
			std::string	str = av[1];
			if (ft_validate(str))
				ScalarConverter::convert(str);
		}
		else 
			return (0);
		
}
//Cast is essentially conversion, which allows us to transform the bits of one type to another type. For instance,
//int and double are saved differently in bits. To go from one type to the other, the bits need to be converted.