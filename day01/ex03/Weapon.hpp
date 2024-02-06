/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:00:14 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/17 14:27:14 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>
#include <string>

class Weapon
{
private:
	std::string	_type;
public:
	Weapon(std::string const str);
	~Weapon();
	const std::string	&getType() const;
	void				setType(std::string newtype);
};

#endif