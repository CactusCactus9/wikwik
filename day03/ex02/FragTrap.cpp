/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:11:42 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/30 10:49:46 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//---------Constructors---------------//
FragTrap::FragTrap(){
	std::cout << "Derived class default constructer called" << std::endl;
	setName("default");
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}
FragTrap::FragTrap(const std::string &name){
	std::cout << "Derived class parameterized constructor" << std::endl;
	setName(name);
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}
FragTrap::FragTrap(FragTrap const &obj){
	std::cout << "copy constructor" << std::endl;
	*this = obj;
}

//---------copy assignment operator---------------//
FragTrap&	FragTrap::operator=(FragTrap const &other){
	std::cout << "derived class copy assignment operator called" <<std::endl;
	if (this != &other)
	{
		setName(other.getName());
		setHitPoints(other.getHitPoint());
		setEnergyPoints(other.getEnergyPoint());
		setAttackDamage(other.getAttackDamage());
	}
	return (*this);
}

//---------Public members---------------//
void	FragTrap::attack(const std::string& target){
	if (!getEnergyPoint() || !getHitPoint())
		return ;
	std::cout << "FragTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage and lost 1 energy point" << std::endl;
	setEnergyPoints(getEnergyPoint() - 1);
}
void FragTrap::highFivesGuys(void){
	std::cout << "High five from FragTrap" << std::endl;
}

//---------destructor---------------//
FragTrap::~FragTrap(){
		std::cout << "derived class default destructor" << std::endl;
}