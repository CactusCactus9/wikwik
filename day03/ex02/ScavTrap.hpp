/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 01:06:32 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/27 02:46:25 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap{
	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(ScavTrap const &obj);
		ScavTrap&   operator=(ScavTrap const &obj);
		void		attack(const std::string& target);
		void 		guardGate();
		~ScavTrap();	
};
#endif
