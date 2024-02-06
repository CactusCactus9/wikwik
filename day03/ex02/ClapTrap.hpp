/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:37:26 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/27 01:17:27 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H
#include <iostream>
#include <string>

class	ClapTrap
{
	protected:
		std::string			_Name;
		unsigned int		_Hit;
		unsigned int		_Energy;
		unsigned int		_Attack;
	public:
		ClapTrap();
		ClapTrap(const std::string &name);
		ClapTrap(ClapTrap const &obj);
		ClapTrap&			operator=(ClapTrap const &  obj);
		void 				attack(const std::string& target);
		void 				takeDamage(unsigned int amount);
		void 				beRepaired(unsigned int amount);
		void				setName(const std::string &name);
		void				setHitPoints(unsigned int hit);
		void				setEnergyPoints(unsigned int energy);
		void				setAttackDamage(unsigned int attack);
		std::string			getName()const;
		unsigned int		getHitPoint()const;
		unsigned int		getEnergyPoint()const;
		unsigned int		getAttackDamage()const;
		
		~ClapTrap();
};

#endif
