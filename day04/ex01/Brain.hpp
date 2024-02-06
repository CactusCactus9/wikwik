/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:36:05 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/29 09:12:40 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H
#include <string>
#include <iostream>

class Brain
{
private:
	std::string	ideas[100];	
public:
	Brain();
	Brain(const Brain& obj);
	Brain&	operator=(const Brain& obj);
	~Brain();
};

#endif