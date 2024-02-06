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
		PresidentialPardonForm(PresidentialPardonForm &obj);
		PresidentialPardonForm(std::string targ);
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &other);
		void	PresidentialPardon();
		void	execute(Bureaucrat const &executor);
		class   PresidentialException : public std::exception{
			public:
				const char  *what()const throw();
		};
		~PresidentialPardonForm();
};

#endif