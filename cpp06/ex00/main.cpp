/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:05:03 by mateo             #+#    #+#             */
/*   Updated: 2025/07/11 16:22:12 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.h"
#include "log.h"

int	main(int argc, char *argv[]) {
	std::string	nbStr;

	LOG(BOLDMAGENTA << "Main start");
	if (argc != 2) {
		LOG(RED << "Incorrect input")
		std::cout << "usage: ./convert {input}" << std::endl;
		return 1;
	}
	nbStr = argv[1];
	ScalarConverter().convert(nbStr);
	
	/* std::cout << "int: " << argv[1] << "\n"; */
	/* std::cout << "float: " << argv[1] << "f\n"; */
	/* std::cout << "double: " << argv[1] << std::endl; */

}
