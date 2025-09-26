/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:20:40 by mateo             #+#    #+#             */
/*   Updated: 2025/09/26 11:21:39 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.h"
#include <iostream>

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	try {
		std::cout << sp.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	try {
		sp.addNumber(12);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	Span	sp1 = Span(20000);
	Span	sp2 = Span(2);
	std::vector<int>	v;
	for (int i = 0; i < 19500 * 2; i+= 2)
		v.push_back(i);
	sp1.addNumbers(v.begin(), v.end());
	try {
		sp2.addNumbers(v.begin(), v.end());
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << sp1.shortestSpan() << std::endl;
	std::cout << sp1.longestSpan() << std::endl;
	return 0;
}
