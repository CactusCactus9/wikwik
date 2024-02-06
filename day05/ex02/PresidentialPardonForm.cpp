#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"


//--------def constructor--------//
PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential", false, 25, 5){}

//--------copy constructor--------//
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &obj): AForm("Presidential", false, 25, 5){
	*this = obj;
}

//--------copy assignment operator--------//
PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
	if (this!= &other){
		this->_target = other._target;
	}
	return (*this);
}

//--------throw exceptions--------//
const char  *PresidentialPardonForm::PresidentialException::what()const throw(){
	return ("Presidential pardon failed!");
}

//--------parameterized constructor--------//
PresidentialPardonForm::PresidentialPardonForm(std::string targ):AForm("Presidential", false, 25, 5) , _target(targ){};


//--------Others--------//
void	PresidentialPardonForm::PresidentialPardon(){
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
void	PresidentialPardonForm::execute(Bureaucrat const &executor){
	if (getIfSigned() == true && getExecutedGrade() >= executor.getGrade())
		PresidentialPardon();
	else
		throw GradeTooLowException();
}

//--------Destructor--------//
PresidentialPardonForm::~PresidentialPardonForm(){};