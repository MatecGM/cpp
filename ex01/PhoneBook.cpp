/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:09:39 by mbico             #+#    #+#             */
/*   Updated: 2025/01/08 19:02:01 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <ostream>
#include <string>

PhoneBook::PhoneBook(void)
{
	index = 0;
}

void	PhoneBook::add_contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
{
	list[index].set_contact(fn, ln, nn, pn, ds);
	index ++;
	if (index == 8)
		index = 0;
}

int	PhoneBook::search_contact(void)
{
	std::string	str;

	std::cout << "     index|first name| last name|  nickname|" << std::endl;
	for (int i = 0; i < 8; i ++)
	{
		std::cout << "         " << i << "|";
		list[i].get_contact();
		std::cout << std::endl;
	}
	std::cout << "Enter index :" << std::endl;
	std::getline(std::cin, str);
	if (std::cin.eof())
		return (1);
	if (str.length() == 1 && str[0] - '0' >= 0 && str[0] - '0' < 8)
	{
		std::cout << "index : " << str[0] << std::endl;
		list[str[0] - '0'].get_contact_info();
	}
	else
		std::cout << "bad index";
	std::cout << std::endl;
	return (0);
}
