/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:02:01 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/17 23:28:11 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name)
{
    if (N <= 0)
        return (NULL);
    Zombie  *Hord = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        Hord[i].setName(name);
    }
    return (Hord);
}