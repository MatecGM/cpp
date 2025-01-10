/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:29:09 by mbico             #+#    #+#             */
/*   Updated: 2025/01/10 17:48:36 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

#define	NB_ZOMBIE 50

int	main(void)
{
	Zombie	*zombies;

	zombies = zombieHorde(NB_ZOMBIE, "Salut");
	if (!zombies)
		return (1);
	for (int i = 0; i < NB_ZOMBIE; i ++)
	{
		std::cout << i << " - ";
		zombies[i].announce();
	}
	delete[] zombies;
	return (0);
}
