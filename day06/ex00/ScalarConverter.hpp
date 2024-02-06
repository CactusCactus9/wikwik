#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H
#include <iostream>
#include <string>

class	ScalarConverter{
	private:
	//non instanciable
		ScalarConverter();
		ScalarConverter(const ScalarConverter &obj);
		ScalarConverter	&operator=(const ScalarConverter &other);
		~ScalarConverter();
	public:
		static void	convert(std::string &str);//static method is a member 
		//function of a class that is associated with the class rather than 
		//with instances (objects) of the class. 
		//It belongs to the class itself rather than any specific instance of the class.

};
	int	pseudo_literal(std::string str);
#endif