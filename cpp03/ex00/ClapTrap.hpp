/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:55:51 by mbico             #+#    #+#             */
/*   Updated: 2025/01/16 17:25:24 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class	ClapTrap {
	public:
		ClapTrap();
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();

		ClapTrap(std::string name);
		void	attack(const std::string& targer);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	private:
		std::string	_name;
		int			_hitPoints = 10;
		int			_energyPoints = 10;
		int			_attackDamage = 0;

};
