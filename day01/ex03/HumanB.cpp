/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:59:42 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/17 14:32:39 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name){
    this->_name = name;
    this->_weapon  = NULL;
}

HumanB::~HumanB(){}


void	HumanB::setWeapon(Weapon &weaponB){
    _weapon = &weaponB;
}

void	HumanB::attack()
{
    if (this->_weapon)
	    std::cout << this->_name << " attacks with their " << this->_weapon->getType() <<std::endl;
}

