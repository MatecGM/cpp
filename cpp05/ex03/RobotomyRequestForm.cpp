/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:32:19 by mbico             #+#    #+#             */
/*   Updated: 2025/06/20 04:39:04 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.h"
#include "log.h"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45) {
    LOG("constructor RobotomyRequestForm empty")}

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

void	robotomyExecuteAction(Bureaucrat const & executor) {
	int randNum = rand() % 2;
	
	std::cout << "DRRRRRR DRRRRRRRR" << std::endl;
	if (randNum)
		std::cout << executor.getName() << " has been robotomized" << std::endl;
	else
		std::cout << executor.getName() << " has not been robotomized" << std::endl;
}
