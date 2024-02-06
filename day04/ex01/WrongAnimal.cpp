/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:36:24 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/28 17:36:34 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Wrong animal"){
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj){
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = obj;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& obj){
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}

const std::string	WrongAnimal::getType()const{
	return (this->_type);
}

void	WrongAnimal::makeSound()const{
	std::cout << "hello" << std::endl;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal default destructor called" << std::endl;
}