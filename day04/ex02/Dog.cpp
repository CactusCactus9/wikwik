/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:37:47 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/30 13:15:16 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal(){
	std::cout << "Dog default constructor called" << std::endl;
	_type = "Dog";
	this->_braindog = new Brain();
	
}

Dog::Dog(const Dog& obj) : AAnimal(obj){
	std::cout << "Dog copy constructor called" << std::endl;
	this->_braindog = NULL;
	*this = obj;
}

Dog&	Dog::operator=(const Dog& obj){
	if (this != &obj)
	{
		if (this->_braindog)
			delete (this->_braindog);
		this->_braindog = new Brain(*(obj._braindog));
	}
	return (*this);
}

void	Dog::makeSound()const{
	std::cout << "woof" << std::endl;
}

Dog::~Dog(){
	std::cout << "Dog default destructor called" << std::endl;
	delete _braindog;
}