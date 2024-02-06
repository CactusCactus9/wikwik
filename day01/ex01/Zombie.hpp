/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:02:11 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/14 14:50:33 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string _name;
public:
	Zombie();
	~Zombie();
	void	announce();
	void	setName(std::string name);
};
Zombie* zombieHorde( int N, std::string name );

#endif
