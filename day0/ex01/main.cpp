/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:37:26 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/10 14:30:05 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	std::string line;
	PhoneBook	phone;
	

	int	i;
	i = 0;
		while (1)
		{
			std::cout << "Looking for a contact? type: SEARCH." << std::endl;
			std::cout << "To add a new contact type: ADD." << std::endl;
			std::cout << "To exit phonebook type: EXIT" <<std::endl;
			std::getline(std::cin, line);
			if (!std::cin.good())exit(1);
			if (line == "ADD")
				phone.add_contact();
			if (line == "SEARCH")
				phone.show_contacts();
			std::cout<<std::endl;
			if (line == "EXIT")
				exit(0);
		}
}