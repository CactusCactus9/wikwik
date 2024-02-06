/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:55:57 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/25 10:47:07 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_n = 8;

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->_num = 0;
}

Fixed::Fixed(const Fixed &obj){
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed&	Fixed::operator=(const Fixed &src){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_num = src.getRawBits();
	return (*this);
}

int	Fixed::getRawBits() const{
	std::cout << "getRawBits member function called" << std::endl;
	return (_num);
}

void	Fixed::setRawBits(int const raw){
	this->_num = raw;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
};