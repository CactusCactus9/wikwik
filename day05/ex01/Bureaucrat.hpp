/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:50:28 by abelkace          #+#    #+#             */
/*   Updated: 2024/01/18 15:31:04 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUREAUCRAT_H
# define BUREAUCRAT_H
#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;
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
		void	signForm(Form &f);
};

std::ostream	&operator<<(std::ostream &strm, const Bureaucrat &other);
	
#endif
