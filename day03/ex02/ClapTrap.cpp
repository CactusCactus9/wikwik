/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:36:17 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/30 10:49:46 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//---------Constructors---------------//
ClapTrap::ClapTrap(){
	std::cout << "Default constructor called" << std::endl;
	this->_Name = "def";
	this->_Hit = 10;
	this->_Energy = 10;
	this->_Attack = 0;
}
ClapTrap::ClapTrap(const std::string& name) : _Name(name){
	std::cout << "Parameterized constructor called" << std::endl;
	this->_Hit = 10;
	this->_Energy = 10;
	this->_Attack = 0;
}
ClapTrap::ClapTrap(ClapTrap const &obj){
	std::cout << "Copy Constructor Called" << std::endl;
	*this = obj;
}

//---------Setters---------------//
void	ClapTrap::setName(const std::string& name){ //shallow copy
	_Name = name;
}
void	ClapTrap::setHitPoints(unsigned int hit){
	_Hit = hit;
}
void	ClapTrap::setEnergyPoints(unsigned int energy){
	_Energy = energy;
}
void	ClapTrap::setAttackDamage(unsigned int attack){
	_Attack = attack;
}

//---------Getters---------------//
std::string	ClapTrap::getName()const{
	return(this->_Name);
}
unsigned int	ClapTrap::getHitPoint()const{
	return(this->_Hit);
}
unsigned int	ClapTrap::getEnergyPoint()const{
	return(this->_Energy);
}
unsigned int	ClapTrap::getAttackDamage()const{
	return(this->_Attack);
}

//---------copy assignment operator---------------//
ClapTrap&	ClapTrap::operator=(ClapTrap const &obj){
	std::cout << "Copy Assignement Called" << std::endl;
	if (this != &obj)
	{
		this->_Name = obj._Name;
		this->_Hit = obj._Hit;
		this->_Energy = obj._Energy;
		this->_Attack = obj._Attack;
	}
	return (*this);
}

//---------Public members---------------//
void	ClapTrap::attack(const std::string& target){
	if (!this->_Energy || !this->_Hit)
		return ;
	std::cout << "ClapTrap " << this->_Name << " attacks " << target << ", causing " << this->_Attack << " points of damage and lost 1 energy point" << std::endl;
	this->_Energy--;
}
void	ClapTrap::takeDamage(unsigned int amount){
	if (!this->_Energy || !this->_Hit)
		return ;
	if (this->_Hit < amount)
		this->_Hit = 0;
	else
		this->_Hit-= amount;	
	std::cout << _Name << " lost " << amount << " hit points"<< std::endl;
}
void	ClapTrap::beRepaired(unsigned int amount){
	if (!this->_Energy || !this->_Hit)
	return ;
	this->_Hit += amount;
	this->_Energy--;
	std::cout << _Name << " gained " << amount << " hit points" << " and lost 1 energy point" << std::endl;
}

//---------destructor---------------//
ClapTrap::~ClapTrap(){
	std::cout << "destructor called" << std::endl;
};
