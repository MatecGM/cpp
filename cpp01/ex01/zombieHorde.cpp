/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:16:49 by mbico             #+#    #+#             */
/*   Updated: 2025/01/10 17:44:02 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name) {
	if (N < 1)
		return (NULL);
	Zombie	*zombies = new Zombie[N];
	
	for (int i = 0; i < N; i ++) {
		zombies[i].set_name(name);
	}
	return (zombies);
}
