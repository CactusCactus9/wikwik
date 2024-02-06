/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:55:23 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/30 11:46:24 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal(){
	_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& obj) : Animal(obj){
	std::cout << "Cat copy constructor called" << std::endl;
	*this = obj;
}

Cat&	Cat::operator=(const Cat& obj){
	if (this != &obj)
	{
		Animal::operator=(obj);
	}
	return (*this);
}

void	Cat::makeSound()const{
	std::cout << "meow" << std::endl;
}

Cat::~Cat(){
	std::cout << "Cat default destructor called" << std::endl;
}