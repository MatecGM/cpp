/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:34:46 by mateo             #+#    #+#             */
/*   Updated: 2025/06/29 18:58:16 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"
#include "log.h"

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
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

bool	isChar(const std::string str)
{
	if (str.length() == 1 && str[0] >= 32 && str[0] <= 126)
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
	if (dot == 1 && f == 1 && str[i - 1] == 'f')
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
	if (dot == 1)
		return (true);
	return (false);
}

e_type	realType(const std::string str) {
	e_type	type = ERROR;

	if (isInt(str))
		type = INT;
	else if (isChar(str))
		type = CHAR;
	else if (isFloat(str))
		type = FLOAT;
	else if (isDouble(str))
		type = DOUBLE;
	LOG(YELLOW << "input realType(): " << BLUE << type);
	return (type);
}

void	ScalarConverter::convert(const std::string &str)
{
	(void)realType(str);
}
