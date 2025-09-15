/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:34:42 by mateo             #+#    #+#             */
/*   Updated: 2025/07/21 14:04:09 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

bool	isCharOverflow(const char *str);
bool	isIntOverflow(const char *str);
bool	isFloatOverflow(const char *str);
bool	isDoubleOverflow(const char *str);

template <typename T>
void	printConvert(T nb, const char *str) {
	if (isCharOverflow(str)) {
		if (!(nb >= 32 && nb < 127))
			std::cout << "char: Non displayable\n";
		else
			std::cout << "char: '" << static_cast<char>(nb) << "'\n";
	}
	else
		std::cout << "char: impossible\n";
	if (isIntOverflow(str))
		std::cout << "int: " << static_cast<int>(nb) << "\n";
	else
		std::cout << "int: impossible\n";
	if (isFloatOverflow(str)) {
		std::cout << "float: " << static_cast<float>(nb);
		if (static_cast<float>(nb) == static_cast<int>(nb) && nb < 1000000 && nb > -1000000)
			std::cout << ".0";
		std::cout << "f\n";
	}
	else
		std::cout << "float: impossible\n";
	if (isDoubleOverflow(str))
	{
		std::cout << "double: " << static_cast<double>(nb);
		if (static_cast<double>(nb) == static_cast<int>(nb) && nb < 1000000 & nb > -1000000)
			std::cout << ".0";
		std::cout << std::endl;
	}
	else
		std::cout << "double: impossible" << std::endl;
}

enum	e_type {
	ERROR = 0,
	NANF,
	NINF,
	PINF,
	INT,
	CHAR,
	FLOAT,
	DOUBLE,
};

class ScalarConverter {
	public:
		static void	convert(const std::string &str);
	private:
		ScalarConverter(const ScalarConverter &ref);
		ScalarConverter(void);
		~ScalarConverter(void);

		ScalarConverter &operator=(ScalarConverter const &src);
};


