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

	std::map<std::string, std::string> map;

	std::ifstream   myFile("data.csv");
	if (!myFile.is_open()){
		throw ("Failed to open the file!");
	}
	if (!getline(myFile, header)){
		throw ("Failed to read the line!");
	}
	while (getline(myFile, line)){
		std::istringstream iss(line);//like cin except it reads from string
		if(!getline(iss, date, ','))
			throw ("Failed to get the date from data base!");
		if(!getline(iss, value))
			throw ("Failed to get the value from data base!");
		map.insert(std::make_pair(date, value));//to avoid overriding same values
	}
	myFile.close();
	return (map);
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
	if (occurence == std::string::npos)//static member constant of the std::string class, represents the maximum possible value for the size of a string
		throw ("Invalid Format");
	//----allowed charachters----//
	for (size_t i = 0; i < line.length(); i++){
		if (line[i] != ' ' && line[i] != '-' && line[i] != '|' && line[i] != '.' && !isdigit(line[i]))
			throw ("Invalid input1!");
	}
	//----valid year----//is year 0 valid?
	for (size_t i = 0; i < occurence; i++){
		if (!isdigit(line[i]))
			throw ("Enter a valid year!");
	}
	if (line[0] == '-')
		throw("Wrong format!");
	//----valid month----//
	for (size_t i = occurence + 1; i < occurence + 3; i++){
		if (!isdigit(line[i]))
			throw ("Enter a valid month!");
	}
	if (check_month(line, occurence + 1) == 1)
		throw("Enter a valid month!");
	
	if (line[occurence + 3] != '-')
		throw ("Wrong format!");
	//----valid day----//
	for (size_t i = occurence + 4; i < occurence + 6; i++){
		if (!isdigit(line[i]))
			throw ("Invalid input6!");
	}
	if (check_day(line, occurence + 4)){
		throw ("Enter a valid day!");
	}
	//----valid format----//
	if (line.length() >= occurence + 6 && (line[occurence + 6] != ' ' && line[occurence + 6] != '\0')){
		throw ( "Invalid input7!");
	}
	if (line.length() >= occurence + 6 && (line[occurence + 6] != ' ' || line[occurence + 7] != '|' || line[occurence + 8] != ' '))
		throw ("Invalid input8!");
	//----valid value----//
	for (size_t i = line.length() - 1; i > occurence + 8; i--){
		if (line[i] == '.' && line[i - 1] == '.')
			throw ("Invalid Value!");
	}
	if (!isdigit(line[occurence + 9]) || !isdigit(line[line.length() - 1]) || (atoi(&line[occurence + 9]) < 0 || atoi(&line[occurence + 9]) > 1000) || (atof(&line[occurence + 9]) > 1000))
		throw ("Invalid Valueee!");
}

void	read_file(char **av){
	std::string		header;
	std::string		line;
	std::string		date;
	std::string		val;
	unsigned int	y;
	unsigned int	m;
	unsigned int	d;
	size_t			v;
	char			dash;
	int				leap;
	size_t			m_y;
	size_t			m_m;
	size_t			m_d;
	size_t			m_v;
	char 			m_dash;
	std::map<std::string, std::string>	map;

	// leap = 3;
	std::ifstream   myFile(av[1]);
	if (!(myFile.is_open())){
		std::cerr << "Failed to open the file!" <<std::endl;
		return ;
	}
	if (!getline(myFile, header)){
		myFile.close();
		std::cerr << ("Failed to read first line!") << std::endl;
		return ;
	}
	if (header != "date | value"){
		myFile.close();
		std::cerr << "Invalid input!" << std::endl;
		return ;
	}
	while (getline(myFile, line)){
		try{
			ft_parsing(line);
			std::istringstream	strm(line);
			
			if (!getline(strm, date, '|')){
				myFile.close();
				std::cerr <<("Failed to get the date!") << std::endl;
			}
			if (!getline(strm, val)){
				myFile.close();
				std::cerr<< ("Failed to get the value!") << std::endl;
			}
			//--get int values----//
			std::istringstream	newstrm(date);
			newstrm >> y >> dash >> m >> dash >> d;
			std::stringstream	nstrm(val);
			nstrm >> v;
			leap = ft_leap(y);
			if (leap == 0 && m == 02 && d > 29)
				throw ("leap year can't depass 29 days!");
			if (leap == 1 && m == 02 && d > 28)
				throw ("Non leap year can't depass 28 days!");
			if (leap == 1 && (m == 04 || m == 06 || m == 9 || m == 11) && d > 30)
				throw ("This month can't depass 30 days!");
			std::string	tmp = date.substr(0, date.size() - 1);
			//----map----//
			map = split_data();
			std::map<std::string, std::string>::iterator	it = map.lower_bound(tmp);
			if (it != map.end()){
				if (tmp != it->first)
					--it;
				//--map elements to int----//
				std::istringstream	newstrm(it->first);
				newstrm >> m_y >> m_dash >> m_m >> m_dash >> m_d;
				std::stringstream	nstrm(it->second);
				nstrm >> m_v;
				std::cout << date << " => " << val << " = " << (m_v * v) << std::endl;
			}
			else{
				--it;
				//--map elements to int----//
				std::istringstream	newstr(it->first);
				newstr >> m_y >> m_dash >> m_m >> m_dash >> m_d;
				std::stringstream	nstr(it->second);
				nstr >> m_v;
				if (!map.empty()){
					std::cout << date << " => " << val << " = " << (m_v * v) << std::endl;
				}
				else
					throw ("Empty data!");
			}
		}catch(const char *e){
			std::cout << e << std::endl;
		}
	}
	myFile.close();
}
