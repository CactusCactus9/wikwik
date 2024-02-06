/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:37:47 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/30 10:49:46 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal(){
	_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& obj) : Animal(obj){
	std::cout << "Dog copy constructor called" << std::endl;
	*this = obj;
}

Dog&	Dog::operator=(const Dog& obj){
	if (this != &obj)
	{
		Animal::operator=(obj);
	}
	return (*this);
}

void	Dog::makeSound()const{
	std::cout << "woof" << std::endl;
}

Dog::~Dog(){
	std::cout << "Dog default destructor called" << std::endl;
}