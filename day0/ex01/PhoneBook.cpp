/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:41:46 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/10 18:02:03 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	i = 0;
}
PhoneBook::~PhoneBook()
{
	
}
		
int hasTabulation(const std::string& str) {
	 for (std::string::size_type i = 0; i < str.length(); i++) {
		if (std::isspace(str[i]))
			return (1);
	}
	return (0);
}


void	PhoneBook::add_contact()
{
	std::string	f_name;
	std::string	l_name;
	std::string	n_name;
	std::string	p_number;
	std::string	d_secret;
	
	std::cout << "Enter the first name" << std::endl;
	std::getline(std::cin, f_name);
	if(!std::cin.good())exit(1);	
	while(f_name.empty() || hasTabulation(f_name) == 1)
	{
		std::cout << "Not valid" << std::endl;
		std::getline(std::cin, f_name);
		if(!std::cin.good())exit(1);	
	}
	std::cout << "Enter the last name" << std::endl;
	std::getline(std::cin, l_name);
	if(!std::cin.good())exit(1);	
	while(l_name.empty() || hasTabulation(l_name) == 1)
	{
		std::cout << "Not valid" << std::endl;
		std::getline(std::cin, l_name);
		if(!std::cin.good())exit(1);
	}
	std::cout << "Enter the nickname" << std::endl;
	std::getline(std::cin, n_name);
	if(!std::cin.good())exit(1);
	while(n_name.empty() || hasTabulation(n_name) == 1)
	{
		std::cout << "Not valid" << std::endl;
		std::getline(std::cin, n_name);
		if(!std::cin.good())exit(1);
	}
	std::cout << "Enter the phone number" << std::endl;
	std::getline(std::cin, p_number);
	if(!std::cin.good())exit(1);
	while(p_number.empty() || hasTabulation(p_number) == 1)
	{
		std::cout << "Not valid" << std::endl;
		std::getline(std::cin, p_number);
		if(!std::cin.good())exit(1);
	}
	std::cout << "Enter the darkest secret" << std::endl;
	std::getline(std::cin, d_secret);
	if(!std::cin.good())exit(1);
	while(d_secret.empty() || hasTabulation(d_secret) == 1)
	{
		std::cout << "Not valid" << std::endl;
		std::getline(std::cin, d_secret);
		if(!std::cin.good())exit(1);
	}
	contact[i % 8].setContact(f_name, l_name, n_name, p_number, d_secret);
	i++;
}
void	PhoneBook::display_contact(int n)
{
	
	{
		std::cout << std::setw(10) << "First name : " << (contact[n].getFirstName()) << std::endl;
		std::cout << std::setw(10) << "Lastname : " << (contact[n].getLastName()) << std::endl;
		std::cout << std::setw(10) << "Nickname : " << (contact[n].getNickName()) <<std::endl;
		std::cout << std::setw(10) << "Phone number : " << (contact[n].getPhoneNumber()) <<std::endl;
		std::cout << std::setw(10) << "Darkest secret : " << (contact[n].getSecret()) <<std::endl;
		
	}
}

void	PhoneBook::show_contacts()
{
	int	j;
	std::string	k;
	std::string index;
	int	n;
	
	if (i == 0)
		std::cout << "No contacts to display! Enter new contact" <<std::endl;
	else
	{
		std::cout<<std::setw(10)<< "Index" << "|";
		std::cout << std::setw(10)<<"FirstName"<< "|";
		std::cout << std::setw(10)<<"LastName"<< "|";
		std::cout << std::setw(10)<<"NickName" << "\n";
		for(j = 0; j < 8 ; j++)
		{
			if (contact[j].getFirstName().empty())
				break ;
			std::cout << std::setw(10) << j;
			std::cout << "|";
			std::cout << std::setw(10) << ((contact[j].getFirstName().length() > 9)?(contact[j].getFirstName().substr(0,9) + "."): (contact[j].getFirstName()));
			std::cout << "|";
			std::cout << std::setw(10) << ((contact[j].getLastName().length() > 9)?(contact[j].getLastName().substr(0,9) + "."): (contact[j].getLastName()));
			std::cout << "|";
			std::cout << std::setw(10) << ((contact[j].getNickName().length() > 9)?(contact[j].getNickName().substr(0,9) + "."): (contact[j].getNickName()));
			std::cout << std::endl;
		}
		std::cout << "Enter an index" << std::endl;
		getline(std::cin, index);
		if (!std::cin.good())exit(1);
		for (size_t i = 0; i < index.length(); i++)
		{
			char	c = index[i];
			if (!(std::isdigit(c)))
			{
				std::cout << "Not a digit" << std::endl;
				return;
			}
		}
		n = std::atoi(index.c_str());
		if ((n >= 0 && n < 8) && !(contact[n].getFirstName().empty()))
			display_contact(n);
		else
			std::cout << "Wrong index";
	}
}


