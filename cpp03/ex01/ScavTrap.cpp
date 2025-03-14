/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:44:45 by mbico             #+#    #+#             */
/*   Updated: 2025/01/21 18:15:32 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>


ScavTrap::ScavTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << _name << " (ScavTrap) constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
	_name = other._name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << _name << " (ScavTrap) copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = 100;
		_energyPoints = 50;
		_attackDamage = 20;
	}
	std::cout << _name << " (ScavTrap) copy assignment operator called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << _name << " (ScavTrap) destructor called" << std::endl;
}



ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << _name << " (ScavTrap) name constructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& targer)
{	
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints --;
		std::cout << _name << " (ScavTrap) attacks " << targer << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else	
		std::cout << "Attack impossible, " << _name << " (ScavTrap) has " << _energyPoints << " energy points and " << _hitPoints << " hit points!" << std::endl;
}
		
void	ScavTrap::guardGate()
{
	std::cout << _name << " (ScavTrap) is now in Gate keeper mode!" << std::endl;
}
