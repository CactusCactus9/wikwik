/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:47:28 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/17 14:16:12 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class	Zombie
{
private:
	std::string	_name;
public:
	Zombie(std::string name1);
	~Zombie();
	void	announce();
};

Zombie* newZombie( std::string name);
void randomChump( std::string name);

#endif