/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:35:46 by mbico             #+#    #+#             */
/*   Updated: 2025/01/10 17:05:37 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

int	main(void) {
	Zombie	z1("Mateo");
	Zombie	*z2;
	
	z1.announce();
	z2 = newZombie("Francois");
	z2->announce();
	delete	z2;
	randomChump("Remi");
	
}
