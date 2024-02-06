# ifndef BUREAUCRAT_H
# define BUREAUCRAT_H
#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;
class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat	&operator=(const Bureaucrat &other);
		std::string	getName()const;
		int			getGrade()const;
		void		incrementGrade();
		void		decrementGrade();
		~Bureaucrat();
		class GradeTooHighException : public std::exception{
		public:
			const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception{
		public:
			const char	*what() const throw();
		};
		void	signForm(AForm &f);
		void	executeForm(AForm &form);
};

std::ostream	&operator<<(std::ostream &strm, const Bureaucrat &other);
	
#endif
