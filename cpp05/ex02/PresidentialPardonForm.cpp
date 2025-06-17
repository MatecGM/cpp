/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:34:16 by mbico             #+#    #+#             */
/*   Updated: 2025/06/16 16:48:32 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.h"
#include "log.h"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5) {
    LOG("constructor PresidentialPardonForm empty")}

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
