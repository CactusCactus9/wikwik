/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:59:30 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/17 14:07:58 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon (weapon){
	this->_name = name;  
}

HumanA::~HumanA()
{}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() <<std::endl;
}