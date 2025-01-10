/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:31:05 by mbico             #+#    #+#             */
/*   Updated: 2025/01/10 16:58:41 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class	Zombie{
	public:
		Zombie(std::string name);
		~Zombie();
		void	announce(void);
	private:
		std::string	name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
