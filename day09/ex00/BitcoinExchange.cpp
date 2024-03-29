#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

int	split_data(){
	std::string	line;
	std::string	date;
	std::string	value;
	std::string	header;
	std::map<std::string, std::string> map;

	std::ifstream   myFile("data.csv");
	if (!myFile.is_open()){
		std::cerr << "Failed to open the file!" << std::endl;
		return (0);
	}
	if (!getline(myFile, header))
		return (0);
	while (getline(myFile, line)){
		std::istringstream iss(line);//like cin except it reads from string
		if(!getline(iss, date, ','))
			return (0);
		if(!getline(iss, value))
			return (0);
		map[date] =value;
	}
	myFile.close();
	return (1);
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

int	check_month(std::string line, size_t i){
	const char	*str;

	str = line.c_str();
	if ((str[i] == '0' && (str[i + 1] >= '1' && str[i + 1] <= '9')) || (str[i] == '1'  && (str[i + 1] >= '0' && str[i + 1] <= '2')))
		return (0);
	return (1);
}

int	check_day(std::string line, size_t i){
	const char	*str;

	str = line.c_str();
	if ((str[i] == '0' && (str[i + 1] >= '1' && str[i + 1] <= '9')) || ((str[i] == '1' || str[i] == '2')  && (str[i + 1] >= '0' && str[i + 1] <= '9')) || (str[i] == '3'  && (str[i + 1] >= '0' && str[i + 1] <= '1')))
		return (0);
	return (1);
}

void	ft_parsing(std::string line){
	size_t	occurence;

	occurence = line.find('-');
	//----allowed charachters----//
	for (size_t i = 0; i < line.length(); i++){
		if (line[i] != ' ' && line[i] != '-' && line[i] != '|' && line[i] != '.' && !isdigit(line[i])){
			std::cerr << "Invalid input1!" << std::endl;
		}
	}
	//----valid year----//
	for (size_t i = 0; i < occurence; i++){
		if (!isdigit(line[i])){
			std::cerr << "Enter a valid year!" << std::endl;
		}
	}
	if (line[0] == '-')
		std::cout << "Wrong format!" << std::endl;
	//----valid month----//
	for (size_t i = occurence + 1; i < occurence + 3; i++){
		if (!isdigit(line[i]))
			std::cerr << "Enter a valid month!" << std::endl;
	}
	if (check_month(line, occurence + 1) == 1)
		std::cout << "Enter a valid month!" << std::endl;
	
	if (line[occurence + 3] != '-')
		std::cout << "Wrong format!" << std::endl;
	//----valid day----//
	for (size_t i = occurence + 4; i < occurence + 6; i++){
		if (!isdigit(line[i]))
			std::cerr << "Invalid input6!" << std::endl;
	}
	if (check_day(line, occurence + 4)){
		std::cout << "Enter a valid day!" << std::endl;
	}
	//----valid format----//
	if (line.length() >= occurence + 6 && (line[occurence + 6] != ' ' && line[occurence + 6] != '\0')){
		std::cerr << "Invalid input7!" << std::endl;
	}
	if (line.length() >= occurence + 6 && (line[occurence + 6] != ' ' || line[occurence + 7] != '|' || line[occurence + 8] != ' ' || 
	!isdigit(line[occurence + 9]) || !isdigit(line[line.length() - 1]) || (atof(&line[occurence + 9]) < 0 || atof(&line[occurence + 9]) > 1000))){
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
			std::cout << "month.c_str() " << month.c_str() << std::endl;
		if (leap == 0 && atoi(month.c_str()) == 02 && atoi(day.c_str()) > 29)
			return ;
			std::cout << "leap" << leap << std::endl;
	}
	myFile.close();
}
