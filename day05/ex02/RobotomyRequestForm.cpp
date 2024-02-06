#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

//--------def constructor--------//
RobotomyRequestForm::RobotomyRequestForm():AForm("Robotomy", false, 72, 45){};

//--------copy constructor--------//
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &obj): AForm("Robotomy", false, 72, 45){
	*this = obj;
};

//--------copy assignment operator--------//
RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
	if (this!= &other){
		this->_target = other._target;
	}
	return (*this);
}

//--------throw exceptions--------//
const char  *RobotomyRequestForm::RobotomyException::what()const throw(){
	return ("Robotomy failed!");
}

//--------parameterized constructor--------//
RobotomyRequestForm::RobotomyRequestForm(std::string targ):AForm("Robotomy", false, 72, 45) , _target(targ){};

//--------Others--------//
void	RobotomyRequestForm::Robotomize(){
	static int	i;
	if (i == 0)
	{
		i++;
		std::cout << "Robotomy failed!" << std::endl;
	}
	else
	{
		std::cout<< "Zzzzzzz" <<std::endl;
		std::cout << this->_target << " has been robotomized." << std::endl;
		i = 0;
	}
}
void	RobotomyRequestForm::execute(Bureaucrat const &executor){
	if (getIfSigned() == true && getExecutedGrade() >= executor.getGrade())
		Robotomize();
	else
		throw GradeTooLowException();
}

//--------Destructor--------//
RobotomyRequestForm::~RobotomyRequestForm(){};