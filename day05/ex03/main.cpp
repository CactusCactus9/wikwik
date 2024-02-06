#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"


int	main(){
	try{
		Bureaucrat	a("Director", 1);
		Intern		e;
		AForm*		Robotomy;
		AForm*		Presidential;
		AForm*		Shrubbery;
		
		Robotomy = e.makeForm("Robotomy Request", "Bender");
		if (!Robotomy){
			std::cout << "This name isn't part of the form! " << std::endl;
			return (1);
		}
		a.signForm(*Robotomy);
		a.executeForm(*Robotomy);
		a.executeForm(*Robotomy);
		free(Robotomy);
		Presidential = e.makeForm("Presidential Pardon", "Bender");
		if (!Presidential){
			std::cout << "This name isn't part of the form! " << std::endl;
			return (1);
		}
		a.signForm(*Presidential);
		a.executeForm(*Presidential);
		free(Presidential);
		Shrubbery = e.makeForm("Shrubbery Creation", "Bender");
		if (!Shrubbery){
			std::cout << "This name isn't part of the form! " << std::endl;
			return (1);
		}
		a.signForm(*Shrubbery);
		a.executeForm(*Shrubbery);
		free(Shrubbery);
		Robotomy = e.makeForm("Hello", "Bender");
		if (!Robotomy){
			std::cout << "This name isn't part of the form! " << std::endl;
			return (1);
		}
		a.signForm(*Robotomy);
		a.executeForm(*Robotomy);
		free(Robotomy);
	}
	catch(std::exception &e){
		std::cout << "Error caught: " << e.what() << std::endl; 
	}
}