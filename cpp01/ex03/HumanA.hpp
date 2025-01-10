/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:08:09 by mbico             #+#    #+#             */
/*   Updated: 2025/01/10 18:50:35 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class	HumanA {
	public :
		void	attack(void);
		HumanA(std::string name, Weapon& weapon);
	private :
		std::string	_name;
		Weapon&		_weapon;
};

#endif
