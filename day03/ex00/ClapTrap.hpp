/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:15:25 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/27 03:22:29 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H
#include <iostream>
#include <string>

class	ClapTrap
{
	private:
		std::string			_Name;
		unsigned int		_Hit;
		unsigned int		_Energy;
		unsigned int		_Attack;
	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(ClapTrap const &  obj);
		ClapTrap&			operator=(ClapTrap const &  obj);
		void 				attack(const std::string& target);
		void 				takeDamage(unsigned int amount);
		void 				beRepaired(unsigned int amount);
		std::string			getName()const;
		unsigned int		getHitPoint()const;
		unsigned int		getEnergyPoint()const;
		unsigned int		getAttackDamage()const;
		~ClapTrap();
};

#endif