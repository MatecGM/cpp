/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:38:53 by mbico             #+#    #+#             */
/*   Updated: 2025/01/21 16:52:54 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	ClapTrap	ct1("Sandrine");

	ct1.beRepaired(5);
	ct1.attack("Natasha");
	ct1.takeDamage(10);
	ct1.takeDamage(5);
	ct1.attack("Justine");

	std::cout << std::endl;
	ClapTrap	ct2("Thomas");

	ct2.attack("Timoté");
	ct2.attack("Timoté");
	ct2.attack("Timoté");
	ct2.attack("Timoté");
	ct2.attack("Timoté");
	ct2.attack("Timoté");
	ct2.attack("Timoté");
	ct2.attack("Timoté");
	ct2.attack("Timoté");
	ct2.attack("Timoté");
	ct2.beRepaired(50);

	std::cout << std::endl;
	ClapTrap	ct3("John");

	ct3.takeDamage(1000);
	ct3.takeDamage(10);

}
