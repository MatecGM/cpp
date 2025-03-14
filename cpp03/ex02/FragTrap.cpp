/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:44:45 by mbico             #+#    #+#             */
/*   Updated: 2025/01/21 18:46:15 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>


FragTrap::FragTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << _name << " (FragTrap) constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
{
	_name = other._name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << _name << " (FragTrap) copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = 100;
		_energyPoints = 100;
		_attackDamage = 30;
	}
	std::cout << _name << " (FragTrap) copy assignment operator called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << _name << " (FragTrap) destructor called" << std::endl;
}



FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << _name << " (FragTrap) name constructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << _name << " (FragTrap) requesting a high five!" << std::endl;
}
