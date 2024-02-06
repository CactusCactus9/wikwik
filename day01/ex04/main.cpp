/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:28:39 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/18 10:03:09 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "files.hpp"

int	main(int ac, char **av)
{
	
	if (ac == 4)
	{
		std::string	file = av[1];
		std::string	s1 = av[2];
		std::string	s2 = av[3];
		
		
		replace_file(file, s1, s2);
	}
	else
		std::cout << "check the arguments" << std::endl;
}