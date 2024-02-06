#include "Intern.hpp"

Intern::Intern(){}


Intern::Intern(const Intern &obj){
    *this = obj;
}


AForm   *Intern::makeForm(std::string name, std::string target){
    std::string Names[] = {"Robotomy Request" ,"Presidential Pardon", "Shrubbery Creation"};
    AForm   *ptr[] = {new RobotomyRequestForm(target), new PresidentialPardonForm(target), new ShrubberyCreationForm(target)};
    for (int i = 0; i < 3; i ++)
    {
        if (name == Names[i]){
            std::cout << "Intern creates " << name << std::endl;
            for (int j = 0; j < 3; j++)
            {
                if (j != i)
                    delete ptr[j];
            }
            return (ptr[i]);
        }

    }
    delete ptr[0];
    delete ptr[1];
    delete ptr[2];
    return (NULL);
}
Intern::~Intern(){}