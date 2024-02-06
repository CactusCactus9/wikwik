/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:24:17 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/18 14:04:11 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
int	main()
{
	int n = 4;
    Zombie* z;
    z = zombieHorde(n, "zombieX");
    for(int i = 0; i < n; i++)
    {
        z[i].announce();
    }
    delete[] z;
}