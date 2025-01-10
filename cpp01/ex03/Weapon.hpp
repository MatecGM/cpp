/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:03:03 by mbico             #+#    #+#             */
/*   Updated: 2025/01/10 18:59:35 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class	Weapon {
	public:
		const std::string&	getType(void);
		void		setType(std::string type);
		Weapon(std::string type);
		Weapon(const Weapon& weapon);
	private:
		std::string	_type;
};

#endif
