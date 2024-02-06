/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:55:13 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/25 11:06:34 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H
#include <iostream>
 

class	Fixed
{
private:
	int					_num;
	static const int	_n;
public:
	Fixed();
	Fixed(const Fixed &obj); 
	Fixed &operator = (const Fixed& src);
	int	getRawBits(void)const;
	void	setRawBits(int const raw);
	~Fixed();
};

#endif
