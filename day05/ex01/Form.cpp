#include "Form.hpp"

//--------def constructor--------//
Form::Form():_name("default"), _signed(false), _sign_grade(1), _execute_grade(1){}

//--------copy constructor--------//
Form::Form(const Form&  obj):_name(obj._name), _signed(obj._signed),_sign_grade(obj._sign_grade), _execute_grade(obj._execute_grade){
	*this = obj; 
}

//--------copy assignment operator--------//
Form	&Form::operator=(const Form &other){
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

//--------throw exceptions--------//
const char	*Form::GradeTooHighException::what()const throw(){
	return ("grade too high!");
}
const char	*Form::GradeTooLowException::what()const throw(){
	return ("grade too low!");
}

//--------parameterized constructor--------//
Form::Form(const std::string name, bool sign, const int grade1, const int grade2): 
_name(name), _signed(sign), _sign_grade(grade1), _execute_grade(grade2){
	if (this->_sign_grade < 1 || this->_execute_grade < 1)
		throw GradeTooHighException();
	if (this->_sign_grade > 150 || this->_execute_grade > 150)
		throw GradeTooLowException();
}

//--------Getters--------//
std::string	Form::getTheName()const{
	return (this->_name);
}
bool	Form::getIfSigned()const{
	return (this->_signed);
}
int	Form::getSignedGrade()const{
	return (this->_sign_grade);
}
int	Form::getExecutedGrade()const{
	return (this->_execute_grade);
}

//--------Others--------//
void	Form::beSigned(Bureaucrat a){
	if (this->_sign_grade < a.getGrade())
		throw Form::GradeTooLowException();
	if (this->_sign_grade >= a.getGrade())
		this->_signed = true;
}

//--------Destructor--------//
Form::~Form(){};

//--------operator overload--------//
std::ostream	&operator<<(std::ostream &strm, const Form &other){
	strm << "Form, "<< other.getTheName() ;
	if (other.getIfSigned())
		strm << " is signed ";
	else
		strm << " is not signed ";
	strm << ", sign grade " << other.getSignedGrade();
	strm << ", execute grade " <<other.getExecutedGrade();
	return (strm);
}
