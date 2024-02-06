/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:14:10 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/30 10:49:46 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//---------Constructors---------------//

ScavTrap::ScavTrap() : ClapTrap(){
	std::cout << "Derived class default constructer called" << std::endl;
	setName("default");
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
};
ScavTrap::ScavTrap(const std::string &name){
	std::cout << "Derived class parameterized constructor" << std::endl;
	setName(name);
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}
ScavTrap::ScavTrap(ScavTrap const &obj){
	std::cout << "Derived class copy constructor called" << std::endl;
	*this = obj;
}

//---------copy assignment operator---------------//

ScavTrap&	ScavTrap::operator=(ScavTrap const &obj){
	std::cout << "derived class copy assignment operator called" <<std::endl;
	if (this != &obj)
	{
		setName(obj.getName());
		setHitPoints(obj.getHitPoint());
		setEnergyPoints(obj.getEnergyPoint());
		setAttackDamage(obj.getAttackDamage());
	}
	return (*this);
}

//---------Public members---------------//

void	ScavTrap::attack(const std::string& target){
	if (!getEnergyPoint() || !getHitPoint())
		return ;
	std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage and lost 1 energy point" << std::endl;
	setEnergyPoints(getEnergyPoint() - 1);
}
void 		ScavTrap::guardGate(){
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

//---------destructor---------------//
ScavTrap::~ScavTrap(){
		std::cout << "derived class default destructor" << std::endl;
}
