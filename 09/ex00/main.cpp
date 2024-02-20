#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

int	main(int ac,char **av){
	std::string	line;
	std::string	header;
	std::map<std::string, std::string>	map;
	(void)av;
	if (ac != 2){
		std::cout << "Error! Check the arguments!" << std::endl;
		return (1);
	}
	map = split_data();
	read_file(av);
}