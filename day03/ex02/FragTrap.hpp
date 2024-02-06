/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:37:48 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/27 03:21:07 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H
#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string& name);//shallow copy
		FragTrap(FragTrap const &obj);
		FragTrap&	operator=(FragTrap const &other);
		void		attack(const std::string& target);
		void 		highFivesGuys(void);
		~FragTrap();
};

#endif