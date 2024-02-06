/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:55:23 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/30 13:02:46 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(){
	std::cout << "Cat default constructor called" << std::endl;
	_type = "Cat";
	this->_braincat = new Brain();//new memory scape
}

Cat::Cat(const Cat& obj){
	std::cout << "Cat copy constructor called" << std::endl;
	this->_braincat = NULL;//garbage value
	*this = obj;////using the copy constructor of the Brain class to create a new Brain object and assigning its address to the _braincat pointer of the current object.
}

Cat&	Cat::operator=(const Cat& obj){
	if (this != &obj)
	{
		if (this->_braincat)
			delete this->_braincat;
		this->_braincat = new Brain(*(obj._braincat));//deep copy of data
	}
	return (*this);
}

void	Cat::makeSound()const{    
	std::cout << "meow" << std::endl; 
}

Cat::~Cat(){
	std::cout << "Cat default destructor called" << std::endl;
	delete _braincat;
}