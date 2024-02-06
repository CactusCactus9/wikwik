/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:26:38 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/30 10:49:46 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("animal"){
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& obj){
	std::cout << "Animal copy constructor called" << std::endl;
	*this = obj;
}

Animal&	Animal::operator=(const Animal& obj){
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}

const std::string	Animal::getType()const{
	return (this->_type);
}

void	Animal::makeSound()const{
	std::cout << "make noise" << std::endl;
}

Animal::~Animal(){
	std::cout << "Animal default destructor called" << std::endl;
}
