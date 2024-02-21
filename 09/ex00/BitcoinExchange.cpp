#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

std::map<std::string, std::string>	split_data(){
	std::string	line;
	std::string	date;
	std::string	value;
	std::string	header;
	// unsigned int	y;
	// unsigned int	m;
	// unsigned int	d;
	// float		v;
	// char 			dash;

	std::map<std::string, std::string> map;

	std::ifstream   myFile("data.csv");
	if (!myFile.is_open()){
		std::cerr << "Failed to open the file!" << std::endl;
		myFile.close();
	}
	if (!getline(myFile, header)){
		std::cout <<"header not deading" << std::endl;
		myFile.close();
	}
	while (getline(myFile, line)){
		std::istringstream iss(line);//like cin except it reads from string
		if(!getline(iss, date, ',')){
			std::cout << "Failed to get the date from data base!" << std::endl;
			myFile.close();
		}
		if(!getline(iss, value)){
			std::cout << "Failed to get the value from data base!" << std::endl;
			myFile.close();
		}
		// std::istringstream	newstrm(date);
		// newstrm >> y >> dash >> m >> dash >> d;
		// // std::cout << "y" << y << dash << "m" << m << dash << "d" << d << std::endl;
		// std::stringstream	nstrm(value);
		// nstrm >> v;
		// // std::cout << "v" << v << std::endl;
		map.insert(std::make_pair(date, value));
	}
	myFile.close();
	// std::map<std::string, std::string>::iterator	it = map.begin();
	// while (it != map.end()){
	// 	std::cout << it->first << " ******* " << it->second << std::endl;
	// 	++it;
	// }
	return (map);
}
//duplicate dates override

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
	if (occurence == std::string::npos){//static member constant of the std::string class, represents the maximum possible value for the size of a string
		std::cout << "Invalid Format" << std::endl;
		return ;
	}

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
}

void	read_file(char **av){
	std::string		header;
	std::string		line;
	std::string		date;
	std::string		val;
	// unsigned int	y;
	// unsigned int	m;
	// unsigned int	d;
	float	v;
	// char			dash;
	// int				leap;
	size_t	m_y;
	size_t	m_m;
	size_t	m_d;
	float			m_v;
	char 			m_dash;

	// leap = 3;
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
		
		if (!getline(strm, date, '|')){
			std::cout << "Failed to get the date!" << std::endl;
			return ;
		}
		if (!getline(strm, val, '|')){
			std::cout << "Failed to get the value!" << std::endl;
			std::cout << date << std::endl;
			
			return ;
		}
		//--get int values----//
		// std::istringstream	newstrm(date);
		// newstrm >> y >> dash >> m >> dash >> d;
		std::stringstream	nstrm(val);
		nstrm >> v;
		// leap = ft_leap(y);
		// if (leap == 0 && m == 02 && d > 29)
		// 	std::cout << "Error!" << std::endl;
		std::map<std::string, std::string>	map;
		map = split_data();
		std::string	tmp = date.substr(0, date.size() - 1);
		std::map<std::string, std::string>::iterator	it = map.lower_bound(tmp);
		if (it != map.end()){
			//--map elements to int----//
			std::istringstream	newstrm(it->first);
			newstrm >> m_y >> m_dash >> m_m >> m_dash >> m_d;
			std::stringstream	nstrm(it->second);
			nstrm >> m_v;
			if (date == it->first){
				std::cout << "right output: " << date << " => " << val << " = " << (m_v * v) << std::endl;
				std::cout << " output: " << it->first << " => " << it->second << std::endl;
			}
			else{
				--it;
				if (it != map.end()){
				std::cout << "right output: " << date << " => " << val << " = " << (m_v * v) << std::endl;
				std::cout << " outpu t: " << it->first << " => " << it->second << std::endl;
				}
			}
		}
			else
				std::cout << "date not found" << std::endl;
	}
	myFile.close();
}
