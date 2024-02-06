#ifndef INTERN_H
#define INTERN_H
#include <string>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"



class Intern
{
public:
    Intern();
    Intern(const Intern &obj);
    AForm   *makeForm(std::string name, std::string target);
    ~Intern();
};


#endif