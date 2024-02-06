#include "Bureaucrat.hpp"

int	main(){
	try{
		Bureaucrat	a("Director", 2);
		Bureaucrat	b("Employee1", 10);
		Bureaucrat	c("Employee2", 140);
		a.incrementGrade();
		b.incrementGrade();
		c.decrementGrade();
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
	}
	catch(std::exception &e){
		std::cout << "Error caught: " << e.what() << std::endl; 
	}

}