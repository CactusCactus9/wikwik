#ifndef PresidentialPardonFORM_H
#define PresidentialPardonFORM_H
#include "AForm.hpp"
#include <fstream>
#include <exception>


class PresidentialPardonForm : public AForm{
	private:
		std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string targ);
		PresidentialPardonForm(PresidentialPardonForm &obj);
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &other);
		void	PresidentialPardon();
		void	execute(Bureaucrat const &executor);
		~PresidentialPardonForm();
		class   PresidentialException : public std::exception{
			const char  *what()const throw();
		};
};

#endif