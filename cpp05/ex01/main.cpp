/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:48:03 by mbico             #+#    #+#             */
/*   Updated: 2025/06/16 18:37:18 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

// the following are UBUNTU/LINUX, and MacOS ONLY terminal color codes.
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

void ex00() {
  std::cout << BOLDMAGENTA << "================EX00 :===============" << std::endl;

  RUN_TEST("test0 - orthodox canonical form", {
    Bureaucrat didier("Didier", 42);
    Bureaucrat dflt;
    dflt = didier;
    std::cout << dflt << std::endl;
    Bureaucrat cpy(didier);
    std::cout << cpy << std::endl;
	});

  RUN_TEST("test1 - getter", {
    Bureaucrat andre("Andre", 66);
    std::cout << andre << std::endl;
	});

  RUN_TEST("test2 - incrementation/decrementation", {
    Bureaucrat manuel("Manuel", 1);
    manuel.decrementGrade();
    manuel.incrementGrade();
    manuel.incrementGrade();
	});

  RUN_TEST("test3 - grade too high", {
	Bureaucrat jose("Jose", 0);
	});

  RUN_TEST("test4 - grade too low", {
	Bureaucrat juan("Juan", 200);
	});
}

void ex01() {
  std::cout << BOLDMAGENTA << "================EX01 :===============" << std::endl;

  RUN_TEST("test0 - orthodox canonical form", {
    Form contract("a412", 42, 50);
    Form contractDef;
    contractDef = contract;
    std::cout << contractDef << std::endl;
    Form contractCpy(contract);
    std::cout << contractCpy << std::endl;
  });

  RUN_TEST("test1 : grade too high", {
	Form contractB("5c", 0, 12);
	});

  RUN_TEST("test2 : grade too low", { Form contractC("6d", 53, 150); });

  RUN_TEST("test3 : getter", {
    Form contractD("7e", 53, 50);
    std::cout << contractD << std::endl;
	});

  RUN_TEST("test4 : sign", {
    Bureaucrat jeff("Jeff", 42);
    Form contractE("8f", 100, 100);
    jeff.signForm(contractE);
    std::cout << contractE << std::endl;
    Form contractF("9g", 1, 1);
    jeff.signForm(contractF);
	})
}

int main(void) {
  ex00();
  ex01();
}
