/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:27:48 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/10 14:28:42 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H
#include <string>
#include <iostream>

class Contact
{
	private:
		std::string			phone_number;
		std::string			first_name;
		std::string			last_name;
		std::string			nickname;
		std::string			darkest_secret;
	public:
		void		setContact(std::string f_name, std::string l_name, std::string n_name, std::string p_number, std::string d_secret);
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickName();
		std::string	getPhoneNumber();
		std::string	getSecret();
};	

#endif