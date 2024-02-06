/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 03:04:31 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/27 03:19:42 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main()
{
	FragTrap	a("soldier");
	FragTrap	b(a);
	a.attack("citizen");
	a.beRepaired(8);
	b.takeDamage(0);
	a.highFivesGuys();
}