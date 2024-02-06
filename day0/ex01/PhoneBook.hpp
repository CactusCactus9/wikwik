/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:35:03 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/10 16:33:37 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <cctype>

class PhoneBook
{
	private:
		Contact	contact[8];
		int		i;
	public:
		PhoneBook();
		~PhoneBook();
		void	add_contact();
		void	show_contacts();
		void	display_contact(int n);
};

#endif




