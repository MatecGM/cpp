/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:15:15 by mbico             #+#    #+#             */
/*   Updated: 2025/01/21 16:49:04 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
{
	_name = "Default";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	_name = other._name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << _name << " copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = 10;
		_energyPoints = 10;
		_attackDamage = 0;
	}
	std::cout << _name << " copy assignment operator called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << _name << " destructor called" << std::endl;
}



ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << _name << " name constructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& targer)
{	
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints --;
		std::cout << _name << " attacks " << targer << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else	
		std::cout << "Attack impossible, " << _name << " has " << _energyPoints << " energy points and " << _hitPoints << " hit points!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		_hitPoints -= amount;
		std::cout << _name << " take damage, " << amount << " hit points lost!" << std::endl;
	}
	else
		std::cout << _name << " can't take any damage, he's dead!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints --;
		_hitPoints += amount;
		std::cout << _name << " repairs itself, it gets " << amount << " hit points back!" << std::endl; 
	}
	else
		std::cout << "Repair impossible, " << _name << " has " << _energyPoints << " energy points and " << _hitPoints << "hit points!" << std::endl;
}


