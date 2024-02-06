/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:18:35 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/27 03:19:13 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	p;
	ScavTrap	a("hisuka");
	a.attack("kirua");
	a.beRepaired(2);
	a.takeDamage(77);
	a.guardGate();
	
}