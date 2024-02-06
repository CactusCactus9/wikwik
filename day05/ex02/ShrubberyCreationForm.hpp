#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H
#include "AForm.hpp"
#include <fstream>
#include <exception>


class ShrubberyCreationForm : public AForm{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string targ);
		ShrubberyCreationForm(ShrubberyCreationForm &obj);
		ShrubberyCreationForm   &operator=(const ShrubberyCreationForm &other);
		void    createFile(std::string &_target);
		void	execute(Bureaucrat const &executor);
		~ShrubberyCreationForm();
		class ShrubberryException : public std::exception{
			public:
				const char  *what()const throw();
		};
};

#endif