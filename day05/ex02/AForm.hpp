#ifndef AFORM_H
#define AFORM_H
#include <string>
#include <iostream>
// #include "Bureaucrat.hpp"


class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_execute_grade;

	public:
		AForm();
		AForm(const AForm& obj);
		AForm(const std::string name, bool sign, const int grade1, const int grade2);
		AForm	&operator=(const AForm &other);
		std::string	getTheName()const;
		bool		getIfSigned()const;
		int	getSignedGrade()const;
		int	getExecutedGrade()const;
		void	beSigned(Bureaucrat a);
		virtual void	execute(Bureaucrat const & executor)=0;
		class GradeTooHighException : public std::exception{
			public:
				const char*	what()const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				const char*	what()const throw();
		};
		virtual ~AForm();
};
std::ostream	&operator<<(std::ostream &strm, const AForm &other);
#endif