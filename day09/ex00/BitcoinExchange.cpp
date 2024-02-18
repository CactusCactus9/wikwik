#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

void	split_data(){
	std::string	line;
	std::string	date;
	std::string	value;
	std::string	header;
	std::map<std::string, std::string> map;

	std::ifstream   myFile("data.csv");
	if (!myFile.is_open()){
		std::cerr << "Failed to open the file!" << std::endl;
		return ;
	}
	if (!getline(myFile, header))
		return ;
	while (getline(myFile, line)){
		std::istringstream iss(line);//like cin except it reads from string
		if(!getline(iss, date, ','))
			return ;
		if(!getline(iss, value))
			return ;
		map[date] =value;
	}
	myFile.close();
	// std::map<std::string, std::string>::iterator	it = map.begin();
	// while (it != map.end()){
	// 	std::cout << it->first << " ******* " << it->second << std::endl;
	// 	++it;
	// }
}


int	ft_leap(int	year){
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return (0);
	return (1);
}


void	ft_parsing(std::string line){
	//----allowed charachters----//
	for (size_t i = 0; i < line.length(); i++){
		if (line[i] != ' ' && line[i] != '-' && line[i] != '|' && line[i] != '.' && !isdigit(line[i])){
			std::cerr << "Invalid input1!" << std::endl;
		}
	}
	//----valid year----//
	for (size_t i = 0; i < 4; i++){
		if (!isdigit(line[i])){
			std::cerr << "Invalid input2!" << std::endl;
		}
	}
	//----valid format----//
	if (line.length() >= 4 && line[4] != '-'){
		std::cerr << "Invalid input!3" << std::endl;
	}
	//----valid month----//
	for (size_t i = 5; i < 7; i++){
		if (!isdigit(line[i])){
			std::cerr << "Invalid input4!" << std::endl;
		}
	}
	//----valid format----//
	if (line.length() >= 7 && line[7] != '-'){
		std::cerr << "Invalid input5!" << std::endl;
	}
	//----valid day----//
	for (size_t i = 8; i < 10; i++){
		if (!isdigit(line[i])){
			std::cerr << "Invalid input6!" << std::endl;
		}
	}
	//----valid format----//
	if (line.length() >= 10 && (line[10] != ' ' && line[10] != '\0')){
		std::cerr << "Invalid input7!" << std::endl;
	}
	if (line.length() >= 11 && (line[11] != '|' || line[12] != ' ' || 
	!isdigit(line[13]) || (line[13] < 0 || atoi(&line[13]) > 1000))){
		std::cerr << "Invalid input8!" << std::endl;
	}
	std::cout <<  "line " <<line << std::endl;
}

void	read_file(char **av){
std::string	header;
std::string	line;
std::string	year;
std::string	month;
std::string	day;
std::string	val;
int			leap;

leap = 3;
std::ifstream   myFile(av[1]);
if (!(myFile.is_open())){
		std::cout << "Failed to open the file!" <<std::endl;
		return ;
	}
	if (!getline(myFile, header)){
		std::cerr << "Failed to read!" << std::endl;
		return ;
	}
	if (header != "date | value"){
		std::cout << "Invalid input!" << std::endl;
		return ;
	}
	while (getline(myFile, line)){
		ft_parsing(line);
		std::istringstream	strm(line);
		if (!getline(strm, year, '-'))
			return ;
		leap = ft_leap(atoi(year.c_str()));
		if (!getline(strm, month, '-'))
			return ;
		if (!getline(strm, day, ' '))
			return ;
		if (leap == 0 && atoi(day.c_str()) != 29)
			return ;
			std::cout << "leap" << leap << std::endl;
	}
	myFile.close();
}
