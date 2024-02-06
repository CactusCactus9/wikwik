/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:11:25 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/25 11:08:46 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H
#include <iostream>
#include <cmath>
 
class	Fixed
{
private:
	int					_num;
	static const int	_n;
public:
	Fixed();
	Fixed(const int n);
	Fixed(const float m);
	Fixed(const Fixed &obj);
	Fixed	&operator=(const Fixed& src);
	int		getRawBits(void)const;
	void	setRawBits(int const raw);
	float	toFloat(void)const;
	int		toInt(void) const;
	~Fixed();
};

std::ostream&	operator<<(std::ostream& os, const Fixed& other);

#endif
