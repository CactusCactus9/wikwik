/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:59:50 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/17 14:29:17 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H
#include "Weapon.hpp"

class	HumanB
{
private:
	std::string	_name;
	Weapon		*_weapon;
public:
	HumanB(std::string _name);
	~HumanB();
	void	attack();
	void	setWeapon(Weapon &weapon);
};


#endif