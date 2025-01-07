/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:02:30 by mbico             #+#    #+#             */
/*   Updated: 2025/01/07 19:00:26 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Contact.hpp"

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
	std::string	info[] = {first_name, last_name, nickname, phone_number, darkest_secret}; 
	return (str);
}
