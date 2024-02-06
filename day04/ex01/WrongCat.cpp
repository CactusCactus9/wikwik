/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:38:01 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/28 17:38:07 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	_type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj) : WrongAnimal(obj){
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = obj;
}

WrongCat&	WrongCat::operator=(const WrongCat& obj){
	if (this != &obj)
	{
		WrongAnimal::operator=(obj);
	}
	return (*this);
}

std::string	WrongCat::getType()const{
	return (this->_type);
}

void	WrongCat::makeSound()const{
	std::cout << "meow" << std::endl;
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat default destructor called" << std::endl;
}