/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:07:09 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/14 14:50:56 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::~Zombie(){}

void	Zombie::announce()
{
	std::cout << this->_name << ": More zombies..." <<std::endl;
}

void    Zombie::setName(std::string name){
    this->_name = name;
}
