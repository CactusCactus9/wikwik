/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:26:38 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/30 13:13:11 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("animal"){
	std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& obj){
	std::cout << "Animal copy constructor called" << std::endl;
	*this = obj;
}

AAnimal&	AAnimal::operator=(const AAnimal& obj){
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}

const std::string	AAnimal::getType()const{
	return (this->_type);
}

void	AAnimal::makeSound()const{
	std::cout << "make noise" << std::endl;
}

AAnimal::~AAnimal(){
	std::cout << "Animal default destructor called" << std::endl;
}
