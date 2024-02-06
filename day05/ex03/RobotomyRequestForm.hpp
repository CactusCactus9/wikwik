#ifndef ROBOTOMY_H
#define ROBOTOMY_H
#include "AForm.hpp"
#include <fstream>
#include <exception>


class RobotomyRequestForm : public AForm{
	private:
		std::string _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string targ);
		RobotomyRequestForm(RobotomyRequestForm &obj);
		RobotomyRequestForm   &operator=(const RobotomyRequestForm &other);
		void    Robotomize();
		void	execute(Bureaucrat const &executor);
		~RobotomyRequestForm();
		class   RobotomyException : public std::exception{
			const char  *what()const throw();
		};
};

#endif