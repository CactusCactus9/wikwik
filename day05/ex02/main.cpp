#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"


int	main(){
	try{
		Bureaucrat				a("Director", 1);
		ShrubberyCreationForm	b("home");
		RobotomyRequestForm		c("robot");
		PresidentialPardonForm	d("Defendant");
		
		a.signForm(b);
		a.signForm(c);
		a.signForm(d);

		a.executeForm(b);
		a.executeForm(c);
		a.executeForm(c);
		a.executeForm(d);

	}
	catch(std::exception &e){
		std::cout << "Error caught: " << e.what() << std::endl; 
	}

}