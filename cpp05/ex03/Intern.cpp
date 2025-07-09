/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 05:33:20 by mateo             #+#    #+#             */
/*   Updated: 2025/06/22 23:43:06 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include "log.h"

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
	std::string	formList[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	int	i;
	for (i = 0; i < 3; i ++)
	{
		if (name == formList[i])
			break;
	}
	
	switch (i) {
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


