/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:38:53 by mbico             #+#    #+#             */
/*   Updated: 2025/01/21 18:48:04 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <FragTrap.hpp>

int    main(void) {
    ScavTrap    kanel("Kanel");
    ScavTrap    suki("Suki");

    suki.takeDamage(500);
    kanel.guardGate();
	suki.takeDamage(1);

	FragTrap	adam("adam");

	adam.highFivesGuys();

    return (0);
}
