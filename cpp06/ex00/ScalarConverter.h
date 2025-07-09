/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:34:42 by mateo             #+#    #+#             */
/*   Updated: 2025/06/29 18:45:28 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

enum	e_type {
	ERROR = 0,
	INT,
	CHAR,
	FLOAT,
	DOUBLE,
};

class ScalarConverter {
	public:
		static void	convert(const std::string &str);

		ScalarConverter(const ScalarConverter &ref);
		ScalarConverter(void);
		~ScalarConverter(void);

		ScalarConverter &operator=(ScalarConverter const &src);
};


