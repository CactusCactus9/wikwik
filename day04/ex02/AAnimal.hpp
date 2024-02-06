/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:16:08 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/30 13:11:10 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
#define AANIMAL_H
#include <string>
#include <iostream>

class AAnimal
{
protected:
	std::string _type;
public:
	AAnimal();
	AAnimal(const AAnimal& obj);
	AAnimal& operator=(const AAnimal& obj);
	const std::string getType()const;
	virtual void	makeSound()const=0;
	virtual ~AAnimal();
};
#endif