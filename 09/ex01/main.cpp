#include "RPN.hpp"

int	main(int ac, char **av){
	try{
		if (ac < 2)
			throw ("Not enough arguments!");
		std::string	str = av[1];
		ft_parsing(av[1]);
		}
	catch(const char *e){
		std::cout << e << std::endl;
	}
		
}