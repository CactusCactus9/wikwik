#include "AForm.hpp"
#include "Bureaucrat.hpp"

//--------def constructor--------//
AForm::AForm():_name(""), _signed(false), _sign_grade(0), _execute_grade(0){}//initialize the const 

//--------copy constructor--------//
AForm::AForm(const AForm&  obj):_name(""), _signed(false),_sign_grade(0), _execute_grade(0){
	*this = obj; 
}

//--------copy assignment operator--------//
AForm	&AForm::operator=(const AForm &other){
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

//--------throw exceptions--------//
const char	*AForm::GradeTooHighException::what()const throw(){
	return ("grade too high!");
}
const char	*AForm::GradeTooLowException::what()const throw(){
	return ("grade too low!");
}

//--------parameterized constructor--------//
AForm::AForm(const std::string name, bool sign, const int grade1, const int grade2): 
_name(name), _signed(sign), _sign_grade(grade1), _execute_grade(grade2){
	if (this->_sign_grade < 1 || this->_execute_grade < 1)
		throw GradeTooHighException();
	if (this->_sign_grade > 150 || this->_execute_grade > 150)
		throw GradeTooLowException();
}

//--------Getters--------//
std::string	AForm::getTheName()const{
	return (this->_name);
}
bool	AForm::getIfSigned()const{
	return (this->_signed);
}
int	AForm::getSignedGrade()const{
	return (this->_sign_grade);
}
int	AForm::getExecutedGrade()const{
	return (this->_execute_grade);
}

//--------Others--------//
void	AForm::beSigned(Bureaucrat a){
	if (this->_sign_grade < a.getGrade())
		throw AForm::GradeTooLowException();
	if (this->_sign_grade >= a.getGrade())
	{
		this->_signed = true;
	}
}

//--------Destructor--------//
AForm::~AForm(){};

//--------operator overload--------//
std::ostream	&operator<<(std::ostream &strm, const AForm &other){
	strm << "Form, "<< other.getTheName() ;
	if (other.getIfSigned())
		strm << " is signed ";
	else
		strm << " is not signed ";
	strm << ", sign grade " << other.getSignedGrade();
	strm << ", execute grade " <<other.getExecutedGrade();
	return (strm);
}
