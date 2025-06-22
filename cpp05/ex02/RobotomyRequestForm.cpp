/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:32:19 by mbico             #+#    #+#             */
/*   Updated: 2025/06/21 08:42:14 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.h"
#include "log.h"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45) {
    LOG("constructor RobotomyRequestForm empty")
	_target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45) {
    LOG("constructor RobotomyRequestForm empty")
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm("RobotomyRequestForm", 72, 45) {
  LOG("constructor RobotomyRequestForm copy")
  if (this != &src)
    *this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(void){
    LOG("destructor RobotomyRequestForm")}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    RobotomyRequestForm const &src) {
  if (this == &src)
    return (*this);
  return (*this);
}

void	RobotomyRequestForm::executeAction() const {
	int randNum = rand() % 2;
	
	std::cout << "DRRRRRR DRRRRRRRR" << std::endl;
	if (randNum)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << _target << " has not been robotomized" << std::endl;
}
