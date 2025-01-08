/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:14:54 by mbico             #+#    #+#             */
/*   Updated: 2025/01/08 19:35:42 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include <string>
#include <cctype>

int	add(PhoneBook *pb)
{
	std::string	str[5];
	std::string	info[] = {"first name", "last name", "nickname", "phone number", "darkest secret"};

	for (int i = 0; i < 5; i ++)
	{
		std::cout << "Enter your " << info[i] << " :" << std::endl;
		std::getline(std::cin, str[i]);
		if (std::cin.eof())
			return (1);
		if (str[i] == "")
			i --;
	}
	(*pb).add_contact(str[0], str[1], str[2], str[3], str[4]);	
	return (0);
}

int main(void)
{
	std::string	str;
	PhoneBook	pb;

	while (true)
	{
		std::cout << "\"ADD\", \"SEARCH\" or \"EXIT\" :" << std::endl;
		std::getline(std::cin, str);
		if (std::cin.eof())
			return (1);
		if (str == "ADD")
		{
			if (add(&pb))
				return (1);
		}
		else if (str == "SEARCH")
			pb.search_contact();
		else if (str == "EXIT")	
			return (0);
	}
}
