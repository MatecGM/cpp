/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:10:41 by mbico             #+#    #+#             */
/*   Updated: 2025/01/21 18:03:32 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

void	HumanA::attack(void)
{
	std::cout << _name << "attacks with their " << _weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon& weapon): _weapon(weapon)
{
	_name = name;
}
