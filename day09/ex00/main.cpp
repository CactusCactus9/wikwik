#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

int	main(int ac,char **av){
	std::string	line;
	std::string	header;

	if (ac != 2){
		std::cout << "Error! Check the arguments!" << std::endl;
		return (1);
	}
	//Here's how std::ios::trunc works:
//If the file specified for output operations already exists, opening it with the std::ios::trunc flag will truncate the file, meaning that it will delete all existing content within the file.
//If the file does not exist, a new file with the specified name is created.
//If the file is successfully opened or created, output operations (such as writing data to the file) can be performed
	split_data();
	read_file(av);
}