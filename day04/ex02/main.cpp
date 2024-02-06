/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:08:24 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/30 13:18:03 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{	
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	// AAnimal	test;
	delete j;//should not create a leak
	delete i;
	
	AAnimal  *p[4];
	for (int i = 0; i < 4; i++){
		if (i < 4/2)
			p[i] = new Dog();
		else
			p[i] = new Cat();
	}
	for (int i = 0; i < 4; i++){
		p[i]->makeSound();
		delete p[i];
	}
return 0;
}
