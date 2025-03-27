/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:48:03 by mbico             #+#    #+#             */
/*   Updated: 2025/03/19 00:17:14 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>


//the following are UBUNTU/LINUX, and MacOS ONLY terminal color codes.
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#define RUN_TEST(testName, codeBlock)                               \
    {                                                               \
        std::cout << YELLOW  << testName << WHITE << std::endl;       \
        try {														\
            codeBlock                                             \
        } catch (const std::exception& e) {                         \
            std::cerr << RED << e.what();                          \
			std::cout << std::endl;									\
        }                                                           \
        std::cout << std::endl; \
    }

void ex00() {
    std::cout << BOLDMAGENTA << "=====EX00 :=====" << std::endl;

	RUN_TEST("test0 - orthodox canonical form", {
        Bureaucrat Didier("Didier", 42);
		Bureaucrat Default;
		Default = Didier;
		std::cout << Default << std::endl;
		Bureaucrat cpy(Didier);
		std::cout << cpy << std::endl;
    });
	
	RUN_TEST("test1 - getter", {
        Bureaucrat	Andre("Andre", 66);
		std::cout << Andre << std::endl;
    });

    RUN_TEST("test2 - incrementation/decrementation", {
        Bureaucrat Manuel("Manuel", 1);
        Manuel.decrementGrade();
        Manuel.incrementGrade();
        Manuel.incrementGrade();
    });

    RUN_TEST("test3 - grade too high", {
        Bureaucrat Jose("Jose", 0);
    });

    RUN_TEST("test4 - grade too low", {
        Bureaucrat Juan("Juan", 200);
    });

}

void	ex01() {
	std::cout << BOLDMAGENTA << "=====EX01 :=====" << std::endl;

	RUN_TEST("test0 - orthodox canonical form", {
        Form Contract("a412", 42, 50);
		Form ContractDef;
		ContractDef = Contract;
		std::cout << ContractDef << std::endl;
		Form ContractCpy(Contract);
		std::cout << ContractCpy << std::endl;
    });

	RUN_TEST("test1 : grade too high", {
		Form	ContractB("5c", 0, 12);
    });

	RUN_TEST("test2 : grade too low", {
		Form	ContractC("6d", 53, 150);
    });

	RUN_TEST("test3 : getter", {
		Form	ContracD("7e", 53, 50);
		std::cout << ContracD << std::endl;
    });
}


int	main(void)
{
	ex00();
	ex01();
}


