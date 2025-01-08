/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:02:30 by mbico             #+#    #+#             */
/*   Updated: 2025/01/08 18:58:56 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>
#include <string>
#include "Contact.hpp"
#include <iomanip>

void	Contact::set_contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
{
	first_name = fn;
	last_name = ln;
	nickname = nn;
	phone_number = pn;
	darkest_secret = ds;
}

Contact::Contact(void)
{
	set_contact("", "", "", "", "");
}

std::string	Contact::get_contact(void)
{
	std::string	str;
	std::string	info[] = {first_name, last_name, nickname};

	for (int i = 0; i < 3; i ++)
	{
		if (info[i].length() > 10)
		{
			info[i].resize(10);
			info[i][9] = '.';
		}
		std::cout.fill(' ');
		std::cout.width(10);
		std::cout << info[i] << "|";
	}
	return (str);
}

std::string	Contact::get_contact_info(void)
{
	std::string	str;
	std::string	value[] = {first_name, last_name, nickname, phone_number, darkest_secret};
	std::string	key[] = {"first name", "last name", "nickname", "phone number", "darkest secret"};

	for (int i = 0; i < 5; i ++)
	{
		std::cout << key[i] << " : "<< value[i];
		if (i != 4)
			std::cout<< std::endl;
	}
	return (str);
}
