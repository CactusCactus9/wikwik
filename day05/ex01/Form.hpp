#ifndef FORM_H
#define FORM_H
#include "Bureaucrat.hpp"


class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_execute_grade;

	public:
		Form();
		Form(const Form& obj);
		Form(const std::string name, bool sign, const int grade1, const int grade2);
		Form	&operator=(const Form &other);
		std::string	getTheName()const;
		bool		getIfSigned()const;
		int	getSignedGrade()const;
		int	getExecutedGrade()const;
		void	beSigned(Bureaucrat a);
		class GradeTooHighException : public std::exception{
			public:
				const char*	what()const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				const char*	what()const throw();
		};
		~Form();
};
std::ostream	&operator<<(std::ostream &strm, const Form &other);
#endif
