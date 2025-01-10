/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:31:05 by mbico             #+#    #+#             */
/*   Updated: 2025/01/10 17:29:28 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class	Zombie{
	public:
		Zombie();
		~Zombie();
		void	announce(void);
		void	set_name(std::string name);
	private:
		std::string	name;
};

Zombie	*zombieHorde(int N, std::string name);
