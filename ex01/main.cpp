/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:14:54 by mbico             #+#    #+#             */
/*   Updated: 2025/01/07 17:30:39 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include <iomanip>

int main(int argc, char **argv)
{
	PhoneBook	test;

	test.add_contact("MateoMateo", "Bico", "mbicombico", "076982055", "je suis gay en gros");
	test.search_contact();
}
