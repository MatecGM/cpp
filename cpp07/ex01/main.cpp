/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 07:28:55 by mateo             #+#    #+#             */
/*   Updated: 2025/09/24 17:59:51 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.h"

#define RED "\033[31m"                /* Red */
#define WHITE "\033[37m"              /* White */
#define BLUE "\033[34m"              /* Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */

std::string	code_format(std::string cb)
{
	int	i;

	cb[1] = '\n';
	i = cb.find(';', 0);
	while ((size_t)i != std::string::npos)
	{
		if (cb[i + 1])
			cb[i + 1] = '\n';
		i = cb.find(';', i + 1);
	}
	return cb;
}

#define RUN_TEST(testName, codeBlock)													\
  {																						\
    std::cout << std::endl << BOLDMAGENTA << "________" << testName << "________" << WHITE << std::endl;  \
    try {																				\
      std::cout << BLUE << code_format(#codeBlock) << WHITE << std::endl;               \
      codeBlock																			\
    } catch (const std::exception &e) {													\
      std::cerr << RED << e.what() << WHITE << std::endl;                               \
    }																					\
  }

int	main() {
	char	charArr[5] = {'a', 'b', 'c', 'd', 'e'};
	RUN_TEST("#1 - String test", {
		for (int i = 0; i < 5; i ++)
			std::cout << (int)charArr[i] << " ";
		std::cout << std::endl;
		iter(charArr, 5, printAddOne<char>);
		std::cout << std::endl;
	});

	int	nbArr[5] = {1, 2, 3, 4, 5};
	RUN_TEST("#2 - Number test", {
		for (int i = 0; i < 5; i++)
			std::cout << nbArr[i] << " ";
		std::cout << "\n";
		iter(nbArr, 5, printAddOne<int>);
		std::cout << std::endl;
	});
	return (0);
}
