/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:17:19 by mateo             #+#    #+#             */
/*   Updated: 2025/09/26 11:18:01 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.h"
#include <vector>
#include <deque>

int	main(void) {
	std::deque<int>	d;
	for (int i = 0; i < 6; i++)
		d.push_back(i);
	try {
		std::cout << *easyfind(d, 2) << std::endl;
		std::cout << *easyfind(d, 10) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::vector<int>	v;
	for (int i = 0; i < 6; i++)
		v.push_back(i);
	try {
		std::cout << *easyfind(v, 3) << std::endl;
		std::cout << *easyfind(v, 6) << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
