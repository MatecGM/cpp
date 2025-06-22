/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 05:33:20 by mateo             #+#    #+#             */
/*   Updated: 2025/06/21 09:18:33 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include "log.h"
#include <list>
#include <algorithm>

Intern::Intern(void){LOG("constructor Intern empty")}

Intern::Intern(const Intern &src) {
  LOG("constructor Intern copy")
  if (this != &src)
    *this = src;
}

Intern::~Intern(void){LOG("destructor Intern")}

Intern &Intern::operator=(Intern const &src) {
  if (this == &src)
    return (*this);
  return (*this);
}

AForm	*Intern::makeForm(std::string name, std::string target) {
	AForm	*form = NULL;
	std::list<std::string> formList;

	formList.push_back("presidential pardon");
	formList.push_back("robotomy request");
	formList.push_back("shrubbery creation");
	std::list<std::string>::iterator	it = std::find(formList.begin(), formList.end(), name);
	
	(void) target;
	switch (std::distance(formList.begin(), it)) {
        case 0:
            form = new PresidentialPardonForm(target);
            break;
        case 1:
            form = new	RobotomyRequestForm(target);
            break;
        case 2:
            form = new	ShrubberyCreationForm(target);
            break;
        default:
			throw UnknownFormException();
    }
	return form;
}

const char	*Intern::UnknownFormException::what() const throw()
{
	return("AForm::UnknownFormException");
}


