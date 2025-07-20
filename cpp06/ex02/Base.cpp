/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 07:33:32 by mateo             #+#    #+#             */
/*   Updated: 2025/07/20 08:37:28 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.h"
#include <cstdlib>
#include <iostream>

Base	*generate(void) {

	srand(time(NULL));
	int		rand = std::rand() % 3;
	Base	*ret;

	LOG(YELLOW << "rand value: " << rand);
	switch (rand) {
		case 0:
			ret = new A;
			std::cout << "generate: A() has been instantiates.\n";
			break;
		case 1:
			ret = new B;
			std::cout << "generate: B() has been instantiates.\n";
			break;
		case 2:
			ret = new C;
			std::cout << "generate: C() has been instantiates.\n";
			break;
	}
	return (ret);
}

void	identify(Base *p) {
	if (dynamic_cast<A *>(p))
		std::cout << "p: \"A\"\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "p: \"B\"\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "p: \"C\"\n";
	else
		std::cout << "p: isn't \"A\", \"B\" or \"C\"\n";
}

void	identify(Base &p) {
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "p: \"A\"\n";
	}
	catch (...) {
		try {
			(void)dynamic_cast<B &>(p);
			std::cout << "p: \"B\"\n";
		}
		catch (...) {
			try {
				(void)dynamic_cast<C &>(p);
				std::cout << "p: \"C\"\n";
			}
			catch (...) {
				std::cout << "p: isn't \"A\", \"B\" or \"C\"\n";
			}
		}
	}
}
