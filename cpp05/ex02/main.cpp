/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:48:03 by mbico             #+#    #+#             */
/*   Updated: 2025/06/21 08:40:48 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include <iostream>
#include <cstdlib>

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

void ex02() {
  std::cout << BOLDMAGENTA << "================EX02 :===============" << std::endl;
	RUN_TEST("test0 - execute grade too low", {
		PresidentialPardonForm	f1;
		Bureaucrat	b1("b1", 24);

		b1.signForm(f1);
		b1.executeForm(f1);
	})
	RUN_TEST("test1 - execute form not signed", {
			PresidentialPardonForm	f1("b2");
			Bureaucrat	b1("b1", 24);

			b1.executeForm(f1);
			})
	RUN_TEST("test2 - ShrubberyCreationForm", {
			ShrubberyCreationForm	f1("presidential");
			Bureaucrat	b1("b1", 1);

			b1.signForm(f1);
			b1.executeForm(f1);
			})
	RUN_TEST("test3 - PresidentialPardonForm", {
			PresidentialPardonForm	f1("shrubbery");
			Bureaucrat	b1("b1", 1);

			b1.signForm(f1);
			b1.executeForm(f1);
			})
	RUN_TEST("test4 - RobotomyRequestForm", {
			RobotomyRequestForm	f1("robotomy");
			Bureaucrat	b1("b1", 1);

			b1.signForm(f1);
			b1.executeForm(f1);
			})
}

int main(void) {
	srand(time(0));
	ex00();
	ex02();
}
