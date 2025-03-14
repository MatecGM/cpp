/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:48:03 by mbico             #+#    #+#             */
/*   Updated: 2025/03/11 20:06:31 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "iostream"


int	main(void)
{
	try {
		Bureaucrat	Manuel("Manuel", 1);
		std::cout << Manuel.getName() << std::endl;
		std::cout << Manuel.getGrade() << std::endl;
		Manuel.decrementGrade();
		std::cout << Manuel.getGrade() << std::endl;
		Manuel.incrementGrade();
		std::cout << Manuel.getGrade() << std::endl;
		Manuel.incrementGrade();
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat	Jose("Jose", 0);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Bureaucrat	Juan("Juan", 200);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
