/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:29:43 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/30 12:58:04 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& obj){
	std::cout << "Brain copy constructor called" << std::endl;
	*this = obj;
}

Brain&	Brain::operator=(const Brain& obj){
	if (this != &obj)
	{
		for(int i = 0; i < 100; i++)
			this->ideas[i] = obj.ideas[i];
	}
	return (*this);
}

Brain::~Brain(){
	std::cout << "Brain default destructor called" << std::endl;
}