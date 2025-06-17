/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:26:49 by mbico             #+#    #+#             */
/*   Updated: 2025/06/16 16:45:33 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.h"
#include "log.h"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137) {
    LOG("constructor ShrubberyCreationForm empty")
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm("ShrubberyCreationForm", 145, 137) {
  LOG("constructor ShrubberyCreationForm copy")
  if (this != &src)
    *this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){
    LOG("destructor ShrubberyCreationForm")}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src) {
  if (this == &src)
    return (*this);
  return (*this);
}
