/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:35:33 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/30 13:14:14 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H
#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal{
private:
	Brain	*_braindog;
public:
	Dog();
	Dog(const Dog& obj);
	Dog&				operator=(const Dog& obj);
	void				makeSound()const;
	~Dog();
};
#endif