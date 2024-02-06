/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:00:08 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/18 14:15:36 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"


Weapon::Weapon(std::string const str){
	_type = str;
}

Weapon::~Weapon(){}

const std::string	&Weapon::getType() const {
	return (_type);
}

void	Weapon::setType(std::string newtype){
	this->_type = newtype;
}

