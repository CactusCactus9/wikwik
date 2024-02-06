/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:08:24 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/30 12:55:51 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"



int main()
{
const Animal  *p[4];
	for (int i = 0; i < 4; i++){
		if (i < 2)
			p[i] = new Dog();
		else
			p[i] = new Cat();
	}
	for (int i = 0; i < 4; i++){
		p[i]->makeSound();
		delete p[i];
	}

const Animal* j = new Dog();
const Animal* i = new Cat();
delete j;//should not create a leak
delete i;
return 0;
}
