/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:25:51 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/25 14:42:00 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_n = 8;

Fixed::Fixed() : _num(0){
}

//Comparison Operators
bool	Fixed::operator>(const Fixed& other)const{
	return (this->getRawBits() > other.getRawBits());
}
bool	Fixed::operator<(const Fixed& other)const{
	return (this->getRawBits() < other.getRawBits());
}
bool	Fixed::operator>=(const Fixed& other)const{
	return (this->getRawBits() >= other.getRawBits());
}
bool	Fixed::operator<=(const Fixed& other)const{
	return (this->getRawBits() <= other.getRawBits());
}
bool	Fixed::operator==(const Fixed& other)const{
	return (this->getRawBits() == other.getRawBits());
}
bool	Fixed::operator!=(const Fixed& other)const{
	return (this->getRawBits() != other.getRawBits());
}


//Arithmetic Operators
Fixed	Fixed::operator*(Fixed const &ref) const{
	Fixed	res(this->toFloat() * ref.toFloat());
	return (res);
}
Fixed	Fixed::operator+(Fixed const &ref) const{
	Fixed	res(this->toFloat() + ref.toFloat());
	return (res);
}
Fixed	Fixed::operator-(Fixed const &ref) const{
	Fixed	res(this->toFloat() - ref.toFloat());
	return (res);
}
Fixed	Fixed::operator/(Fixed const &ref) const{
	Fixed	res(this->toFloat() / ref.toFloat());
	return (res);
}


//Increment-Decrement Operators
Fixed	&Fixed::operator++(){
	this->_num++;
	return (*this);
}
Fixed	Fixed::operator++(int){
	Fixed	tmp(*this);
	this->_num++;
	return (tmp);
}
Fixed	&Fixed::operator--(){
	this->_num--;
	return (*this);
}
Fixed	Fixed::operator--(int){
	Fixed	tmp(*this);
	this->_num--;
	return (tmp);
}


//min-max
Fixed& Fixed::min(Fixed &ref1, Fixed &ref2){
	return (ref1 < ref2) ? ref1 : ref2;
}
const Fixed&	Fixed::min(const Fixed &ref1, const Fixed &ref2){
	return (ref1 < ref2) ? ref1 : ref2;
}
Fixed&	Fixed::max(Fixed &ref1, Fixed &ref2){
	return (ref1 > ref2) ? ref1 : ref2;
}
const Fixed&	Fixed::max(const Fixed &ref1, const Fixed &ref2){
	return (ref1 > ref2) ? ref1 : ref2;
}
Fixed::Fixed(const int n){
	this->_num = n << this->_n;
}

Fixed::Fixed(const float n){
	_num = roundf( n * (1 << _n));
}

int	Fixed::getRawBits() const{
	return (_num);
}

void	Fixed::setRawBits(int const raw){
	this->_num = raw;
}

float	Fixed::toFloat(void)const{
	return ((float)(this->getRawBits()) / (1 << this->_n));
}

int		Fixed::toInt(void) const{
	return ((this->_num >> this->_n));
}


Fixed::Fixed(const Fixed &obj)
{
	*this = obj;
}

Fixed&	Fixed::operator=(const Fixed &src){
	if (this != &src)
		this->_num = src.getRawBits();
	return (*this);
}

Fixed::~Fixed(){};

std::ostream&	operator<<(std::ostream& os, const Fixed& other){
	os << other.toFloat();
	return (os);
}




