/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:42:14 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/26 16:53:42 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap	player1("Kurapika");
	ClapTrap	player2("Spiders");
	ClapTrap	player3(player1);
	
	player1.attack(player2.getName());
	player1.beRepaired(1);
	player2.takeDamage(4);
	
	
}