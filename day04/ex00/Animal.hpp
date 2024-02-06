/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:16:08 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/30 08:21:58 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
#include <iostream>

class Animal
{
protected:
	std::string _type;
public:
	Animal();
	Animal(const Animal& obj);
	Animal& operator=(const Animal& obj);
	const std::string getType()const;
	virtual void	makeSound()const;
	virtual ~Animal();
};
#endif

//virtual destructor frees memory space. virtual keywword calls base{2} and 
//drived{1} classes destructors at run time 
