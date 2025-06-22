/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:34:16 by mbico             #+#    #+#             */
/*   Updated: 2025/06/21 08:42:31 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.h"
#include "Bureaucrat.hpp"
#include "log.h"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5) {
	LOG("constructor PresidentialPardonForm empty")
	_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5) {
	LOG("constructor PresidentialPardonForm empty")
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm (const PresidentialPardonForm &src) : AForm("PresidentialPardonForm", 25, 5) {
  LOG("constructor PresidentialPardonForm copy")
  if (this != &src)
    *this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(void){
    LOG("destructor PresidentialPardonForm")}

PresidentialPardonForm &PresidentialPardonForm::operator=(
    PresidentialPardonForm const &src) {
  if (this == &src)
    return (*this);
  return (*this);
}

void	PresidentialPardonForm::executeAction() const
{
	std::cout << "Informs that " << _target << " has been pardoned by Zaphod Beeblerox" << std::endl;
}
