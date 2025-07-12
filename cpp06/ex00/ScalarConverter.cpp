/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:34:46 by mateo             #+#    #+#             */
/*   Updated: 2025/07/12 22:55:47 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"
#include "log.h"
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cerrno>
#include <iostream>

ScalarConverter::ScalarConverter(void) {
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
	if (this != &src)
	*this = src;
}

ScalarConverter::~ScalarConverter(void) {
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src) {
	if (this == &src)
		return (*this);
	return (*this);
}

bool	isInt(const std::string str) {
	int	i = 0;

	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9' || !isIntOverflow(str.c_str()))
			return (false);
		i++;
	}
	return (true);
}

bool	isChar(const std::string str)
{
	if (str.length() == 1 && str[0] >= 32 && str[0] <= 126 && isCharOverflow(str.c_str()))
		return (true);
	return (false);
}

bool	isFloat(const std::string str)
{
	int		dot = 0;
	int		f = 0;
	int		i = 0;

	if (str[i] == '-')
		i ++;
	while (str[i])
	{
		if (str[i] == '.')
			dot ++;
		else if (str[i] == 'f')
			f ++;
		else if (str[i] < '0' || str[i] > '9')
			return (false);
		i ++;
	}
	if (dot == 1 && f == 1 && str[i - 1] == 'f' && isFloatOverflow(str.c_str()))
		return (true);
	return (false);
}

bool	isDouble(const std::string str)
{
	int	dot = 0;
	int	i = 0;

	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
			dot ++;
		else if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	if (dot == 1 && isDoubleOverflow(str.c_str()))
		return (true);
	return (false);
}

e_type	realType(const std::string str) {
	e_type	type = ERROR;

	if (str == "nan" || str == "nanf")
		type = NANF;
	else if (str == "-inf" || str == "-inff")
		type = NINF;
	else if (str == "+inf" || str == "+inff")
		type = PINF;
	else if (isInt(str))
		type = INT;
	else if (isChar(str))
		type = CHAR;
	else if (isFloat(str))
		type = FLOAT;
	else if (isDouble(str))
		type = DOUBLE;
	return (type);
}

bool	isIntOverflow(const char *str) {
	long nb;

	nb = std::strtol(str, NULL, 10);

	if (errno == ERANGE || nb > INT_MAX  || nb < INT_MIN)
		return false;
	return true;
}

bool	isFloatOverflow(const char *str)
{
	float	nb;

	nb = std::strtof(str, NULL);
	if (nb == HUGE_VALF)
		return (false);
	return (true);
}

bool	isDoubleOverflow(const char *str)
{
	double	nb;

	nb = std::strtod(str, NULL);
	if (nb == HUGE_VAL)
		return (false);
	return (true);
}

bool	isCharOverflow(const char *str) {
	long nb;

	nb = std::strtol(str, NULL, 10);

	if (errno == ERANGE || nb > CHAR_MAX  || nb < CHAR_MIN)
		return false;
	return true;
}

void	exceptPrintConvert(std::string str)
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: " << str << "f\n";
	std::cout << "double: " << str << std::endl;
}

void	ScalarConverter::convert(const std::string &str)
{	
	switch (static_cast<int>(realType(str))) {
		case NANF:
			LOG(YELLOW << "input realType(): " << BLUE << "nan");
			exceptPrintConvert("nan");
			break;
		case NINF:
			LOG(YELLOW << "input realType(): " << BLUE << "-inf");
			exceptPrintConvert("-inf");
			break;
		case PINF:
			LOG(YELLOW << "input realType(): " << BLUE << "+inf");
			exceptPrintConvert("+inf");
			break;
		case INT:
			{
				LOG(YELLOW << "input realType(): " << BLUE << "int");
				int nb = static_cast<int>(std::strtol(str.c_str(), NULL, 10));
				printConvert<int>(nb, str.c_str());
				break;
			}
		case CHAR:
			{
				LOG(YELLOW << "input realType(): " << BLUE << "char");
				char nb = str[0];
				printConvert<char>(nb, str.c_str());
				break;
			}
		case FLOAT:
			{
				LOG(YELLOW << "input realType(): " << BLUE << "float");
				float nb = std::strtof(str.c_str(), NULL);
				printConvert<float>(nb, str.c_str());
				break;
			}
		case DOUBLE:
			{
				LOG(YELLOW << "input realType(): " << BLUE << "double");
				double nb = std::strtod(str.c_str(), NULL);
				printConvert<double>(nb, str.c_str());
				break;
			}
		default:
			LOG(RED << "Type Error: not recognized")
			std::cout << "Type is not recognized, type supported : char, int, float, double" << std::endl;
			break;
	}
}
