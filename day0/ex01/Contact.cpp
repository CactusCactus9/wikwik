/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:41:18 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/10 18:03:34 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::setContact(std::string f_name, std::string l_name, std::string n_name, std::string p_number, std::string d_secret)
	{
		first_name = f_name;
		last_name = l_name;
		nickname = n_name;
		phone_number = p_number;
		darkest_secret = d_secret;
	}

	
	std::string	Contact::getFirstName()
	{
		return first_name;
	}
	
	std::string Contact::getLastName()
	{
		return last_name;
	}
	
	std::string	Contact::getNickName()
	{
		return nickname;
	}
	
	std::string	Contact::getPhoneNumber()
	{
		return phone_number;
	}
	
	std::string	Contact::getSecret()
	{
		return darkest_secret;
	}