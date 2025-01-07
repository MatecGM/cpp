/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:09:39 by mbico             #+#    #+#             */
/*   Updated: 2025/01/07 17:27:29 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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

void	PhoneBook::search_contact(void)
{
	for (int i = 0; i < 8; i ++)
	{
		std::cout << list[i].get_contact() << std::endl;
	}
}
