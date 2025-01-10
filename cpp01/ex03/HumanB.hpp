/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:08:09 by mbico             #+#    #+#             */
/*   Updated: 2025/01/10 18:56:41 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class	HumanB {
	public :
		void	attack(void);
		HumanB(std::string name);
		void	setWeapon(Weapon& weapon);
	private :
		std::string	_name;
		Weapon		*_weapon;
};

#endif
